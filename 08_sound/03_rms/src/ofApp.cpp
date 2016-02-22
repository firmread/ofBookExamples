#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    
    bufferSize = 256;
    ofSoundStreamSetup( 0, 2, 44100, bufferSize, 4);
    vol = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    cout << vol << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(245, 58, 135);
    ofDrawCircle(ofGetWindowSize()/2, vol * ofGetHeight());
    
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer & buffer){
    // modified from audioInputExample
    float rms = 0.0;
    int numCounted = 0;
    for (int i = 0; i < bufferSize; i++){
        float leftSample = buffer[i * 2] * 0.5;
        float rightSample = buffer[i * 2 + 1] * 0.5;
        
        rms += leftSample * leftSample;
        rms += rightSample * rightSample;
        numCounted += 2;
    }
    
    rms /= (float)numCounted;
    rms = sqrt(rms);
    // rms is now calculated
    vol = rms;
}
