// Example 3. Finding the Brightest Pixel in an Image

#include "ofApp.h"

//---------------------
void ofApp::setup(){
    laserTagImage.load("laser_tag.jpg");
}

//---------------------
void ofApp::draw(){
    ofBackground(255);
    
    int w = laserTagImage.getWidth();
    int h = laserTagImage.getHeight();
    
    float maxBrightness = 0; // these are used in the search
    int maxBrightnessX = 0; // for the brightest location
    int maxBrightnessY = 0;
    
    // Search through every pixel. If it is brighter than any
    // we've seen before, store its brightness and coordinates.
    // After testing every pixel, we'll know which is brightest!
    for(int y=0; y<h; y++) {
        for(int x=0; x<w; x++) {
            ofColor colorAtXY = laserTagImage.getColor(x, y);
            float brightnessOfColorAtXY = colorAtXY.getBrightness();
            if(brightnessOfColorAtXY > maxBrightness){
                maxBrightness = brightnessOfColorAtXY;
                maxBrightnessX = x;
                maxBrightnessY = y;
            }
        }
    }
    
    // Draw the image.
    ofSetColor (255);
    laserTagImage.draw(0,0);
    
    // Draw a circle at the brightest location.
    ofNoFill();
    ofDrawEllipse (maxBrightnessX, maxBrightnessY, 40,40);
}