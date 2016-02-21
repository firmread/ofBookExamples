#pragma once
#include "ofMain.h"
#include "particle.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		vector <particle> particles;
		int nPtsW;
		int nPtsH;
};
