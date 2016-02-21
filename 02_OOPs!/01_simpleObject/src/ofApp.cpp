#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    myBall.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    myBall.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myBall.draw();

}
