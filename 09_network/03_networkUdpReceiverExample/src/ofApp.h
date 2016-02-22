#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		ofxUDPManager udpConnection;
		ofTrueTypeFont  mono;
		ofTrueTypeFont  monosm;

		vector<ofPoint> stroke;
};

