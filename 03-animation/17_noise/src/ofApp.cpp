#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,255,255);
	//ofSetFrameRate(5);
	ofSetVerticalSync(true);
	colorScheme.load("sunset.png");
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableAlphaBlending();
	ofSetColor(255,255,255, 100);
	ofSeedRandom(0); // always pick the same random numbers.

	for (int i = 0; i < mouseX*3; i++){
		float x = ofNoise(ofGetElapsedTimef()*0.2, i*0.3)*ofGetWidth();
		float y = ofNoise(-ofGetElapsedTimef()*0.2, i*0.3)*ofGetHeight();
		ofColor col = getColorForPixel( ofMap(x,0,ofGetWidth(), 0, colorScheme.getWidth()),
                                        ofMap(y,0,ofGetHeight(), 0, colorScheme.getHeight()));
		col.a = 85;	// set some alpha. 
		ofSetColor(col);
		ofDrawCircle(x,y,ofRandom(4,40));
	}
}

//--------------------------------------------------------------
ofColor ofApp::getColorForPixel(int x, int y){
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (x >= colorScheme.getWidth()) x = colorScheme.getWidth()-1;
	if (y >= colorScheme.getHeight()) y = colorScheme.getHeight()-1;

	return colorScheme.getColor(x,y);
}
