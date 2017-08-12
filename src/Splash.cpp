/*
 **
 ** Made by Applelo
 **
 */

#include "../include/Splash.hh"

Splash::Splash() {
	_alpha = 255;
	_finish = false;
	_texture = nullptr;
	_timer = new Timer();
	_timer->startTimer();
	_timer->pauseTimer();
	_duration = 6;
}

Splash::Splash(vita2d_texture* texture) {
	_alpha = 255;
	_finish = false;
	_texture = texture;
	_timer = new Timer();
	_timer->startTimer();
	_timer->pauseTimer();
	_duration = 6;
}

Splash::Splash(vita2d_texture* texture, int duration) {
	_alpha = 255;
	_finish = false;
	_texture = texture;
	_timer = new Timer();
	_timer->startTimer();
	_timer->pauseTimer();
	_duration = duration;
}

Splash::~Splash() {
}

//Setter
void Splash::setTexture(vita2d_texture* texture){
	_texture = texture;
}

void Splash::setDuration(int duration){
	_duration = duration;
}

//Getter
const bool Splash::getFinish() const {
	return _finish;
}

// Display
void Splash::displaySplash() {
	if (_finish == false)
		_timer->resumeTimer();

	if (_timer->getTime() * 0.001 >= _duration)
		_finish = true;

	if ((_timer->getTime() * 0.001 > 0) && (_timer->getTime() * 0.001 < (_duration / 3)) && (_alpha > 0))//Splash appear
		_alpha -= 3;
	//Splash no move
	else if ((_timer->getTime() * 0.001 > (_duration / 3 * 2)) && (_timer->getTime() * 0.001 < _duration) && (_alpha < 255))//Splash disappear
		_alpha += 3;

	if (_texture)
		vita2d_draw_texture(_texture, 0, 0);//splash

	vita2d_draw_rectangle(0, 0, SCREEN_L, SCREEN_H, RGBA8(0, 0, 0, (int)_alpha));//masque
}

void Splash::resetSplash() {
	_alpha = 255;
	_finish = false;
	_timer->resetTimer();
	_timer->pauseTimer();
}
