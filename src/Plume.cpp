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
	_animation = 0;
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

void Plume::setAnimation(const int animation) {
	_animation = animation;
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


//Getter
const int Plume::getX() const{
	return _x;
}

const int Plume::getY() const{
	return _y;
}

const int Plume::getAnimation() const{
	return _animation;
}

const Statut Plume::getStatut() const {
	return _statut;
}

const int Plume::getSpeed() const{
	return _speed;
}

// Display
void Plume::displayPlume() {

  _animation++;
  if (_animation >= 30) _animation=0;

  if (_statut==LEFT) vita2d_draw_texture_part(_texture,_x,_y,0+floor(_animation/10)*38,0,38,60); //left
  else if (_statut==RIGHT) vita2d_draw_texture_part(_texture,_x,_y,152+floor(_animation/10)*38,0,38,60);//right
  else vita2d_draw_texture_part(_texture,_x,_y,304+floor(_animation/10)*38,0,38,60);//start

}
