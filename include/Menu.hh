/*
**
** Made by MisterAlex
** And also Applelo (but a little)
**
*/

#ifndef MENU_HH_
# define MENU_HH_
# include "Buttons.hh"
# include "Engine.hh"
# include "Splash.hh"

typedef enum Step {
	SPLASH = 0,
	MAIN,
	GAME,
	CREDITS,
	LOOSE,
	EXIT
} Step;

class Menu {
private:
	int _xTouch;
	int _yTouch;
	int _oldXTouch;
	int _oldYTouch;

	Step _step;
	SceTouchData _touch;

	vita2d_font* _tfont;
	Engine* _engine;

	Buttons* _buttonPlay;
	Buttons* _buttonCredits;
	Buttons* _buttonExit;
	Buttons* _buttonBack;
	Buttons* _buttonOk;

	std::map<std::string, vita2d_texture*> _splashscreen;
	Splash* _splashGeki;

public:
	Menu();
	virtual ~Menu();

	//Getter
	const Step getMenu() const;

	//Setter
	void setMenu(const Step step);

	//Display Menu
	void splash();
	void main();
	void credits();
	void game();
	void loose();

};

#endif /* !MENU_HH_ */
