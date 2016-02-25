#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	path.moveTo(20,20);
	path.lineTo(40,20);
	path.lineTo(40,40);
	path.lineTo(20,40);
	path.close();
	m.rotate(45, 0, 0, 0);
	m.translate(20, 20, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofMultMatrix(m);
	path.draw();

}
