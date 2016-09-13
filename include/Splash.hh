/*
**
** Made by Applelo
**
*/

#ifndef SPLASH_HH_
# define SPLASH_HH_

# include "Utils.h"
# include "Timer.hh"

class Splash {
private:
	vita2d_texture* _texture;
	bool _statut;
	float _alpha;
	Timer* _timer;

public:
	Splash();
	virtual ~Splash();

	//Setter
	void setTexture(vita2d_texture* texture);
	void setStatut(const bool statut);

	//Getter
	const bool getStatut() const;
	const bool finishSplash() const;
	
	// Display
	void displaySplash();


};

#endif /* !SPLASH_HH_ */
