#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
	
		ofImage image;
		ofMesh mesh;
	
		ofEasyCam easyCam;
		vector<ofVec3f> offsets;
	
		// We are going to use these to allow us to toggle orbiting on and off
		ofMesh meshCopy;
		bool orbiting;
		float startOrbitTime;
	
		// These variables will let us store the polar coordinates of each vertex
		vector <float> distances;
		vector <float> angles;
		ofVec3f meshCentroid;
	
		bool mouseDisplacement;
};
