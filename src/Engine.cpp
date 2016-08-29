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
extern unsigned char _binary_img_pause_png_start;

Engine::Engine() {
	_timer = new Timer();
	_timer->startTimer();

	_textures["plume"] = vita2d_load_PNG_buffer(&_binary_img_plume_png_start);
	_textures["cloud"] = vita2d_load_PNG_buffer(&_binary_img_cloud_png_start);
	_textures["grid"] = vita2d_load_PNG_buffer(&_binary_img_grid_png_start);
	_textures["block"] = vita2d_load_PNG_buffer(&_binary_img_block_png_start);
	_textures["grass"] = vita2d_load_PNG_buffer(&_binary_img_grass_png_start);
	_textures["pause"] = vita2d_load_PNG_buffer(&_binary_img_pause_png_start);
	_xTouch = 0;
	_plume = new Plume();
	_plume->setTexture(_textures["plume"]);
	_grid = new Grid();
	_grid->setTexture(_textures["grid"]);
	_grass = new Grass();
	_grass->setTexture(_textures["grass"]);
	_cloud = new Cloud();
	_cloud->setTexture(_textures["cloud"]);
	_block = new Block();
	_block->setTexture(_textures["block"]);
	
	_tfont = vita2d_load_font_mem(font, font_size);
	
	//button
	_buttonPause = new Buttons(_textures["pause"], 890, 10, 60, 60);
	

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
	if (_textures["pause"])
		vita2d_free_texture(_textures["pause"]);
}

void Engine::displayWorld() {
	_cloud->displayCloud();
	_grid->displayGrid();
	_plume->displayPlume();
	_grass->displayGrass();
	_block->displayBlock();
	vita2d_font_draw_textf(_tfont, 10, 10,WHITE, 20,"Time : %4f",_timer->getTime()*0.001);
			
}

void Engine::control() {
	sceTouchPeek(SCE_TOUCH_PORT_FRONT, &_touch, 1);
	sceCtrlPeekBufferPositive( 0, &_pad, 1);

//Right or left
	_xTouch = lerp(_touch.report[0].x, 1919, 960);
	if (_xTouch<480)
		_plume->setX(_plume->getX()-4);
	else
		_plume->setX(_plume->getX()+4);

//Statut
	if (_plume->getY()>=420) {
		_plume->setStatut(Statut::START);
	}
	else {
		if (_xTouch<480)
			_plume->setStatut(Statut::LEFT);
		else
			_plume->setStatut(Statut::RIGHT);
	}

	if (_plume->getY()>=200)
		_plume->setY(_plume->getY()-1);

	//Limite personnage
	if (_plume->getX()<150)
		_plume->setX(150);

	if (_plume->getX()>770)
		_plume->setX(770);
	_buttonPause->displayButton();

}

void Engine::check() {
	if (_grid->getStatut() == false) {
		_grass->setStatut(false);
		_cloud->setStatut(true);
		_grid->setStatut(true);
	}
	if (_block->getStatut() == false)
		_block->setStatut(true);
	
}