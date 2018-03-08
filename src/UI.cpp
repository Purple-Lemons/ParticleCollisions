#include "UI.h"

UI::UI() 
{

}

UI::UI(bool *particleGravityOn, bool *mouseGravityOn, bool *particleCollisionsOn, bool *particleEditorOn, int *timeStep, int *maxTimeStep, int *minTimeStep, bool* _helpBoxOpen, bool* clearParticles)
	:helpBoxOpen(_helpBoxOpen), particleEditorOpen(particleEditorOn)
{
	ofColor color = ofColor(50, 90, 102, 255);//The background colour for the buttons

	string helpBox = "Help: \n"
		"Use the slider at the bottom of the screen to change the speed of time.\n\n"
		"Use the UI on the left of the screen to toggle various features.\n\n"
		"While using the particle editor change the parameters using the sliders\n"
		"next to the button, click on the screen to add the particles.\n\n"
		"Using features such as particle gravity will slow down the system\n"
		"signifcantly, especially with a lot of particles.\n\n";//Some information for the usert

	addButton(_helpBoxOpen, "Help", color);

	//Adds a text box in line with the first button
	textBoxes.push_back(TextBox(70, buttons.size() * 42 + 10, 610, 200, helpBox, color));

	addButton(particleCollisionsOn, "Particle\nCollisions", color);
	addButton(mouseGravityOn, "Mouse\nGravity", color);
	addButton(particleGravityOn, "Particle\nGravity", color);
	addButton(particleEditorOn, "Particle\nEditor", color);
	addButton(clearParticles, "Clear\nParticles", color);
	
	timeStepSlider = Slider<int>(timeStep, maxTimeStep, minTimeStep, 400, 850, 800, 32, "Time Step");
}

UI::~UI()
{

}

void UI::draw()
{
	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].draw();
	}
	
	if (*particleEditorOpen)
	{
		for (int i = 0; i < editorSliders.size(); i++)
		{
			editorSliders[i].draw();
		}
	}

	timeStepSlider.draw();

	if (*helpBoxOpen) {
		for (int i = 0; i < textBoxes.size(); i++)
		{
			textBoxes[i].draw();
		}
	}
}

void UI::addButton(bool *action, string label, ofColor color)
{
	int x = 10;
	int y = buttons.size() * 42 + 10;
	int width = 50;
	int height = 32;

	buttons.push_back(Button(action, x, y, width, height, label, color));
}

//Checks if a mouse press has interacted with any of the ui
bool UI::mousePressed(int mouseX, int mouseY)
{
	bool hasUIBeenClicked = false;

	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i].pressed(mouseX, mouseY))
		{
			hasUIBeenClicked = true;
			buttons[i].toggle();
		}
	}
	for (int i = 0; i < editorSliders.size(); i++)
	{
		if (editorSliders[i].clicked(mouseX, mouseY))
		{
			hasUIBeenClicked = true;
		}
	}
	if (timeStepSlider.clicked(mouseX, mouseY))
	{
		hasUIBeenClicked = true;
	}

	return hasUIBeenClicked;
}

//Allows a use to drag the mouse to interact with sliders
void UI::mouseDragged(int mouseX, int mouseY)
{
	for (int i = 0; i < editorSliders.size(); i++)
	{
		editorSliders[i].clicked(mouseX, mouseY);
	}
	timeStepSlider.clicked(mouseX, mouseY);
}

//Adds sliders next to the particle editor button
void UI::addEditorSlider(double *action, double *actionMax, double *actionMin, string label)
{
	int height = 16;
	int width = 100;

	int x = 70;
	int y = 4 * 42 + 10 + editorSliders.size() * (height + 10); //The positin of the particle editor buttton

	editorSliders.push_back(Slider<double>(action, actionMax, actionMin, x, y, width, height, label));
}

