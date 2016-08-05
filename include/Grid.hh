/*
**
** Made by Applelo
**
*/

#ifndef GRID_HH_
# define GRID_HH_

# include "Utils.h"

class Grid {
private:
	int _y;
	int _speed;
	bool _statut;
	vita2d_texture* _texture;

public:
	Grid();
	virtual ~Grid();

	//Setter
	void setY(const int y);
	void setTexture(vita2d_texture* texture);
	void setStatut(const bool statut);
	void setSpeed(const int speed);

	//Getter
	const int getY() const;
	const bool getStatut() const;
	const int getSpeed() const;

	// Display
	void displayGrid();


};

#endif /* !GRID_HH_ */
