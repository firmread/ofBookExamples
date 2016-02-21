
#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
		void mouseMoved(int x, int y );

		float timeScale;
		float clearAlpha;

};
