#pragma once
#include "ofMain.h"
#include "particle.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		void keyPressed  (int key);
		void mouseDragged(int x, int y, int button);

		vector <particle> particles;
		bool bRepel;
		float radius;
		float strength;
};
