#pragma once

#include "ofMain.h"
#include "../Particle.h"
#include <math.h>
#include "../Space.h"
#include "UI.h"
#include "../ParticleEditor.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void loadParticles();
		void loadParticleCircle(double radius, double smallRadius, double centerX, double centerY, double mass, double speed);
		void particleCollisions();
		void particleGravity();
		void gravityAtMouse();

	private:
		double G = 0.000000000066742;
		vector<Particle> particles;

		bool particleGravityOn = false;
		bool mouseGravityOn = false;
		bool particleCollisionsOn = true;
		bool helpBoxOpen = false;

		bool clearParticles = false;
		
		UI ui;

		ParticleEditor editor;
};
