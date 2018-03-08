/*
This class provides the functionality for users to add and remove
particles in the program
*/
#include "ParticleEditor.h"

ParticleEditor::ParticleEditor()
{

}

ParticleEditor::ParticleEditor(vector<Particle> *_particles)
	:particles(_particles)
{


	_particles = nullptr;
}

ParticleEditor::~ParticleEditor()
{
	particles = nullptr;
}

//Adds sliders to the main ui
void ParticleEditor::addUI(UI* _ui)
{
	ui = _ui;

	ui->addEditorSlider(&radius, &maxRadius, &minRadius, "Radius");
	ui->addEditorSlider(&xSpeed, &maxSpeed, &minSpeed, "X Speed");
	ui->addEditorSlider(&ySpeed, &maxSpeed, &minSpeed, "Y Speed");
	ui->addEditorSlider(&mass, &maxMass, &minMass, "Mass");
}

void ParticleEditor::draw()
{
	if (active)
	{

	}
}

void ParticleEditor::mousePressed(int mouseX, int mouseY)
{
	if (active) 
	{
		centerX = mouseX;
		centerY = mouseY;
		addParticles();
	}
}

void ParticleEditor::addParticles()
{
	double tempRadius = radius;
	for (int j = 0; j <= radius / (particleRadius) + 9; j++) {//Creates rings of particles that decrease in size, creating a circle
		radius -= particleRadius * 2;//smallRadius refers to the radius of the particle, radius is the radius of the whole circle

		double circumferance = radius * 2 * PI;//The circumferance of the current ring
		int numCircles = floor(circumferance / particleRadius) / 2;

		double angleIncrement = 2 * PI / numCircles;

		for (int i = 0; i < numCircles; i++)//Places particles along the ring
		{
			double x = centerX + radius * cos(i * angleIncrement);
			double y = centerY + radius * sin(i * angleIncrement);

			particles->push_back(Particle(x, y, xSpeed, ySpeed, mass, particleRadius, ofColor(64, 128, 190)));
		}
	}
	radius = tempRadius;
}

bool* ParticleEditor::isActive()
{
	return &active;
}