#pragma once

#include "ofMain.h"
#include "Ball.h"

class ofApp : public ofBaseApp{
	public:
        void setup();
		void update();
		void draw();
		
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
    
        vector <Ball> myBall;   // defining a vector of type Ball and naming it myBall
    
};
