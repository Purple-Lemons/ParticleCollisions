/*
This class is a ui button that takes a pointer to a boolean and toggles 
that boolean when it is clicked, making it a general purpose button
*/

#include "Button.h"

Button::Button(bool* _action, int _x, int _y, int _width, int _height, string _label, ofColor _color)
	:action(_action)
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	color = _color;
	label = _label;

	outlineColor = ofColor(255, 255, 255);//Color of the button outline, displayed when a buttons state is true

	_action = nullptr;
	font.loadFont("verdana.ttf", 8);
}

Button::~Button()
{
	action = nullptr;
}

void Button::toggle()
{
	*action = !(*action);
}

void Button::draw()
{
	ofSetColor(color);
	ofRect(x, y, width, height);

	//If the button has been clicked, display a white border around it 
	if (*action)
	{
		ofSetColor(outlineColor);
		ofNoFill();
		ofRect(x, y, width, height);
		ofFill();
	}

	ofSetColor(255, 255, 255);
	font.drawString(label, x, y + 16);
}

//Checks is the button has been clicked
bool Button::pressed(int mouseX, int mouseY)
{
	return (mouseX > x && mouseX < x + width && mouseY > y && mouseY < y + height);
}