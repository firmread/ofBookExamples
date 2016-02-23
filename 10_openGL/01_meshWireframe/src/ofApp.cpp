#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	int width = 10, height = 10;
	ofMesh mesh;
	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			mesh.addVertex(ofPoint(x*20, y*20, 0)); // make a new vertex
			mesh.addColor(ofFloatColor(0, 0, 0));  // add a color at that vertex
		}
	}
	
	// what this is basically doing is figuring out based on the way we inserted vertices
	// into our vertex array above, which array indices of the vertex array go together
	// to make triangles. the numbers commented show the indices added in the first run of
	// this loop - notice here that we are re-using indices 1 and 10
	for (int y = 0; y < height-1; y++){
		for (int x=0; x < width-1; x++){
			mesh.addIndex(x + y * width);         // 0
			mesh.addIndex((x+1) + y * width);     // 1
			mesh.addIndex(x + (y+1) * width);     // 10
			
			mesh.addIndex((x+1) + y * width);     // 1
			mesh.addIndex((x+1) + (y+1) * width); // 11
			mesh.addIndex(x + (y+1) * width);     // 10
		}
	}
	ofTranslate(20, 20);
	mesh.drawWireframe();
}
