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
		_positionBlock[_i] = -(rand() % 61);
	}
	_speed = 1;
	_speedMv = 0.5;
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

void Block::setMvBlock(const int id, const bool mv){
	_mvBlock[id] = mv;
}

void Block::setMvSpeed(const float speedMv){
	_speedMv = speedMv;
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

const bool Block::getMvBlock(const int id) const {
	return _xBlock[id];
}

const int Block::getNumber() const {
	return _number;
}

const float Block::getSpeed() const {
	return _speed;
}

const float Block::getMvSpeed() const {
	return _speedMv;
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

		if (_mvBlock[_i]) {

			if (_positionBlock[_i] > 0 && _positionBlock[_i] < 60)
				_xBlock[_i] += _speedMv;
			else if (_positionBlock[_i] > 60 && _positionBlock[_i] < 120)
				_xBlock[_i] -= _speedMv;
			else
				_positionBlock[_i] = -(rand() % 61);

		}
		_positionBlock[_i] += (1 / _speedMv);
	}
}
