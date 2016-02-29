#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	mesh.setMode(OF_PRIMITIVE_LINES);
	mesh.enableColors();
	mesh.enableIndices();

	ofVec3f eyeLeftTop(50.0, 25.0, 0.0);
	ofVec3f eyeLeftBottom(50.0, 50.0, 0.0);
	ofVec3f eyeRightTop(100.0, 25.0, 0.0);
	ofVec3f eyeRightBottom(100.0, 50.0, 0.0);
	ofVec3f mouthLeft(50.0, 75.0, 0.0);
	ofVec3f mouthMiddle(75.0, 100.0, 0.0);
	ofVec3f mouthRight(100.0, 75.0, 0.0);

	mesh.addVertex(eyeLeftTop);
	mesh.addVertex(eyeLeftBottom);
	mesh.addIndex(0);
	mesh.addIndex(1);
	mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
	mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));

	mesh.addVertex(eyeRightTop);
	mesh.addVertex(eyeRightBottom);
	mesh.addIndex(2);
	mesh.addIndex(3);
	mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
	mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));

	mesh.addVertex(mouthLeft);
	mesh.addVertex(mouthMiddle);
	mesh.addVertex(mouthRight);
	mesh.addIndex(4);
	mesh.addIndex(5);
	mesh.addIndex(5);
	mesh.addIndex(6);
	mesh.addColor(ofFloatColor(0.0, 1.0, 0.0));
	mesh.addColor(ofFloatColor(0.0, 1.0, 0.0));
	mesh.addColor(ofFloatColor(0.0, 1.0, 0.0));

	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	mesh.draw();
}

