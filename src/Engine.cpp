/*
 **
 ** Made by MisterAlex
 ** And also Applelo (but a little)
 **
 */

# include "../include/Engine.hh"

//Font
extern unsigned int font_size;
extern unsigned char font[];

// Image
extern unsigned char _binary_img_plume_png_start;
extern unsigned char _binary_img_grid_png_start;
extern unsigned char _binary_img_cloud_png_start;
extern unsigned char _binary_img_grass_png_start;
extern unsigned char _binary_img_block_png_start;

Engine::Engine() {
	_timer = new Timer();
	_timer->startTimer();

	_textures["plume"] = vita2d_load_PNG_buffer(&_binary_img_plume_png_start);
	_textures["cloud"] = vita2d_load_PNG_buffer(&_binary_img_cloud_png_start);
	_textures["grid"] = vita2d_load_PNG_buffer(&_binary_img_grid_png_start);
	_textures["block"] = vita2d_load_PNG_buffer(&_binary_img_block_png_start);
	_textures["grass"] = vita2d_load_PNG_buffer(&_binary_img_grass_png_start);

	_tfont = vita2d_load_font_mem(font, font_size);
	srand(time(NULL));

}

Engine::~Engine() {
	if (_tfont)
		vita2d_free_font(_tfont);
	if (_textures["plume"])
		vita2d_free_texture(_textures["plume"]);
	if (_textures["cloud"])
		vita2d_free_texture(_textures["cloud"]);
	if (_textures["grid"])
		vita2d_free_texture(_textures["grid"]);
	if (_textures["block"])
		vita2d_free_texture(_textures["block"]);
	if (_textures["grass"])
		vita2d_free_texture(_textures["grass"]);
}
