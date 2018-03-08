#include "ofApp.h"

//The speed at which time moves, declared staticly because they're used all over the program
int Space::timeStep = 5;
int Space::minTimeStep = -1000;
int Space::maxTimeStep = 1000;

//--------------------------------------------------------------
void ofApp::setup() {

	

	loadParticles();

	editor = ParticleEditor(&particles);
	ui = UI(&particleGravityOn, &mouseGravityOn, &particleCollisionsOn, editor.isActive(), &Space::timeStep, &Space::maxTimeStep, &Space::minTimeStep, &helpBoxOpen, &clearParticles);
	editor.addUI(&ui);
}

void ofApp::loadParticles()
{
	loadParticleCircle(120, 4.0, 600, 400, 400, 0);//Loads a circle made of smaller circles (particles)
	//loadParticleCircle(40, 4.0, 200, 500, 800, 0.05);
}

void ofApp::loadParticleCircle(double radius, double smallRadius, double centerX, double centerY, double mass, double speed)
{
	for (int j = 0; j <= radius / (smallRadius) + 9; j++) {//Creates rings of particles that decrease in size, creating a circle
		radius -= smallRadius * 2;//smallRadius refers to the radius of the particle, radius is the radius of the whole circle

		double circumferance = radius * 2 * PI;//The circumferance of the current ring
		int numCircles = floor(circumferance / smallRadius) / 2;

		double angleIncrement = 2 * PI / numCircles;

		for (int i = 0; i < numCircles; i++)//Places particles along the ring
		{
			double x = centerX + radius * cos(i * angleIncrement);
			double y = centerY + radius * sin(i * angleIncrement);

			particles.push_back(Particle(x, y, speed, 0, mass, smallRadius, ofColor(64, 128, 190)));
		}
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	if (clearParticles)//If the clear particles button has been clicked
	{
		particles.clear();
		clearParticles = false;
	}
	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].calculate();
	}

	//The various options for physics features
	if (particles.size() > 0)
	{
		if (particleGravityOn) {
			particleGravity();
		}
		if (mouseGravityOn) {
			gravityAtMouse();
		}
		if (particleCollisionsOn) {
			particleCollisions();
		}
	}

	ui.calculate();
}

void ofApp::particleCollisions()
{
	for (int i = 0; i < particles.size() - 1; i++)
	{
		for (int j = i + 1; j < particles.size(); j++) {//j=i+1 stops repeat collisions and cuts down on calculations
			//If the particles collide
			if (abs(particles[i].getX() - particles[j].getX()) < particles[i].getRadius() + particles[j].getRadius())
			{
				//This if statement is split into two because it gets resource intensive with a large number of particles
				if (abs(particles[i].getY() - particles[j].getY()) < particles[i].getRadius() + particles[j].getRadius()) {
						
					float v0 = particles[i].getVMag();
					float m0 = particles[i].getMass();
					double angle0 = particles[i].getAngle();
					float x0 = particles[i].getX();
					float y0 = particles[i].getY();

					float v1 = particles[j].getVMag();
					float m1 = particles[j].getMass();
					double angle1 = particles[j].getAngle();
					float x1 = particles[j].getX();
					float y1 = particles[j].getY();

					particles[i].collide(v1, m1, angle1, x1, y1, j);
					particles[j].collide(v0, m0, angle0, x0, y0, i);

				}
			}
			
		}
	}
}

//Calculates the gravity between particles
void ofApp::particleGravity()
{
	for (int i = 0; i < particles.size(); i++)
	{
		for (int j = i + 1; j < particles.size(); j++)//j = i + 1 to half calculations because the gravitational force between two point masses is equal
		{
			double distX = particles[i].getX() - particles[j].getX();
			double distY = particles[i].getY() - particles[j].getY();
			double distSquared = (distX * distX) + (distY * distY);//keep it squared because sqrt is resource intensive

			double F = G * particles[j].getMass() * particles[i].getMass() / distSquared;//Newtons law of gravitation

			double limit = particles[i].getRadius() + particles[j].getRadius();

			if (distSquared > limit * limit) {//Stops gravity being calculated when the particles are intersecting 
				particles[j].applyForce(F, particles[i].getX(), particles[i].getY());
				particles[i].applyForce(F, particles[j].getX(), particles[j].getY());
			}
		}
	}
}


//Applys a gravitational force on particles from the position of the mouse
void ofApp::gravityAtMouse()
{
	for (int i = 0; i < particles.size(); i++)
	{
		double distX = particles[i].getX() - mouseX;
		double distY = particles[i].getY() - mouseY;
		double distSquared = (distX * distX) + (distY * distY);

		double F = (G * particles[i].getMass() * 1000000) / distSquared;

		if (distSquared > 4) {
			particles[i].applyForce(F, mouseX, mouseY);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);

	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].render();
	}

	ui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_RIGHT)
	{
		Space::timeStep += 100;
		cout << Space::timeStep << endl;
	}
	if (key == OF_KEY_LEFT)
	{
		Space::timeStep -= 100;
		cout << Space::timeStep << endl;
	}
	if (key == OF_KEY_BACKSPACE)
	{
		cout << ofGetFrameRate() << endl;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	ui.mouseDragged(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	if (!ui.mousePressed(x, y)) {
		editor.mousePressed(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
