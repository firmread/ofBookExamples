#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofFill();
	ofSetColor(255,0,0);
	ofBeginShape();
	ofVertex(20,20);
	ofVertex(40,20);
	ofVertex(40,40);
	ofVertex(20,40);
	ofEndShape(true);
	
	
	glColor4f(0.0,2.0,0.0,1.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(50,20);
	glVertex2i(70,20);
	glVertex2i(70,40);
	glVertex2i(50,40);
	glEnd();

}
