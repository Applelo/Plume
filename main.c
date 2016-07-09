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


#include "main.h"

// Image
extern unsigned char _binary_img_plume_png_start;
extern unsigned char _binary_img_grid_png_start;
extern unsigned char _binary_img_cloud_png_start;
extern unsigned char _binary_img_grass_png_start;
extern unsigned char _binary_img_block_png_start;
//Font
extern unsigned int font_size;
extern unsigned char font[];

int main()
{
	vita2d_init();
	vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
	vita2d_font *police = vita2d_load_font_mem(font, font_size);
	// Load the statically compiled image.png file
    vita2d_texture *plume = vita2d_load_PNG_buffer(&_binary_img_plume_png_start);
    vita2d_texture *grid = vita2d_load_PNG_buffer(&_binary_img_grid_png_start);
    vita2d_texture *cloud = vita2d_load_PNG_buffer(&_binary_img_cloud_png_start);
    vita2d_texture *grass = vita2d_load_PNG_buffer(&_binary_img_grass_png_start);
    vita2d_texture *block = vita2d_load_PNG_buffer(&_binary_img_block_png_start);

	SceCtrlData pad;
  SceTouchData touch;
	memset(&pad, 0, sizeof(pad));

	while (1) {
		sceCtrlPeekBufferPositive(0, &pad, 1);
        sceTouchPeek(SCE_TOUCH_PORT_FRONT, &touch,1);

        if (pad.buttons & SCE_CTRL_START)
            break;
	}

	vita2d_fini();
  
	vita2d_free_texture(plume);
  vita2d_free_texture(grid);
  vita2d_free_texture(cloud);
  vita2d_free_texture(grass);
  vita2d_free_texture(block);

	vita2d_free_font(police);

	sceKernelExitProcess(0);
	return 0;
}
