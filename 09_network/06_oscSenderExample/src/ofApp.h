#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define PORT 12345

//--------------------------------------------------------
class ofApp : public ofBaseApp {

	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
    
		ofTrueTypeFont font;
		ofxOscSender sender;
		ofBuffer imgAsBuffer;
		ofImage img;
};

