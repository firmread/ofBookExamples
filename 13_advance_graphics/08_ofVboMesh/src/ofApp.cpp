#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mesh.addVertex(ofVec3f(20,20));
	mesh.addVertex(ofVec3f(40,20));
	mesh.addVertex(ofVec3f(40,40));
	mesh.addVertex(ofVec3f(20,40));
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
	mesh2 = mesh;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	mesh.getVertices()[1].x+=0.1;
	mesh2.getVertices()[1].x=mesh.getVertices()[1].x + 0.1;
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	mesh.draw();
	mesh2.draw(); // fast!!

}
