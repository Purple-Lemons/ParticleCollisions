/*
This class is a ui slider that takes a pointer to some number and
allows a user to changes that number by dragging the slider-
*/
#include "Slider.h"

template<typename T>
Slider<T>::Slider()
{
}

template<typename T>
Slider<T>::Slider(T* _action, T* _maxActionValue, T* _minActionValue, int _x, int _y, int _width, int _height, string _label)
	:action(_action), maxActionValue(_maxActionValue), minActionValue(_minActionValue)
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	label = _label;

	//The colours of each side of the slider
	color1 = ofColor(255, 0, 0, 128);
	color2 = ofColor(0, 0, 255, 128);

	textColor = ofColor(255, 255, 255);

	font.loadFont("verdana.ttf", height / 2);

	sliderPosition = 0.5f;

	_action = nullptr;
}

template<typename T>
Slider<T>::~Slider()
{
	action = nullptr;
}

template<typename T>
void Slider<T>::draw()
{
	
	//Draw each side of this slider
	ofSetColor(color1);
	ofDrawRectangle(x, y, width * sliderPosition, height);

	ofSetColor(color2);
	ofDrawRectangle(x + width * sliderPosition, y, width * (1 - sliderPosition), height);

	ofSetColor(textColor);
	string fullLabel = label + ": " + to_string(*action);
	font.drawString(fullLabel, x + width / 2 - 32, y + height / 2);
}

template<typename T>
bool Slider<T>::clicked(int mouseX, int mouseY)
{
	//If the mouse click is within the buttons bounds
	if (mouseX > x && mouseX < x + width && mouseY > y && mouseY < y + height)
	{
		int sliderX = mouseX - x;//The absolute position of the mouse along the slider
		sliderPosition = (sliderX / width);//Sets the new position of the slider

		*action = sliderPosition * (*maxActionValue - *minActionValue) + *minActionValue;//Finds the new value based on the new slider position

		return true;
	}

	return false;
}

template<typename T>
void Slider<T>::dragged(int mouseX, int mouseY)
{
	if (mouseX > x && mouseX < x + width && mouseY > y && mouseY < y + height)
	{
		int sliderX = mouseX - x;
		sliderPosition = (sliderX / width);

		*action = sliderPosition * (*maxActionValue - *minActionValue) + *minActionValue;
	}
}