#!/bin/sh

if [ ! -z "`which bsdmake`" ]; then
	bsdmake configure $*
else
	make configure $*
fi
