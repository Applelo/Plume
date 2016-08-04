/*
**
** Made by Applelo
**
*/

#ifndef PLUME_HH_
# define PLUME_HH_

# include "Utils.h"

typedef enum Statut {
	END = 0,
	LEFT,
	RIGHT
} Statut;

class Plume {
private:
	int _x;
	int _y;
	int _animation;
	Statut _statut;
	vita2d_texture* _texture;

public:
	Plume();
	virtual ~Plume();

	//Setter
	void setX(const int x);
	void setY(const int y);
	void setAnimation(const int animation);
	void setTexture(vita2d_texture* texture);
	void setStatut(const Statut statut);

	//Getter
	const int getX() const;
	const int getY() const;
	const int getAnimation() const;
	const Statut getStatut() const;

	// Display
	void displayPlume();


};

#endif /* !PLUMME_HH_ */
