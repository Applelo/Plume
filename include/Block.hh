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
	bool _mvBlock[15];
	float _positionBlock[15];
	int _position;
	int _number;
	float _speed;
	float _speedMv;
	bool _statut;
	vita2d_texture* _texture;

public:
	Block();
	virtual ~Block();

	//Setter
	void setTexture(vita2d_texture* texture);
	void setStatut(const bool statut);
	void setNumber(const int number);
	void setSpeed(const float speed);
	void setMvBlock(const int id, const bool mv);
	void setSpeedMv(const float speedMv);

	//Getter
	const bool getStatut() const;
	const int getXBlock(const int id) const;
	const int getYBlock(const int id) const;
	const int getNumber() const;
	const float getSpeed() const;
	const bool getMvBlock(const int id) const;
	const float getSpeedMv() const;

	// Display
	void displayBlock();


};

#endif /* !BLOCK_HH_ */
