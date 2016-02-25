#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mesh.addVertex(ofVec3f(20,20));
	mesh.addColor(ofColor::red);
	mesh.addVertex(ofVec3f(40,20));
	mesh.addColor(ofColor::red);
	mesh.addVertex(ofVec3f(40,40));
	mesh.addColor(ofColor::blue);
	mesh.addVertex(ofVec3f(20,40));
	mesh.addColor(ofColor::blue);
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	mesh.draw();
}
