#pragma once

#include "UIElement.h"

class TextBox : UIElement
{
public:
	TextBox();
	TextBox(int _x, int _y, int _width, int _height, string _label, ofColor _color);
	~TextBox();

	void draw();
};