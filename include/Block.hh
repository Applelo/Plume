/*
**
** Made by Applelo
**
*/

#ifndef BLOCK_HH_
# define BLOCK_HH_

# include "Utils.h"

class Block {
private:
	float _xBlock[15];
	float _yBlock[15];
	int _position;
	bool _statut;
	vita2d_texture* _texture;

public:
	Block();
	virtual ~Block();

	//Setter
	void setTexture(vita2d_texture* texture);
	void setStatut(const bool statut);

	//Getter
	const bool getStatut() const;
	const int getXBlock(const int id) const;
	const int getYBlock(const int id) const;

	// Display
	void displayBlock();


};

#endif /* !BLOCK_HH_ */
