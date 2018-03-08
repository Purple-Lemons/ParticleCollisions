#include "Particle.h"

using namespace std;
Particle::Particle(double _x, double _y, double _xSpeed, double _ySpeed, double _mass, int _radius, ofColor _color)
	: x(_x), y(_y), xSpeed(_xSpeed), ySpeed(_ySpeed), mass(_mass), radius(_radius), color(_color)
{
}

void Particle::calculate()
{
	x += xSpeed * Space::timeStep;
	y += ySpeed * Space::timeStep;

	//Stops particles leaving the screen
	if (x - radius <= 0 || x + radius >= ofGetWidth())
	{
		xSpeed = -xSpeed;
	}

	if (y - radius <= 0 || y + radius >= ofGetHeight())
	{
		ySpeed = -ySpeed;
	}
}

//Calculates 2d elastic particle collisions
void Particle::collide(double v2, double m2, double angle2, double x2, double y2, int collisionPos)
{
	double xDist = x - x2;
	double yDist = y - y2;

	double contactAngle = atan2(yDist, xDist);
	double sinAngleDif = sin(getAngle() - contactAngle);
	double vMag = getVMag();

	//numerator for both x and y component of the collison equation are the same, so it is calculated by itself
	double v1Top = (vMag * cos(getAngle() - contactAngle) * (mass - m2) + 2 * m2 * v2 * cos(angle2 - contactAngle));

	//X Component of final velocity
	double v1x = (v1Top / (mass + m2)) * cos(contactAngle) + vMag * sinAngleDif * cos(contactAngle + PI / 2);

	//Y Component of final veclocity
	double v1y = (v1Top / (mass + m2)) * sin(contactAngle) + vMag * sinAngleDif * sin(contactAngle + PI / 2);

	xSpeed = v1x;
	ySpeed = v1y;
}

//Used to apply gravitational forces
void Particle::applyForce(double F, double x2, double y2)
{
	double a = F / mass;//The resultant acceleration
	double angle = atan2(y2 - y, x2 - x);//The angle at which the force is being applied

	xSpeed += (a * cos(angle)) * Space::timeStep;
	ySpeed += (a * sin(angle)) * Space::timeStep;
}

void Particle::render()
{
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
}

//------------------------------------------------------------------//

double Particle::getMass()
{
	return mass;
}

double Particle::getX()
{
	return x;
}

double Particle::getY()
{
	return y;
}

double Particle::getXSpeed()
{
	return xSpeed;
}

double Particle::getYSpeed()
{
	return ySpeed;
}

double Particle::getVMag()
{
	return sqrt((xSpeed * xSpeed) + (ySpeed * ySpeed));
}

double Particle::getAngle()
{
	return atan2(ySpeed, xSpeed);
}

double Particle::getRadius()
{
	return radius;
}
