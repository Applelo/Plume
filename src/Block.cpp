/*
 **
 ** Made by Applelo
 **
 */

#include "../include/Block.hh"

Block::Block() {
	_position = 0;
	_number = 10;
	for(int _i = 0; _i < 15; _i++) {
		_xBlock[_i] = (rand() % 6) * 100 + 160;
		_yBlock[_i] = -((rand() % 8)* 68 + 10) - 36;
		_mvBlock[_i] = false;
	}

	_statut = false;
	_texture = nullptr;
}

Block::~Block() {
}

//Setter
void Block::setStatut(const bool statut) {
	_statut = statut;
}

void Block::setTexture(vita2d_texture* texture){
	_texture = texture;
}

void Block::setNumber(const int number){
	_number = number;
}

void Block::setSpeed(const float speed){
	_speed = speed;
}


//Getter
const bool Block::getStatut() const {
	return _statut;
}

const int Block::getXBlock(const int id) const {
	return _xBlock[id];
}

const int Block::getYBlock(const int id) const {
	return _yBlock[id] + _position;
}

const int Block::getNumber() const {
	return _number;
}

const float Block::getSpeed() const {
	return _speed;
}

// Display
void Block::displayBlock() {

  if (_statut)
  	_position += _speed;

  for (int _i=0; _i < _number; _i++) {
		vita2d_draw_texture(_texture, _xBlock[_i], _yBlock[_i] + _position);
		if (_yBlock[_i] + _position > 544) {
			_xBlock[_i] = (rand() % 6) * 100 + 160;
			_yBlock[_i] = -((rand() % 8) * 68 + 10) - _position - 36;
		}
	}
}
