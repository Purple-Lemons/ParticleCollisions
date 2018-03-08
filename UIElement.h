/*
Used as a parent class for ui elements
*/
#pragma once

#include "ofMain.h"

class UIElement
{
public:
	UIElement();
	~UIElement();

protected:

	float x;
	float y;
	float width;
	float height;

	string label;

	ofColor color;

	ofTrueTypeFont font;
};