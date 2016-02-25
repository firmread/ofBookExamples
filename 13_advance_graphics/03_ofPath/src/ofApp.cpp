#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	path.moveTo(20,20);
	path.lineTo(40,20);
	path.lineTo(40,40);
	path.lineTo(20,40);
	path.close();
	path.setStrokeColor(ofColor::blue);
	path.setFillColor(ofColor::red);
	path.setFilled(true);
	path.setStrokeWidth(2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	path.draw();
}
