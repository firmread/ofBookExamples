#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    soundPlayer.load("song.mp3");
    soundPlayer.play();
    speed = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
    soundPlayer.setSpeed(speed);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapStringHighlight("speed = " + ofToString(speed), 20,20);
    
    string s = "press ' ' to play sound\n";
    s+= "press 'a' to play sound at speed = 1\n";
    s+= "press 's' to play sound at random speed between 0.8 - 1.2\n";
    s+= "drag mouse in X axis to shift speed";
    ofDrawBitmapStringHighlight(s, 20, ofGetHeight()-50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        soundPlayer.play();
    }
    if (key == 'a'){
        speed = 1;
        soundPlayer.play();
    }
    if( key == 's' ) {
        speed = ofRandom(0.8, 1.2);
        soundPlayer.play();
    }
}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    speed = ofMap(x, 0, ofGetWidth(), 0.5, 3.0, true);
}