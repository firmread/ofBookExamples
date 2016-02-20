#pragma once

#include "ofMain.h"
#include "Ball.h"

#define NBALLS 10  // this is a CONSTANT, a value you won't want to change throughout your program

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
        Ball myBall[NBALLS];
    
};
