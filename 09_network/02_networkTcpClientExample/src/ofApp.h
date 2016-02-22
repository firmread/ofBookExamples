#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		
		ofxTCPClient tcpClient;
		string msgTx, msgRx;

		ofTrueTypeFont  mono;
		ofTrueTypeFont  monosm;

		float counter;
		int connectTime;
        int deltaTime;

        int size;
};

