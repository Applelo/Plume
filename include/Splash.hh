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
	int _duration;

public:
	Splash();
	Splash(vita2d_texture* texture);
	Splash(vita2d_texture* texture, int duration);
	virtual ~Splash();

	//Setter
	void setTexture(vita2d_texture* texture);

	void setDuration(int duration);

	//Getter
	const bool getFinish() const;

	// Display
	void displaySplash();

	void resetSplash();


};

#endif /* !SPLASH_HH_ */
