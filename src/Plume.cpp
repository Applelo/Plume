/*
 **
 ** Made by Applelo
 **
 */

#include "../include/Plume.hh"

Plume::Plume() {
	_x = 461;
	_y = 475;
	_speed = 4;
	_statut = START;
	_pause = false;
	_time = 0;
	_timer = new Timer();
	_timer->startTimer();
	_texture = nullptr;
}

Plume::~Plume() {
}

//Setter
void Plume::setX(const int x) {
	_x = x;
}

void Plume::setY(const int y) {
	_y = y;
}

void Plume::setStatut(const Statut statut) {
	_statut = statut;
}

void Plume::setTexture(vita2d_texture* texture){
	_texture = texture;
}

void Plume::setSpeed(const int speed) {
	_speed = speed;
}

void Plume::setPause(const bool pause) {
	_pause = pause;
}


//Getter
const int Plume::getX() const{
	return _x;
}

const int Plume::getY() const{
	return _y;
}

const Statut Plume::getStatut() const {
	return _statut;
}

const int Plume::getSpeed() const{
	return _speed;
}

const bool Plume::getPause() const{
	return _pause;
}

// Display
void Plume::displayPlume() {

	if (floor(_timer->getTime() / 100) >= 3)
		_timer->resetTimer();
	
	if (_timer->isPlaying())
		_time = floor(_timer->getTime() / 100) * 38;
		
	if (_pause)
		_timer->pauseTimer();
	else
		_timer->resumeTimer();
	
	if (_statut == LEFT)
		vita2d_draw_texture_part(_texture, _x, _y, 0 + _time, 0, 38, 60); //left
  	else if (_statut == RIGHT)
		vita2d_draw_texture_part(_texture, _x, _y, 152 + _time, 0, 38, 60);//right
  	else
		vita2d_draw_texture_part(_texture, _x, _y, 304 + _time, 0, 38, 60);//start
}
