#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		ofxTCPServer TCP;

		ofTrueTypeFont  mono;
		ofTrueTypeFont  monosm;

		vector <string> storeText;
		uint64_t lastSent;
};

