#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camera.setFov(60);  // this will actually do nothing since 60 is the default
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	camera.begin();
	// draw something
	ofDrawSphere(0, 0, 7);
	camera.end();
}
