#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "BallRed.h"
#include "BallGreen.h"
#include "BallBlue.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

        BallRed redBall;
        BallGreen greenBall;
        BallBlue blueBall;
    
};
