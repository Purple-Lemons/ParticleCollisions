#pragma once

#include "Button.h"
#include "../Slider.h"
#include "../Slider.cpp"
#include "../TextBox.h"

class UI
{
public:
	UI();
	UI(bool *particleGravityOn, bool *mouseGravityOn, bool *particleCollisionsOn, bool *particleEditorOn, int *timeStep, int *maxTimeStep, int *minTimeStep, bool* helpBoxOpen, bool* clearParticles);
	~UI();

	void draw();

	bool mousePressed(int mouseX, int mouseY);

	void mouseDragged(int mouseX, int mouseY);

	void addButton(bool *action, string label, ofColor color);

	void addEditorSlider(double *action, double *actionMax, double *actionMin, string label);

private:

	vector<Button> buttons;
	vector<Slider<double>> editorSliders;
	vector<TextBox> textBoxes;

	Slider<int> timeStepSlider;

	bool* helpBoxOpen;
	bool* particleEditorOpen;
};
