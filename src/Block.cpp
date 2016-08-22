/*
 **
 ** Made by Applelo
 **
 */

#include "../include/Block.hh"

Block::Block() {
	_position = 0;

	for(int _i = 0; _i < 15; ++_i) {
		_xBlock[_i] = (rand()%6)*100+160;
		_yBlock[_i] = -((rand()%8)*68+10);
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


//Getter
const bool Block::getStatut() const {
	return _statut;
}

const int Block::getXBlock(const int id) const {
	return _xBlock[id];
}

const int Block::getYBlock(const int id) const {
	return _yBlock[id];
}

// Display
void Block::displayBlock() {

  if (_statut)
  	_position=+1;

  for (int _i=0; _i<15;_i++) {
		vita2d_draw_texture(_texture,_xBlock[_i],_yBlock[_i]+_position);
		if (_yBlock[_i]+_position>544) {
			_xBlock[_i] = (rand()%6)*100+160;
			_yBlock[_i] = -((rand()%8)*68+10)-_position;
		}
	}
}