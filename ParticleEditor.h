#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "src/Button.h";
#include "Slider.h";
#include "src/UI.h";

class ParticleEditor
{
public:
	ParticleEditor();
	ParticleEditor(vector<Particle> *_particles);
	~ParticleEditor();

	bool* isActive();

	void mousePressed(int mouseX, int mouseY);

	void addParticles();

	void draw();

	void addUI(UI* _ui);//Can't be passed in constructor, because UI takes variables related to this class

private:
	vector<Particle> *particles;//A pointer to the particles array of particles used in the main part of the program

	bool active;//Whether or not to react to user input

	UI* ui;

	double radius = 90;//The radius of the large circle of particles created when a user adds them
	double maxRadius = 200;
	double minRadius = 20;

	double particleRadius = 4.0;//The radius of the indivdual particles

	double centerX;
	double centerY;

	double mass = 400;//The mass of each particles
	double maxMass = 5000;
	double minMass = 100;

	//The starting speed of the new particles
	double xSpeed = 0;
	double ySpeed = 0;
	double maxSpeed = 0.005;
	double minSpeed = -0.005;

};