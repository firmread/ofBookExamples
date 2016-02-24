#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	bool succ = true;
	succ = image.load("stars.png");
	if (!succ) {
		cerr << "loading image failed ...\n";
	}
	
	mesh.setMode(OF_PRIMITIVE_POINTS);
	
	float intensityThreshold = 150.0;
	int w = image.getWidth();
	int h = image.getHeight();
	for (int x=0; x<w; ++x) {
		for (int y=0; y<h; ++y) {
			ofColor c = image.getColor(x, y);
			float intensity = c.getLightness();
			if (intensity >= intensityThreshold) {
				ofVec3f pos(x, y, 0.0);
				mesh.addVertex(pos);
				mesh.addColor(c);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0,0,255);
	mesh.draw();
}
