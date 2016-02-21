#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		vector <ofPoint> points;
		float radius;
};
