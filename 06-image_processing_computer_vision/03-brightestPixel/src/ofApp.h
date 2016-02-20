// Example 3. Finding the Brightest Pixel in an Image

#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void draw();
    
    // Replace this ofImage with live video, eventually
    ofImage laserTagImage;
};