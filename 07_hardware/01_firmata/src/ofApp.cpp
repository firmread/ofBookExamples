#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    ofBackground(255,0,130);
    
    myArduino.connect("/dev/tty.usbmodemfd121", 57600);
    //myArduino.connect("/dev/ttyUSB0", 57600);
    
    // listen for EInitialized notification. this indicates that
    // the arduino is ready to receive commands and it is safe to
    // call setupArduino()
    ofAddListener(myArduino.EInitialized, this, &ofApp::setupArduino);
    
    bSetupArduino	= false;	// flag so we setup arduino when its ready, you don't need to touch this :)
}

//--------------------------------------------------------------
void ofApp::update(){
    updateArduino();
}
//--------------------------------------------------------------
void ofApp::draw(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:
            myArduino.sendDigital(13, ARD_HIGH);  // turn LED on
            break;
        case OF_KEY_DOWN:
            myArduino.sendDigital(13, ARD_LOW); // turn LED off
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
    
    // remove listener because we don't need it anymore
    ofRemoveListener(myArduino.EInitialized, this, &ofApp::setupArduino);
    myArduino.sendDigitalPinMode(13, ARD_OUTPUT);
    bSetupArduino = true;
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    
    // update the arduino, get any data or messages.
    myArduino.update();
    
    // do not send anything until the arduino has been set up
    if (bSetupArduino) {
        myArduino.sendPwm(6, (int)(128 + 128 * sin(ofGetElapsedTimef())));   // pwm...
        
    }
    
}

