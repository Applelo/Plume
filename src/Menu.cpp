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
	_buttonScore = new Buttons();
	_buttonBack = new Buttons();

	_step = MAIN;

	_xTouch = 0;
	_yTouch = 0;
	_oldXTouch = 0;
	_oldYTouch = 0;

	//buttonPlay
	_buttonPlay->setX((SCREEN_L-(SCREEN_L/4))/2);
	_buttonPlay->setY(SCREEN_H/9);
	_buttonPlay->setWidth(SCREEN_L/4);
	_buttonPlay->setHeight(SCREEN_H/9);
	_buttonPlay->setFont(_tfont);
	_buttonPlay->setText("Play");
	_buttonPlay->setSelected(true);

	//buttonCredits
	_buttonCredits->setX((SCREEN_L-(SCREEN_L/4))/2);
	_buttonCredits->setY(SCREEN_H/9*3);
	_buttonCredits->setWidth(SCREEN_L/4);
	_buttonCredits->setHeight(SCREEN_H/9);
	_buttonCredits->setFont(_tfont);
	_buttonCredits->setText("Credits");

	//buttonExit
	_buttonExit->setX((SCREEN_L-(SCREEN_L/4))/2);
	_buttonExit->setY(SCREEN_H/9*5);
	_buttonExit->setWidth(SCREEN_L/4);
	_buttonExit->setHeight(SCREEN_H/9);
	_buttonExit->setFont(_tfont);
	_buttonExit->setText("Exit");


//buttonBack
	_buttonBack->setX((SCREEN_L-(SCREEN_L/4))/2);
	_buttonBack->setY(SCREEN_H/9*5);
	_buttonBack->setWidth(SCREEN_L/4);
	_buttonBack->setHeight(SCREEN_H/9);
	_buttonBack->setFont(_tfont);
	_buttonBack->setText("Back");
}

Menu::~Menu() {
}


void Menu::game() {
	_engine->control();
	_engine->displayWorld();
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
