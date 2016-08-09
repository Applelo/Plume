/*
**
** Made by Applelo
**
*/

#ifndef PLUME_HH_
# define PLUME_HH_

# include "Utils.h"
# include "Timer.hh"

typedef enum Statut {
	START = 0,
	LEFT,
	RIGHT
} Statut;

class Plume {
private:
	int _x;
	int _y;
	int _speed;
	Statut _statut;
	Timer* _timer;
	vita2d_texture* _texture;

public:
	Plume();
	virtual ~Plume();

	//Setter
	void setX(const int x);
	void setY(const int y);
	void setTexture(vita2d_texture* texture);
	void setStatut(const Statut statut);
	void setSpeed(const int speed);

	//Getter
	const int getX() const;
	const int getY() const;
	const Statut getStatut() const;
	const int getSpeed() const;

	// Display
	void displayPlume();


};

#endif /* !PLUMME_HH_ */
