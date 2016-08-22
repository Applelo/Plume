/*
 **
 ** Made by Applelo
 **
 */

#include "../include/Cloud.hh"

Cloud::Cloud() {
	_position = 0;

	for(int _i = 0; _i < 10; ++_i) {
		_xCloud[_i] = (rand()%(SCREEN_L/80))*80;
		_yCloud[_i] = (rand()%(SCREEN_H/68))*68-60;
		_typeCloud[_i] = (rand()%2);
	}

	_statut = false;
	_texture = nullptr;
}

Cloud::~Cloud() {
}

void Cloud::setStatut(const bool statut) {
	_statut = statut;
}

void Cloud::setTexture(vita2d_texture* texture){
	_texture = texture;
}

const bool Cloud::getStatut() const {
	return _statut;
}

// Display
void Cloud::displayCloud() {

	if (_statut==true)
  	_position=_position+1;

  for (int _i=0; _i<10;_i++) {
		vita2d_draw_texture_part(_texture,_xCloud[_i],_yCloud[_i]+_position,0+(_typeCloud[_i]*66),0,66+(_typeCloud[_i]*14),48);
		if (_yCloud[_i]+_position>544) {
			_xCloud[_i] = (rand()%(SCREEN_L/80))*80;
			_yCloud[_i] = -100-_position;
			_typeCloud[_i] = (rand()%2);
		}
	}
}
