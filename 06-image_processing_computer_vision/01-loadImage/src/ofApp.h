#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void draw();
    
    // Here in the header (.h) file, we declare an ofImage:
    ofImage myImage;
};
