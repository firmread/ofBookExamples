#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    
    phase = 0;
    updateWaveform(32);

    ofSoundStreamSettings s;
    s.setOutListener(this);
    s.numOutputChannels = 1; // mono output
    ofSoundStreamSetup(s);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofScopedLock waveformLock(waveformMutex);
    updateWaveform(ofMap(ofGetMouseX(), 0, ofGetWidth(), 3, 64, true));
    frequency = ofMap(ofGetMouseY(), 0, ofGetHeight(), 60, 700, true);
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::black);
    ofSetLineWidth(5);
    ofSetColor(ofColor::lightGreen);
    outLine.draw();
    ofSetColor(ofColor::cyan);
    waveLine.draw();
}
//--------------------------------------------------------------
void ofApp::updateWaveform(int waveformResolution) {
    waveform.resize(waveformResolution);
    waveLine.clear();
    
    // "waveformStep" maps a full oscillation of sin() to the size
    // of the waveform lookup table
    float waveformStep = (M_PI * 2.) / (float) waveform.size();
    
    for(int i = 0; i < waveform.size(); i++) {
        waveform[i] = sin(i * waveformStep);
//        waveform[i] = ofSignedNoise(i * waveformStep, ofGetElapsedTimef());
        
        
        waveLine.addVertex(ofMap(i, 0, waveform.size() - 1, 0, ofGetWidth()),
                           ofMap(waveform[i], -1, 1, 0, ofGetHeight()));
    }
}
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer &buffer) {
    ofScopedLock waveformLock(waveformMutex);
    
    float sampleRate = 44100;
    float phaseStep = frequency / sampleRate;
    int bufferSize = buffer.getBuffer().size();
    int nChannels = buffer.getNumChannels();
    
    outLine.clear();
    
    for(int i = 0; i < bufferSize * nChannels; i += nChannels) {
        phase += phaseStep;
        int waveformIndex = (int)(phase * waveform.size()) % waveform.size();
        buffer[i] = waveform[waveformIndex];
        
        outLine.addVertex(ofMap(i, 0, bufferSize - 1, 0, ofGetWidth()),
                          ofMap(buffer[i], -1, 1, 0, ofGetHeight()));
    }
}