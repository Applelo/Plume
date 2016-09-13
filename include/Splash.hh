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
	bool _finish;
	float _alpha;
	Timer* _timer;

public:
	Splash();
	virtual ~Splash();

	//Setter
	void setTexture(vita2d_texture* texture);

	//Getter
	const bool getFinish() const;

	// Display
	void displaySplash();


};

#endif /* !SPLASH_HH_ */
