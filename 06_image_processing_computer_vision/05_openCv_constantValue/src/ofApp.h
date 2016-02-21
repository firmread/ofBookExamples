// Example 5: Add a constant value to an image, with ofxOpenCv.
// Make sure to use the ProjectGenerator to include the ofxOpenCv addon.
#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void draw();
    ofxCvGrayscaleImage lincolnCvImageSrc;
    ofxCvGrayscaleImage lincolnCvImageDst;
};