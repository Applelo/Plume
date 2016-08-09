/*
 **
 ** Made by Applelo
 **
 */

#include "../include/Grass.hh"

Grass::Grass() {
	_y = 528;
	_statut = true;
	_texture = nullptr;
}

Grass::~Grass() {
}

void Grass::setStatut(const bool statut) {
	_statut = statut;
}

void Grass::setTexture(vita2d_texture* texture){
	_texture = texture;
}

const bool Grass::getStatut() const {
	return _statut;
}

// Display
void Grass::displayGrass() {

	if (_statut==false && _y<560)
  	_y=_y+2;

  for (int _i=0; _i<=30; _i++)
		vita2d_draw_texture(_texture,0+(_i*32),_y);

}
