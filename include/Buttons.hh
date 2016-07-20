/*
**
** Made by MisterAlex
** And also Applelo (but a little)
**
*/

#ifndef BUTTONS_HH_
# define BUTTONS_HH_

# include "Utils.h"

class Buttons {
private:
	int _x;
	int _y;
	std::string _text;
	int _width;
	int _height;
	vita2d_font* _tfont;
	bool _locked;
	bool _isVisible;
	bool _selected;
	int _txtCenterW;
	int _txtCenterH;
	int _alphaSelect;
	int _compteurSelect;
	vita2d_texture* _texture;

public:
	Buttons();
	Buttons(vita2d_font* font, std::string name, int x, int y, int width, int height);
	virtual ~Buttons();

	//Setter
	void setX(const int x);
	void setY(const int y);
	void setText(const std::string text);
	void setWidth(const int width);
	void setHeight(const int height);
	void setFont(vita2d_font* tfont);
	void setLocked(const bool locked);
	void setIsVisible(const bool locked);
	void setSelected(const bool selected);
	void setTexture(vita2d_texture* texture);


	//Getter
	const int getX() const;
	const int getY() const;
	const std::string getText() const;
	const int getWidth() const;
	const int getHeight() const;
	const bool getLocked() const;
	const bool getIsVisible() const;
	const bool getSelected() const;

	// Display
	void displayButton();

	//Touch
	const bool touchButton(int x, int y) const;
};

#endif /* !Buttons_HH_ */
