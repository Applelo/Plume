/*
 **
 ** Made by Applelo
 **
 */

#include "../include/Splash.hh"

Splash::Splash() {
	_alpha = 0;
	_statut = false;
	_texture = nullptr;
	_timer = new Timer();
	_timer->startTimer();
}

Splash::~Splash() {
}

//Setter
void Splash::setStatut(const bool statut) {
	_statut = statut;
}

void Splash::setTexture(vita2d_texture* texture){
	_texture = texture;
}


//Getter
const bool Splash::getStatut() const {
	return _statut;
}

const bool Splash::finishSplash() const {
	if (_timer->getTime() * 0.001 > 8)
		return true;
		
	return false;
}

// Display
void Splash::displaySplash() {
	if (_statut)
		_timer->resumeTimer();
	else
		_timer->resetTimer();
	
	if ((_timer->getTime() * 0.001 > 2) && (_timer->getTime() * 0.001 < 4))//Splash on
		_alpha += 0.5;
	//Splash no move (between 4 and 6 sec)
	else if ((_timer->getTime() * 0.001 > 6) && (_timer->getTime() * 0.001 < 8))//Splash bye
		_alpha -= 0.5;
	
	vita2d_draw_texture_tint(_texture, 0, 0, _alpha);//splash
}
