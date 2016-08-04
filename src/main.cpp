/*
**
** Made by MisterAlex
** And also Applelo (but a little)
**
*/

#include "../include/Menu.hh"

int main() {
	sceTouchSetSamplingState(SCE_TOUCH_PORT_FRONT, 1);
	int run = 1;

	vita2d_init();
	vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
	
	Menu* menu = new Menu();

	while (run) {
		vita2d_start_drawing();
		vita2d_clear_screen();
		vita2d_draw_rectangle(0,0,SCREEN_L,SCREEN_H,COLOR_SKY);

		if (menu->getMenu() == Step::MAIN)
			menu->main();
		if (menu->getMenu() == Step::GAME)
			menu->game();
		if (menu->getMenu() == Step::OPTION)
			menu->option();
		if (menu->getMenu() == Step::CREDITS)
			menu->credits();
		if (menu->getMenu() == Step::EXIT)
			run=0;

		vita2d_end_drawing();
		vita2d_swap_buffers();
	}
	vita2d_fini();

	sceKernelExitProcess(0);
	return (0);
}
