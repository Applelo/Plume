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
# include "Grid.hh"
# include "Grass.hh"
# include "Cloud.hh"
# include "Block.hh"
# include "Timer.hh"
# include "Utils.h"


class Engine {
private:
	std::vector<Buttons*> _buttons;

	Timer* _timer;
	Plume* _plume;
	Grid* _grid;
	Grass* _grass;
	Cloud* _cloud;
	Block* _block;
	vita2d_font* _tfont;
	std::map<std::string, vita2d_texture*> _textures;
	std::string _error;
	SceTouchData _touch;
	SceCtrlData _pad;
	int _xTouch;

public:
	Engine();
	virtual ~Engine();

	void displayWorld();
	void control();
	void check();

};
#endif /* !ENGINE_HH_ */
