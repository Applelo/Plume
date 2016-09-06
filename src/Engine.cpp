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

	_pause = false;
	_loose = false;
	_score = 0;
	_time = 0;
	_speed = 1;

	_textures["plume"] = vita2d_load_PNG_buffer(&_binary_img_plume_png_start);
	_textures["cloud"] = vita2d_load_PNG_buffer(&_binary_img_cloud_png_start);
	_textures["grid"] = vita2d_load_PNG_buffer(&_binary_img_grid_png_start);
	_textures["block"] = vita2d_load_PNG_buffer(&_binary_img_block_png_start);
	_textures["grass"] = vita2d_load_PNG_buffer(&_binary_img_grass_png_start);
	_textures["pause"] = vita2d_load_PNG_buffer(&_binary_img_pause_png_start);
	_xTouch = 0;
	_yTouch = 0;
	_oldXTouch = 0;
	_oldYTouch = 0;
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
	if (_pause) {
		vita2d_draw_rectangle(0, 0, 960, 544, RGBA8( 217, 174, 28, 200));
		vita2d_font_draw_text(_tfont, 100, 100, WHITE, 20,"Pause");
	}
	vita2d_font_draw_textf(_tfont, 10, 10, WHITE, 20,"Time: %d\n\nScore: %d", _time, _score);

}

void Engine::control() {
	sceTouchPeek(SCE_TOUCH_PORT_FRONT, &_touch, 1);
	sceCtrlPeekBufferPositive( 0, &_pad, 1);

//Right or left
	_xTouch = lerp(_touch.report[0].x, 1919, 960);
	_yTouch = lerp(_touch.report[0].y, 1087, 544);

		if (!_pause) {
			if (_plume->getStatut() == Statut::LEFT)
				_plume->setX(_plume->getX()-4);
			else if (_plume->getStatut() == Statut::RIGHT)
				_plume->setX(_plume->getX()+4);
		}
//Statut
	if (_plume->getY() >= 420) {
		_plume->setStatut(Statut::START);
		if (_xTouch < 480)
			_plume->setX(_plume->getX()-4);
		else
			_plume->setX(_plume->getX()+4);
	}
	else {
		if (_xTouch<480 && _oldXTouch != _xTouch)
			_plume->setStatut(Statut::LEFT);
		else if (_xTouch>480 && _oldXTouch != _xTouch)
			_plume->setStatut(Statut::RIGHT);
	}

	if (_plume->getY() >= 200)
		_plume->setY(_plume->getY() - 1);
	else {
		_buttonPause->displayButton();
		if (_buttonPause->touchButton(_xTouch, _yTouch) && _touch.reportNum == 0 && _oldXTouch != _xTouch)
			_pause = (_pause) ? false : true;
	}


	//Limite personnage
	if (_plume->getX() < 150) {
		_plume->setX(150);
		_plume->setStatut(Statut::RIGHT);
	}

	if (_plume->getX() > 770) {
		_plume->setX(770);
		_plume->setStatut(Statut::LEFT);
	}

	_oldXTouch = _xTouch;
	_oldYTouch = _yTouch;
}

void Engine::check() {
	if (_pause) {
		_grass->setStatut(true);
		_cloud->setStatut(false);
		_grid->setStatut(false);
		_block->setStatut(false);
		_timer->pauseTimer();
	}
	else if (_grid->getStatut() == false && _pause == false) {
		_grass->setStatut(false);
		_cloud->setStatut(true);
		_grid->setStatut(true);
		_block->setStatut(true);
		_timer->resumeTimer();
	}
	else {
		_score = (_time/3)*_speed;
		_time = _timer->getTime()*0.001;
	}

	for (int _i = 0; _i < _block->getNumber(); _i++) {
		if (collision(_i))
		 _loose = true;
	}

	if (_time>10 && _time<15)
		_speed = 1.5;
	else if (_time>80)
		_speed = 2;


	_grid->setSpeed(_speed);
	_cloud->setSpeed(_speed);
	_block->setSpeed(_speed);

}

const bool Engine::collision(const int i) const {
	if ((_plume->getX() >= _block->getXBlock(i) + 50) || (_plume->getX() + 38 <= _block->getXBlock(i)) || (_plume->getY() >= _block->getYBlock(i) + 36)  || (_plume->getY() + 60 <= _block->getYBlock(i)))
		 return false;
	else
		return true;
}

//Getter

const int Engine::getScore() const {
	return _score;
}

const int Engine::getTime() const {
	return _time;
}

const bool Engine::getLoose() const {
	return _loose;
}
