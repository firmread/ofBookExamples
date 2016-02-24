#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(30,30);
	
	for (auto line : lines) {
		ofDrawLine(line.a, line.b);
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	for (auto point : drawnPoints){
		ofPoint mouse;
		mouse.set(x,y);
		float dist = (mouse - point).length();
		if (dist < 50){
			Line lineTemp;
			lineTemp.a = mouse;
			lineTemp.b = point;
			lines.push_back(lineTemp);
		}
	}
	drawnPoints.push_back(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

