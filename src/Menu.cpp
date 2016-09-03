/*
 **
 ** Made by Applelo
 ** And also MisterAlex (but a little)
 **
 */

#include "../include/Menu.hh"
extern unsigned int font_size;
extern unsigned char font[];

Menu::Menu() {
	_tfont = vita2d_load_font_mem(font, font_size);

	_engine = new Engine();
	_buttonPlay = new Buttons();
	_buttonCredits = new Buttons();
	_buttonExit = new Buttons();
	_buttonBack = new Buttons();

	_step = MAIN;

	_xTouch = 0;
	_yTouch = 0;
	_oldXTouch = 0;
	_oldYTouch = 0;

	_buttonPlay = new Buttons( _tfont, "Play", (SCREEN_L-(SCREEN_L/4))/2, SCREEN_H/9, SCREEN_L/4, SCREEN_H/9);
	_buttonPlay->setSelected(true);
	_buttonCredits = new Buttons( _tfont, "Credits", (SCREEN_L-(SCREEN_L/4))/2, SCREEN_H/9*3, SCREEN_L/4, SCREEN_H/9);
	_buttonExit = new Buttons( _tfont, "Exit", (SCREEN_L-(SCREEN_L/4))/2, SCREEN_H/9*5, SCREEN_L/4, SCREEN_H/9);
	_buttonBack = new Buttons( _tfont, "Back", (SCREEN_L-(SCREEN_L/4))/2, SCREEN_H/9*5, SCREEN_L/4, SCREEN_H/9);

}

Menu::~Menu() {
}


void Menu::game() {
	_engine->displayWorld();
	_engine->control();
	_engine->check();
}

void Menu::main() {

	sceTouchPeek(SCE_TOUCH_PORT_FRONT, &_touch, 1);
	_engine->displayWorld();
	_buttonPlay->displayButton();
	_buttonCredits->displayButton();
	_buttonExit->displayButton();

	_xTouch = lerp(_touch.report[0].x, 1919, 960);
	_yTouch = lerp(_touch.report[0].y, 1087, 544);

	if (_buttonPlay->touchButton(_xTouch, _yTouch) && _touch.reportNum > 0 && _oldXTouch != _xTouch) {
		_step = GAME;
	}
	if (_buttonCredits->touchButton(_xTouch, _yTouch) && _touch.reportNum > 0 && _oldXTouch != _xTouch) {
		_step = CREDITS;
	}
	if (_buttonExit->touchButton(_xTouch, _yTouch) && _touch.reportNum > 0 && _oldXTouch != _xTouch) {
		_step = EXIT;
	}

	_oldXTouch = _xTouch;
	_oldYTouch = _yTouch;
}

void Menu::credits() {

	sceTouchPeek(SCE_TOUCH_PORT_FRONT, &_touch, 1);
	_buttonBack->displayButton();

	_xTouch = lerp(_touch.report[0].x, 1919, 960);
	_yTouch = lerp(_touch.report[0].y, 1087, 544);

	if (_buttonBack->touchButton(_xTouch, _yTouch) && _touch.reportNum > 0 && _oldXTouch != _xTouch) {
		_step = MAIN;
	}

	_oldXTouch = _xTouch;
	_oldYTouch = _yTouch;
}

//Setter
void Menu::setMenu(const Step step) {
	_step = step;
}

// Getter
const Step Menu::getMenu() const {
	return _step;
}
