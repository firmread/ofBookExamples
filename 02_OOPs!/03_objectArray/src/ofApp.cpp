#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(100);
    
    for (int i=0; i <NBALLS; i++) {
        myBall[i].setup();
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i <NBALLS; i++) {
        myBall[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i <NBALLS; i++) {
        myBall[i].draw();
    }

}