#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
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