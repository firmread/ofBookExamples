#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0); // let's make our background black
    
    int xCenter = ofGetWidth()*.5;
    int yCenter = ofGetHeight()*.5;
    int dim = ofRandom(200,250);
    
    balls.push_back(*new BallRed());
    balls.push_back(*new BallGreen());
    balls.push_back(*new BallBlue());

    for (auto &b : balls) {
        b.setup(xCenter, yCenter, dim);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (auto &b : balls) {
        b.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (auto &b : balls) {
        b.draw();
    }
    
}
