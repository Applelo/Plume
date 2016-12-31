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
}

Splash::~Splash() {
}

//Setter
void Splash::setTexture(vita2d_texture* texture){
	_texture = texture;
}


//Getter
const bool Splash::getFinish() const {
	return _finish;
}

// Display
void Splash::displaySplash(const int x, const int y) {

	if (_timer->getTime() * 0.001 >= 6 || (x > 0 && x < SCREEN_L && y > 0 && y < SCREEN_H))
		_finish = true;

	if ((_timer->getTime() * 0.001 > 0) && (_timer->getTime() * 0.001 < 2) && (_alpha > 0))//Splash on
		_alpha -= 3;
	//Splash no move (between 4 and 6 sec)
	else if ((_timer->getTime() * 0.001 > 4) && (_timer->getTime() * 0.001 < 6) && (_alpha < 255))//Splash bye
		_alpha += 3;

	if (_texture)
		vita2d_draw_texture(_texture, 0, 0);//splash

	vita2d_draw_rectangle(0, 0, SCREEN_L, SCREEN_H, RGBA8(0, 0, 0, (int)_alpha));//masque
}
