/*
**
** Made by MisterAlex
** And also Applelo (but a little)
**
*/

#ifndef ENGINE_HH_
# define ENGINE_HH_

# include <vector>
# include <map>
# include <string>


# include "Buttons.hh"
# include "Plume.hh"
# include "Timer.hh"
# include "Utils.h"


class Engine {
private:
	std::vector<Buttons*> _buttons;

	Timer* _timer;
	Plume* _plume;
	vita2d_font* _tfont;
	std::map<std::string, vita2d_texture*> _textures;
	std::string _error;
	SceTouchData _touch;
	int _xTouch;

public:
	Engine();
	virtual ~Engine();

	void displayWorld();
	void control();

};
#endif /* !ENGINE_HH_ */
