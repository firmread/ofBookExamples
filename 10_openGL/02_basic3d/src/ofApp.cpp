#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	light.setup();
	light.setPosition(-100, 200,0);
	ofEnableDepthTest();
	
	boxMaterial.setDiffuseColor(ofFloatColor::red);
	boxMaterial.setShininess(0.02);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	// here you will draw your object
		boxMaterial.begin();
			box.draw();
		boxMaterial.end();
	cam.end();
}
