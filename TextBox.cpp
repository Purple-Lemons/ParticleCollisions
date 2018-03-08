/*
A class used for displaying large bodies of text on screen
*/
#include "TextBox.h"

TextBox::TextBox()
{

}

TextBox::TextBox(int _x, int _y, int _width, int _height, string _label, ofColor _color)
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	label = _label;
	color = _color;

	font.loadFont("verdana.ttf", 12);
}

TextBox::~TextBox()
{

}

void TextBox::draw()
{
	ofSetColor(color);
	ofRect(x, y, width, height);
	
	ofSetColor(255, 255, 255);
	font.drawString(label, x, y + 16);
}
