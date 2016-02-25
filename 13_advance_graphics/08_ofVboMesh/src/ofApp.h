#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		ofVboMesh mesh;
		ofVboMesh mesh2;
		
};
