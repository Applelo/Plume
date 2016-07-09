/*
	Plume
	Copyright (C) 2015, Applelo

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __MAIN_H__
#define __MAIN_H__

#include <psp2/apputil.h>
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/dirent.h>
#include <psp2/types.h>
#include <psp2/moduleinfo.h>
#include <psp2/rtc.h>
#include <psp2/system_param.h>
#include <psp2/touch.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <malloc.h>

#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <vita2d.h>

//Touch
#define lerp(value, from_max, to_max) ((((value*10) * (to_max*10))/(from_max*10))/10)

// Screen
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 544

// Color
#define BLACK	 RGBA8(  0,   0,   0, 255)
#define WHITE	 RGBA8(255, 255, 255, 255)
#define RED	     RGBA8(255,   0,   0, 255)
#define GREEN	 RGBA8( 0, 255,  0, 255)
#define BLUE	 RGBA8( 0, 0,  255, 255)

#endif
