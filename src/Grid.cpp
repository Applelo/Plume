/*
 **
 ** Made by Applelo
 **
 */

#include "../include/Grid.hh"

Grid::Grid() {
	_y = 0;
	_statut = false;
	_texture = nullptr;
	_speed = 1;
}

Grid::~Grid() {
}

//Setter
void Grid::setY(const int y) {
	_y = y;
}

void Grid::setStatut(const bool statut) {
	_statut = statut;
}

void Grid::setTexture(vita2d_texture* texture){
	_texture = texture;
}

void Grid::setSpeed(const float speed) {
	_speed = speed;
}

//Getter
const int Grid::getY() const{
	return _y;
}

const bool Grid::getStatut() const {
	return _statut;
}

const float Grid::getSpeed() const{
	return _speed;
}

// Display
void Grid::displayGrid() {
	if (_statut)
  		_y += _speed;

	if (_y > 543)
		_y = 0;

  for (int _i = 0; _i <= 1; _i++)
		vita2d_draw_texture(_texture, 0, _y + ( -544 * _i));
}
