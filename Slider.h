#pragma once

#include "ofMain.h"
#include "Space.h"
#include "UIElement.h"

template<typename T>//The slider can alter various types of number
class Slider : UIElement
{
public:
	Slider();
	Slider(T *_action, T *_maxActionValue, T *_minActionValue, int _x, int _y, int _width, int _height, string _label);
	~Slider();

	void draw();

	bool clicked(int mouseX, int mouseY);

	void dragged(int mouseX, int mouseY);

private:
	T *action;
	T *maxActionValue;
	T *minActionValue;

	float sliderPosition;

	ofColor color1;
	ofColor color2;
	ofColor textColor;

	ofTrueTypeFont font;
};