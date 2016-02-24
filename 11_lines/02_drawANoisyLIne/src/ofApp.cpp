#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto &vert : line.getVertices()){
		vert.x += ofRandom(-1,1);
		vert.y += ofRandom(-1,1);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	line.draw();
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	ofPoint pt;
	pt.set(x,y);
	line.addVertex(pt);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	line.clear();
}

