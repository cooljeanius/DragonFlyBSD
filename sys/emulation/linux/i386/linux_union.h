/*
 * Union of syscall args for messaging.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $DragonFly: src/sys/emulation/linux/i386/linux_union.h,v 1.13 2006/06/07 03:02:09 dillon Exp $
 * created from DragonFly: src/sys/emulation/linux/i386/syscalls.master,v 1.9 2006/06/05 07:26:10 dillon Exp 
 */

union sysunion {
#ifdef _KERNEL /* header only applies in kernel */
	struct	lwkt_msg lmsg;
	struct	sysmsg sysmsg;
#endif
#define	nosys	linux_nosys
	struct	linux_fork_args linux_fork;
	struct	linux_open_args linux_open;
	struct	linux_waitpid_args linux_waitpid;
	struct	linux_creat_args linux_creat;
	struct	linux_link_args linux_link;
	struct	linux_unlink_args linux_unlink;
	struct	linux_execve_args linux_execve;
	struct	linux_chdir_args linux_chdir;
	struct	linux_time_args linux_time;
	struct	linux_mknod_args linux_mknod;
	struct	linux_chmod_args linux_chmod;
	struct	linux_lchown16_args linux_lchown16;
	struct	linux_stat_args linux_stat;
	struct	linux_lseek_args linux_lseek;
	struct	linux_getpid_args linux_getpid;
	struct	linux_mount_args linux_mount;
	struct	linux_oldumount_args linux_oldumount;
	struct	linux_setuid16_args linux_setuid16;
	struct	linux_getuid16_args linux_getuid16;
	struct	linux_stime_args linux_stime;
	struct	linux_ptrace_args linux_ptrace;
	struct	linux_alarm_args linux_alarm;
	struct	linux_fstat_args linux_fstat;
	struct	linux_pause_args linux_pause;
	struct	linux_utime_args linux_utime;
	struct	linux_access_args linux_access;
	struct	linux_nice_args linux_nice;
	struct	linux_kill_args linux_kill;
	struct	linux_rename_args linux_rename;
	struct	linux_mkdir_args linux_mkdir;
	struct	linux_rmdir_args linux_rmdir;
	struct	linux_pipe_args linux_pipe;
	struct	linux_times_args linux_times;
	struct	linux_brk_args linux_brk;
	struct	linux_setgid16_args linux_setgid16;
	struct	linux_getgid16_args linux_getgid16;
	struct	linux_signal_args linux_signal;
	struct	linux_geteuid16_args linux_geteuid16;
	struct	linux_getegid16_args linux_getegid16;
	struct	linux_umount_args linux_umount;
	struct	linux_ioctl_args linux_ioctl;
	struct	linux_fcntl_args linux_fcntl;
	struct	linux_olduname_args linux_olduname;
	struct	linux_ustat_args linux_ustat;
	struct	linux_sigaction_args linux_sigaction;
	struct	linux_sgetmask_args linux_sgetmask;
	struct	linux_ssetmask_args linux_ssetmask;
	struct	linux_setreuid16_args linux_setreuid16;
	struct	linux_setregid16_args linux_setregid16;
	struct	linux_sigsuspend_args linux_sigsuspend;
	struct	linux_sigpending_args linux_sigpending;
	struct	linux_setrlimit_args linux_setrlimit;
	struct	linux_old_getrlimit_args linux_old_getrlimit;
	struct	linux_getgroups16_args linux_getgroups16;
	struct	linux_setgroups16_args linux_setgroups16;
	struct	linux_old_select_args linux_old_select;
	struct	linux_symlink_args linux_symlink;
	struct	linux_readlink_args linux_readlink;
	struct	linux_uselib_args linux_uselib;
	struct	linux_reboot_args linux_reboot;
	struct	linux_readdir_args linux_readdir;
	struct	linux_mmap_args linux_mmap;
	struct	linux_truncate_args linux_truncate;
	struct	linux_ftruncate_args linux_ftruncate;
	struct	linux_statfs_args linux_statfs;
	struct	linux_fstatfs_args linux_fstatfs;
	struct	linux_ioperm_args linux_ioperm;
	struct	linux_socketcall_args linux_socketcall;
	struct	linux_syslog_args linux_syslog;
	struct	linux_setitimer_args linux_setitimer;
	struct	linux_getitimer_args linux_getitimer;
	struct	linux_newstat_args linux_newstat;
	struct	linux_newlstat_args linux_newlstat;
	struct	linux_newfstat_args linux_newfstat;
	struct	linux_uname_args linux_uname;
	struct	linux_iopl_args linux_iopl;
	struct	linux_vhangup_args linux_vhangup;
	struct	linux_vm86old_args linux_vm86old;
	struct	linux_wait4_args linux_wait4;
	struct	linux_swapoff_args linux_swapoff;
	struct	linux_sysinfo_args linux_sysinfo;
	struct	linux_ipc_args linux_ipc;
	struct	linux_sigreturn_args linux_sigreturn;
	struct	linux_clone_args linux_clone;
	struct	linux_newuname_args linux_newuname;
	struct	linux_modify_ldt_args linux_modify_ldt;
	struct	linux_adjtimex_args linux_adjtimex;
	struct	linux_sigprocmask_args linux_sigprocmask;
	struct	linux_create_module_args linux_create_module;
	struct	linux_init_module_args linux_init_module;
	struct	linux_delete_module_args linux_delete_module;
	struct	linux_get_kernel_syms_args linux_get_kernel_syms;
	struct	linux_quotactl_args linux_quotactl;
	struct	linux_bdflush_args linux_bdflush;
	struct	linux_sysfs_args linux_sysfs;
	struct	linux_personality_args linux_personality;
	struct	linux_setfsuid16_args linux_setfsuid16;
	struct	linux_setfsgid16_args linux_setfsgid16;
	struct	linux_llseek_args linux_llseek;
	struct	linux_getdents_args linux_getdents;
	struct	linux_select_args linux_select;
	struct	linux_msync_args linux_msync;
	struct	linux_getsid_args linux_getsid;
	struct	linux_fdatasync_args linux_fdatasync;
	struct	linux_sysctl_args linux_sysctl;
	struct	linux_sched_setscheduler_args linux_sched_setscheduler;
	struct	linux_sched_getscheduler_args linux_sched_getscheduler;
	struct	linux_sched_get_priority_max_args linux_sched_get_priority_max;
	struct	linux_sched_get_priority_min_args linux_sched_get_priority_min;
	struct	linux_mremap_args linux_mremap;
	struct	linux_setresuid16_args linux_setresuid16;
	struct	linux_getresuid16_args linux_getresuid16;
	struct	linux_vm86_args linux_vm86;
	struct	linux_query_module_args linux_query_module;
	struct	linux_nfsservctl_args linux_nfsservctl;
	struct	linux_setresgid16_args linux_setresgid16;
	struct	linux_getresgid16_args linux_getresgid16;
	struct	linux_prctl_args linux_prctl;
	struct	linux_rt_sigreturn_args linux_rt_sigreturn;
	struct	linux_rt_sigaction_args linux_rt_sigaction;
	struct	linux_rt_sigprocmask_args linux_rt_sigprocmask;
	struct	linux_rt_sigpending_args linux_rt_sigpending;
	struct	linux_rt_sigtimedwait_args linux_rt_sigtimedwait;
	struct	linux_rt_sigqueueinfo_args linux_rt_sigqueueinfo;
	struct	linux_rt_sigsuspend_args linux_rt_sigsuspend;
	struct	linux_pread_args linux_pread;
	struct	linux_pwrite_args linux_pwrite;
	struct	linux_chown16_args linux_chown16;
	struct	linux_getcwd_args linux_getcwd;
	struct	linux_capget_args linux_capget;
	struct	linux_capset_args linux_capset;
	struct	linux_sigaltstack_args linux_sigaltstack;
	struct	linux_sendfile_args linux_sendfile;
	struct	linux_vfork_args linux_vfork;
	struct	linux_getrlimit_args linux_getrlimit;
	struct	linux_mmap2_args linux_mmap2;
	struct	linux_truncate64_args linux_truncate64;
	struct	linux_ftruncate64_args linux_ftruncate64;
	struct	linux_stat64_args linux_stat64;
	struct	linux_lstat64_args linux_lstat64;
	struct	linux_fstat64_args linux_fstat64;
	struct	linux_lchown_args linux_lchown;
	struct	linux_getuid_args linux_getuid;
	struct	linux_getgid_args linux_getgid;
	struct	linux_getgroups_args linux_getgroups;
	struct	linux_setgroups_args linux_setgroups;
	struct	linux_chown_args linux_chown;
	struct	linux_setfsuid_args linux_setfsuid;
	struct	linux_setfsgid_args linux_setfsgid;
	struct	linux_pivot_root_args linux_pivot_root;
	struct	linux_mincore_args linux_mincore;
	struct	linux_madvise_args linux_madvise;
	struct	linux_getdents64_args linux_getdents64;
	struct	linux_fcntl64_args linux_fcntl64;
	struct	linux_setxattr_args linux_setxattr;
	struct	linux_lsetxattr_args linux_lsetxattr;
	struct	linux_fsetxattr_args linux_fsetxattr;
	struct	linux_getxattr_args linux_getxattr;
	struct	linux_lgetxattr_args linux_lgetxattr;
	struct	linux_fgetxattr_args linux_fgetxattr;
	struct	linux_listxattr_args linux_listxattr;
	struct	linux_llistxattr_args linux_llistxattr;
	struct	linux_flistxattr_args linux_flistxattr;
	struct	linux_removexattr_args linux_removexattr;
	struct	linux_lremovexattr_args linux_lremovexattr;
	struct	linux_fremovexattr_args linux_fremovexattr;
	struct	linux_fadvise64_args linux_fadvise64;
	struct	linux_exit_group_args linux_exit_group;
};
