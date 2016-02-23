#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    
    int phaseCopies = 5;
    for (int i = 0 ; i< phaseCopies; i++) {
        phases.push_back(0);
    }
    
    updateWaveform(32);
    
    ofSoundStreamSetup(1, 0); // mono output
    
    volume = 0;
    
    frequency = 0;
    frequencyTarget = frequency;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofScopedLock waveformLock(waveformMutex);
    updateWaveform(ofMap(ofGetMouseX(), 0, ofGetWidth(), 3, 64, true));
    frequency = ofLerp(frequency, frequencyTarget, 0.4);
    
    if(ofGetKeyPressed()) {
        volume = ofLerp(volume, 1, 0.8); // jump quickly to 1
    } else {
        volume = ofLerp(volume, 0, 0.1); // fade slowly to 0
    }
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
    
    float t = ofGetElapsedTimef();
    float detune = 5;
    
    
    for(int phaseIndex = 0; phaseIndex < phases.size(); phaseIndex++) {
        float phaseFreq = frequency + ofSignedNoise(phaseIndex, t) * detune;
        float phaseStep = phaseFreq / sampleRate;
        
        for(int i = 0; i < bufferSize * nChannels; i += nChannels) {
            phases[phaseIndex] += phaseStep;
            int waveformIndex = (int)(phases[phaseIndex] * waveform.size()) % waveform.size();
            buffer[i] += waveform[waveformIndex] * volume;
        }
    }
    
    outLine.clear();
    
    for(int i = 0; i < bufferSize * nChannels; i += nChannels) {
        buffer[i] /= phases.size();
        
        outLine.addVertex(ofMap(i, 0, bufferSize - 1, 0, ofGetWidth()),
                          ofMap(buffer[i], -1, 1, 0, ofGetHeight()));
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'z') {
        frequencyTarget = 261.63; // C
    } else if(key == 'x') {
        frequencyTarget = 293.67; // D
    } else if(key == 'c') {
        frequencyTarget = 329.63; // E
    } else if(key == 'v') {
        frequencyTarget = 349.23; // F
    } else if(key == 'b') {
        frequencyTarget = 392.00; // G
    } else if(key == 'n') {
        frequencyTarget = 440.00; // A
    } else if(key == 'm') {
        frequencyTarget = 493.88; // B
    }
}