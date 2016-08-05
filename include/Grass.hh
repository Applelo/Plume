/*
**
** Made by Applelo
**
*/

#ifndef GRASS_HH_
# define GRASS_HH_

# include "Utils.h"

class Grass {
private:
	int _y;
	bool _statut;
	vita2d_texture* _texture;

public:
	Grass();
	virtual ~Grass();

	//Setter
	void setTexture(vita2d_texture* texture);
	void setStatut(const bool statut);

	//Getter
	const bool getStatut() const;

	// Display
	void displayGrass();


};

#endif /* !GRASS_HH_ */
