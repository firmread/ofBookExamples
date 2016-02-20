#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(100);
    
    for(int i=0; i<NBALLS; i++){
        
        int size = (i+1) * 10; // defining the size of each ball based o its place in the array
        int randomX = ofRandom( 0, ofGetWidth() ); //generate a random value bigger than 0 and smaller than our application screen width
        int randomY = ofRandom( 0, ofGetHeight()  ); //generate a random value bigger than 0 and smaller than our application screen height
        
        myBall[i].setup(randomX, randomY, size);
    }


}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i <NBALLS; i++) {
        myBall[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i <NBALLS; i++) {
        myBall[i].draw();
    }

}