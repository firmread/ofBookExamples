#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
        void setupArduino(const int & version);
        void updateArduino();
    
        ofArduino myArduino;
        bool bSetupArduino;			// flag variable for setting up arduino once

};
