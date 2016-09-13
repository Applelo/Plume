/*
**
** Made by MisterAlex
** And also Applelo (but a little)
**
*/

#ifndef ENGINE_HH_
# define ENGINE_HH_

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
	int _yTouch;
	int _oldXTouch;
	int _oldYTouch = 0;
	bool _pause;
	bool _loose;
	int _score;
	float _speed;
	int _time;
	Buttons* _buttonPause;

public:
	Engine();
	virtual ~Engine();

	void displayWorld();
	void control();
	void check();
	const bool collision(const int i) const;


	//Getter
	const bool getLoose() const;
	const int getScore() const;
	const int getTime() const;

};
#endif /* !ENGINE_HH_ */
