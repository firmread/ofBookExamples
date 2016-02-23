#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    
    vol = 0;
    smoothedVol =0;
    bufferSize = 256;

    ofSoundStreamSetup(0, 2, 44100, bufferSize, 4);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(245, 58, 135);
    ofPoint rawRmsPos(ofGetWidth()/3, ofGetHeight()/2);
    ofPoint smoothedRmsPos(ofGetWidth()*2/3, ofGetHeight()/2);
    
    ofDrawCircle(rawRmsPos, vol * ofGetHeight());
    ofDrawCircle(smoothedRmsPos, smoothedVol * ofGetHeight());
    
    ofDrawBitmapStringHighlight("raw rms = " + ofToString(vol), rawRmsPos);
    ofDrawBitmapStringHighlight("smoothed rms = " + ofToString(smoothedVol), smoothedRmsPos);
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
    
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * vol;
}
