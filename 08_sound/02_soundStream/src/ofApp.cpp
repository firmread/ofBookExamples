#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    phase = 0;
    
    ofSoundStreamSettings s;
    s.setOutListener(this);
    s.numOutputChannels = 2;
    ofSoundStreamSetup(s);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer &buffer) {
    for(int i = 0; i < buffer.size(); i += 2) {
        float sample = sin(phase); // generating a sine wave sample
        buffer[i] = sample; // writing to the left channel
        buffer[i + 1] = sample; // writing to the right channel
        phase += 0.05;
    }
}