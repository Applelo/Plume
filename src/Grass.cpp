/*
 **
 ** Made by Applelo
 **
 */

#include "../include/Grass.hh"

Grass::Grass() {
	_y = 528;
	_statut = false;
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
	else
		_y = 528;

  for (int i=0; i<=30;i++)
		vita2d_draw_texture(_texture,0+(i*32),_y);

}
