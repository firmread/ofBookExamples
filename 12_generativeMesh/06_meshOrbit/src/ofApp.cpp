#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(60);
	
	bool succ = true;
	succ = image.load("stars.png");
	if (!succ) {
		cerr << "loading image failed ...\n";
	}
	image.resize(200, 200);
	mesh.setMode(OF_PRIMITIVE_LINES);
	
	float intensityThreshold = 150.0;
	int w = image.getWidth();
	int h = image.getHeight();
	for (int x=0; x<w; ++x) {
		for (int y=0; y<h; ++y) {
			ofColor c = image.getColor(x, y);
			float intensity = c.getLightness();
			// z-coordinate shift depends on point's saturation
			if (intensity >= intensityThreshold) {
				float saturation = c.getSaturation();
				float z = ofMap(saturation, 0, 255, -100, 100);
				ofVec3f pos(x*4, y*4, z);
				mesh.addVertex(pos);
				mesh.addColor(c);
			}
		}
	}
	
	float connectionDistance = 30;
	int numVerts = mesh.getNumVertices();
	for (int a=0; a<numVerts; ++a) {
		ofVec3f verta = mesh.getVertex(a);
		for (int b=a+1; b<numVerts; ++b) {
			ofVec3f vertb = mesh.getVertex(b);
			float distance = verta.distance(vertb);
			if (distance <= connectionDistance) {
				mesh.addIndex(a);
				mesh.addIndex(b);
			}
		}
	}
	
	
	
	for (int x=0; x<w; ++x) {
		for (int y=0; y<h; ++y) {
			ofColor c = image.getColor(x, y);
			float intensity = c.getLightness();
			if (intensity >= intensityThreshold) {
				float saturation = c.getSaturation();
				float z = ofMap(saturation, 0, 255, -100, 100);
				ofVec3f pos(x*4, y*4, z);
				mesh.addVertex(pos);
				mesh.addColor(c);
				
				// And add this line:
				// It will create a ofVec3f with 3 random values
				// These will allow us to move the x, y and z coordinates of each vertex independently
				offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
			}
		}
	}
	
	
	meshCentroid = mesh.getCentroid();
	for (int i=0; i<numVerts; ++i) {
		ofVec3f vert = mesh.getVertex(i);
		float distance = vert.distance(meshCentroid);
		float angle = atan2(vert.y-meshCentroid.y, vert.x-meshCentroid.x);
		distances.push_back(distance);
		angles.push_back(angle);
	}
	
	// These variables will allow us to toggle orbiting on and off
	orbiting = false;
	startOrbitTime = 0.0;
	meshCopy = mesh;		// Store a copy of the mesh, so that we can reload the original state
}

//--------------------------------------------------------------
void ofApp::update(){
	int numVerts = mesh.getNumVertices();
	for (int i=0; i<numVerts; ++i) {
		ofVec3f vert = mesh.getVertex(i);
		
		float time = ofGetElapsedTimef();
		float timeScale = 5.0;
		float displacementScale = 0.75;
		ofVec3f timeOffsets = offsets[i];
		
		// A typical design pattern for using Perlin noise uses a couple parameters:
		// ofSignedNoise(time*timeScale+timeOffset)*displacementScale
		//     ofSignedNoise(time) gives us noise values that change smoothly over time
		//     ofSignedNoise(time*timeScale) allows us to control the smoothness of our noise (smaller timeScale, smoother values)
		//     ofSignedNoise(time+timeOffset) allows us to use the same Perlin noise function to control multiple things and have them look as if they are moving independently
		//     ofSignedNoise(time)*displacementScale allows us to change the bounds of the noise from [-1, 1] to whatever we want
		// Combine all of those parameters together, and you've got some nice control over your noise
		
		vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
		vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
		vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
		mesh.setVertex(i, vert);
	}
	
	if (orbiting) {
		int numVerts = mesh.getNumVertices();
		for (int i=0; i<numVerts; ++i) {
			ofVec3f vert = mesh.getVertex(i);
			float distance = distances[i];
			float angle = angles[i];
			float elapsedTime = ofGetElapsedTimef() - startOrbitTime;
			
			// Lets adjust the speed of the orbits such that things that are closer to
			// the center rotate faster than things that are more distant
			float speed = ofMap(distance, 0, 200, 1, 0.25, true);
			
			// To find the angular rotation of our vertex, we use the current time and
			// the starting angular rotation
			float rotatedAngle = elapsedTime * speed + angle;
			
			// Remember that our distances are calculated relative to the centroid of the mesh, so
			// we need to shift everything back to screen coordinates by adding the x and y of the centroid
			vert.x = distance * cos(rotatedAngle) + meshCentroid.x;
			vert.y = distance * sin(rotatedAngle) + meshCentroid.y;
			
			mesh.setVertex(i, vert);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofColor centerColor = ofColor(85, 78, 68);
	ofColor edgeColor(0, 0, 0);
	ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
	
	easyCam.begin();
		ofPushMatrix();
			ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
			mesh.draw();
		ofPopMatrix();
	easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'o') {
		orbiting = !orbiting; 			// This inverts the boolean
		startOrbitTime = ofGetElapsedTimef();
		mesh = meshCopy;			// This restores the mesh to its original values
	}
}
