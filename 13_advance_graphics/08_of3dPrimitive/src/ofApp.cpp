#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	primitive.getMesh().addVertex(ofVec3f(20,20));
	primitive.getMesh().addVertex(ofVec3f(40,20));
	primitive.getMesh().addVertex(ofVec3f(40,40));
	primitive.getMesh().addVertex(ofVec3f(20,40));
	primitive.getMesh().setMode(OF_PRIMITIVE_TRIANGLE_FAN);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	primitive.move(ofVec3f(10,0,0));
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	primitive.draw();
}
