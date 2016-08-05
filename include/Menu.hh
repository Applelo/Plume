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

typedef enum Step {
	MAIN = 0,
	GAME,
	CREDITS,
	SCORE,
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
	Buttons* _buttonScore;
	Buttons* _buttonBack;

public:
	Menu();
	virtual ~Menu();

	//Getter
	const Step getMenu() const;

	//Setter
	void setMenu(const Step step);

	//Display Menu
	void main();
	void credits();
	void game();

};

#endif /* !MENU_HH_ */
