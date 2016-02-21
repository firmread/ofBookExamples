// Example 2. An application to capture, display,
// and invert live video from a webcam.

#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber myVideoGrabber;
    ofTexture myTexture;
    
    unsigned char* invertedVideoData;
    int camWidth;
    int camHeight;
};