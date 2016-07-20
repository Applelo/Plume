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
# include "Timer.hh"
# include "Utils.h"


class Engine {
private:
	std::vector<Buttons*> _buttons;

	Timer* _timer;
	vita2d_font* _tfont;
	std::map<std::string, vita2d_texture*> _textures;
	std::string _error;

public:
	Engine();
	virtual ~Engine();


};
#endif /* !ENGINE_HH_ */
