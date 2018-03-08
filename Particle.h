#pragma once
#ifndef _PARTICLE
#define _PARTICLE

#include "ofMain.h"
#include <vector>
#include <math.h>
#include <stdio.h>
#include "Space.h"

class Particle
{
public:
	Particle(double _x, double _y, double _xSpeed, double _ySpeed, double _mass, int _dim, ofColor _color);

	double getMass();

	double getX();
	double getY();

	double getXSpeed();
	double getYSpeed();

	double getVMag();

	double getAngle();

	double getRadius();

	void calculate();
	void render();

	void collide(double v2, double m2, double angle2, double x2, double y2, int pos);

	void applyForce(double F, double x2, double y2);
private:
	double mass;

	double x;
	double y;

	double xSpeed;
	double ySpeed;

	double radius;

	ofColor color;
};

#endif


