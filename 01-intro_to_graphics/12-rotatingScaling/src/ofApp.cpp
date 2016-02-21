
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending(); // Remember if we are using transparency, we need to let openFrameworks know
    ofBackground(255);

    timeScale = 100.0;
    clearAlpha = 0.5;

}


//--------------------------------------------------------------
void ofApp::draw(){

    // Reverse the contrast of the rectangles and screen over time
    ofColor darkColor(0,0,0,255);  // Opaque black
    ofColor lightColor(255,255,255,255);  // Opaque white
    float time = ofGetElapsedTimef();  // Time in seconds
    float percent = ofMap(cos(time/2.0), -1, 1, 0, 1);  // Create a value that oscillates between 0 to 1
    ofColor bgColor = darkColor;  // Color for the transparent rectangle we use to clear the screen
    bgColor.lerp(lightColor, percent);  // This modifies our color "in place", check out the documentation page
    bgColor.a = clearAlpha;  // Our initial colors were opaque, but our rectangle needs to be transparent
    ofColor fgColor = lightColor;  // Color for the rectangle outlines
    fgColor.lerp(darkColor, percent);  // Modifies color in place

    // Semi-clear the screen, using a transparent rectangle
    ofSetColor(bgColor);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());  // ofBackground doesn't work with alpha, so draw a transparent rect

    // Draw the spiraling rectangles
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(fgColor);
    ofNoFill();
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);  // Translate to the center of the screen
        for (int i=0; i<100; i++) {
            // Draw the smallest rectangle first and scale out to bigger ones progressively
            ofScale(1.1, 1.1);

            // Make the rectangles spiral
            float time = ofGetElapsedTimef();
            float noise = ofSignedNoise(time * timeScale) * 20.0;
            ofRotate(noise);

            ofDrawRectangle(0, 0, 50, 50);
        }
    ofPopMatrix();
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    clearAlpha = ofMap(x, 0, ofGetWidth(), 0, 255);  // clearAlpha goes from 0 to 255 as the mouse moves from left to right
    timeScale = ofMap(y, 0, ofGetHeight(), 0, 1);  // timeScale goes from 0 to 1 as the mouse moves from top to bottom
}
