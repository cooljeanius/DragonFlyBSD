/*-
 * Copyright (c) 2008, 2009 Yahoo!, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The names of the authors may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: src/usr.sbin/mfiutil/mfi_flash.c,v 1.3 2010/11/19 15:39:59 jhb Exp $
 */

#include <sys/param.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mfiutil.h"

#define	FLASH_BUF_SIZE	(64 * 1024)

int fw_name_width, fw_version_width, fw_date_width, fw_time_width;

static void
scan_firmware(struct mfi_info_component *comp)
{
	int len;

	len = strlen(comp->name);
	if (fw_name_width < len)
		fw_name_width = len;
	len = strlen(comp->version);
	if (fw_version_width < len)
		fw_version_width = len;
	len = strlen(comp->build_date);
	if (fw_date_width < len)
		fw_date_width = len;
	len = strlen(comp->build_time);
	if (fw_time_width < len)
		fw_time_width = len;
}

static void
display_firmware(struct mfi_info_component *comp)
{

	printf("%-*s  %-*s  %-*s  %-*s\n", fw_name_width, comp->name,
	    fw_version_width, comp->version, fw_date_width, comp->build_date,
	    fw_time_width, comp->build_time);
}

static int
display_pending_firmware(int fd)
{
	struct mfi_ctrl_info info;
	struct mfi_info_component header;
	int error;
	u_int i;

	if (mfi_ctrl_get_info(fd, &info, NULL) < 0) {
		error = errno;
		warn("Failed to get controller info");
		return (error);
	}

	printf("mfi%d Pending Firmware Images:\n", mfi_unit);
	strcpy(header.name, "Name");
	strcpy(header.version, "Version");
	strcpy(header.build_date, "Date");
	strcpy(header.build_time, "Time");
	scan_firmware(&header);
	if (info.pending_image_component_count > 8)
		info.pending_image_component_count = 8;
	for (i = 0; i < info.pending_image_component_count; i++)
		scan_firmware(&info.pending_image_component[i]);
	display_firmware(&header);
	for (i = 0; i < info.pending_image_component_count; i++)
		display_firmware(&info.pending_image_component[i]);

	return (0);
}

static void
mbox_store_word(uint8_t *mbox, uint32_t val)
{

	mbox[0] = val & 0xff;
	mbox[1] = val >> 8 & 0xff;
	mbox[2] = val >> 16 & 0xff;
	mbox[3] = val >> 24;
}

static int
flash_adapter(int ac, char **av)
{
	struct mfi_progress dummy;
	off_t offset;
	size_t nread;
	char *buf;
	struct stat sb;
	int error, fd, flash;
	uint8_t mbox[4], status;

	if (ac != 2) {
		warnx("flash: Firmware file required");
		return (EINVAL);
	}

	flash = open(av[1], O_RDONLY);
	if (flash < 0) {
		error = errno;
		warn("flash: Failed to open %s", av[1]);
		return (error);
	}

	if (fstat(flash, &sb) < 0) {
		error = errno;
		warn("fstat(%s)", av[1]);
		return (error);
	}
	if (sb.st_size % 1024 != 0 || sb.st_size > 0x7fffffff) {
		warnx("Invalid flash file size");
		return (EINVAL);
	}

	fd = mfi_open(mfi_unit);
	if (fd < 0) {
		error = errno;
		warn("mfi_open");
		return (error);
	}

	/* First, ask the firmware to allocate space for the flash file. */
	mbox_store_word(mbox, sb.st_size);
	mfi_dcmd_command(fd, MFI_DCMD_FLASH_FW_OPEN, NULL, 0, mbox, 4, &status);
	if (status != MFI_STAT_OK) {
		warnx("Failed to alloc flash memory: %s", mfi_status(status));
		return (EIO);
	}

	/* Upload the file 64k at a time. */
	buf = malloc(FLASH_BUF_SIZE);
	if (buf == NULL) {
		warnx("malloc failed");
		return (ENOMEM);
	}
	offset = 0;
	while (sb.st_size > 0) {
		nread = read(flash, buf, FLASH_BUF_SIZE);
		if (nread <= 0 || nread % 1024 != 0) {
			warnx("Bad read from flash file");
			mfi_dcmd_command(fd, MFI_DCMD_FLASH_FW_CLOSE, NULL, 0,
			    NULL, 0, NULL);
			return (ENXIO);
		}

		mbox_store_word(mbox, offset);
		mfi_dcmd_command(fd, MFI_DCMD_FLASH_FW_DOWNLOAD, buf, nread,
		    mbox, 4, &status);
		if (status != MFI_STAT_OK) {
			warnx("Flash download failed: %s", mfi_status(status));
			mfi_dcmd_command(fd, MFI_DCMD_FLASH_FW_CLOSE, NULL, 0,
			    NULL, 0, NULL);
			return (ENXIO);
		}
		sb.st_size -= nread;
		offset += nread;
	}
	close(flash);

	/* Kick off the flash. */
	printf("WARNING: Firmware flash in progress, do not reboot machine... ");
	fflush(stdout);
	mfi_dcmd_command(fd, MFI_DCMD_FLASH_FW_FLASH, &dummy, sizeof(dummy),
	    NULL, 0, &status);
	if (status != MFI_STAT_OK) {
		printf("failed:\n\t%s\n", mfi_status(status));
		return (ENXIO);
	}
	printf("finished\n");
	error = display_pending_firmware(fd);

	close(fd);

	return (error);
}
MFI_COMMAND(top, flash, flash_adapter);