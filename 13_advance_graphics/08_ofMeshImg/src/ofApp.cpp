#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	mesh.addVertex(ofVec3f(20,20));
	mesh.addTexCoord(ofVec2f(0,0));
	mesh.addVertex(ofVec3f(40,20));
	mesh.addTexCoord(ofVec2f(20,0));
	mesh.addVertex(ofVec3f(40,40));
	mesh.addTexCoord(ofVec2f(20,20));
	mesh.addVertex(ofVec3f(20,40));
	mesh.addTexCoord(ofVec2f(0,20));
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
	img.load("logo20x20.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	img.bind();
	mesh.draw();
	img.unbind();
}
