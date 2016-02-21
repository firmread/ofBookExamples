#include "ofApp.h"

void ofApp::setup(){
    // We load an image from our "data" folder into the ofImage:
    myImage.load("lincoln.png");
    myImage.setImageType(OF_IMAGE_GRAYSCALE);
}

void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255);
    
    // We fetch the ofImage's dimensions and display it 10x larger.
    int imgWidth = myImage.getWidth();
    int imgHeight = myImage.getHeight();
    myImage.draw(10, 10, imgWidth * 10, imgHeight * 10);
}