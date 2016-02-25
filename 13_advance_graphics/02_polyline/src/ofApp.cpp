#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	polyline.lineTo(20,20);
	polyline.lineTo(40,20);
	polyline.lineTo(40,40);
	polyline.lineTo(20,40);
	polyline.close();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	polyline.draw();
}
