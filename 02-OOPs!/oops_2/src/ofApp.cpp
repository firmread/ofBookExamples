#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    myBall1.setup();
    myBall2.setup();
    myBall3.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    myBall1.update();
    myBall2.update();
    myBall3.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myBall1.draw();
    myBall2.draw();
    myBall3.draw();

}