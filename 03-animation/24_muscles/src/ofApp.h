#pragma once

#include "ofMain.h"
#include "particle.h"
#include "spring.h"

class ofApp : public ofBaseApp{
	public:
		// let's make a vector of them
		vector <particle> particles;
		vector <spring> springs;

		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
};
