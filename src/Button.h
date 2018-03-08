#pragma once

#include "ofMain.h"
#include "../UIElement.h"

using namespace std;

class Button : UIElement
{
public:
	Button(bool* _action, int _x, int _y, int _height, int _width, string _label, ofColor _color);
	~Button();

	void toggle();

	void draw();

	bool pressed(int mouseX, int mouseY);

private:
	bool* action;//Points to a bool in ofApp that controls something

	ofColor outlineColor;
};