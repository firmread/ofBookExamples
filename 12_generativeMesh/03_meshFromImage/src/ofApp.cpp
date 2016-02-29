#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Do a little extra error checking to see if the image was
	// loaded properly.  This is not in the chapter text.
	bool wasImageLoaded = image.load("stars.png");
	if (!wasImageLoaded) {
		cerr << "loading image failed ...\n";
	}
	
	mesh.setMode(OF_PRIMITIVE_POINTS);
	mesh.enableColors();
	
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
				// When addColor(...), the mesh will automatically convert
				// the ofColor to an ofFloatColor
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
	ofColor centerColor = ofColor(85, 78, 68);
	ofColor edgeColor(0, 0, 0);
	ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
	mesh.draw();
}
