// Example 6: Thresholding
#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void draw();
    ofxCvGrayscaleImage myCvImageSrc;
    ofxCvGrayscaleImage myCvImageDst;
};