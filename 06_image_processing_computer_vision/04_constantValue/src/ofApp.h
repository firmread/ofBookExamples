// Example 4: Add a constant value to an image.
// This is done from "scratch", without OpenCV.

#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void draw();
    
    ofImage lincolnOfImageSrc; // The source image
    ofImage lincolnOfImageDst; // The destination image
};