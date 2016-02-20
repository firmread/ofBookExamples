#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0); // let's make our background black
    ofSetCircleResolution(100);
    
    int xCenter = ofGetWidth()*.5;
    int yCenter = ofGetHeight()*.5;
    int dim = ofRandom(200,250);
    redBall.setup(xCenter, yCenter, dim);
    greenBall.setup(xCenter, yCenter, dim);
    blueBall.setup(xCenter, yCenter, dim);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    redBall.update();
    greenBall.update();
    blueBall.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    redBall.draw();
    greenBall.draw();
    blueBall.draw();
    
}
