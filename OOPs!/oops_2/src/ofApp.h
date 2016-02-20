#pragma once

#include "ofMain.h"
#include "Ball.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
        Ball myBall1;
        Ball myBall2;
        Ball myBall3;
};
