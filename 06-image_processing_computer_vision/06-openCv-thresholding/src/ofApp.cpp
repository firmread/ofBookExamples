// Example 6: Thresholding
#include "ofApp.h"

//---------------------
void ofApp::setup(){
    
    // Load the cells image
    ofImage cellsOfImage;
    cellsOfImage.load("cells.png");
    cellsOfImage.setImageType(OF_IMAGE_GRAYSCALE);
    
    // Set the myCvImageSrc from the pixels of this ofImage.
    int imgW = cellsOfImage.getWidth();
    int imgH = cellsOfImage.getHeight();
    unsigned char *cellsPixels = cellsOfImage.getPixels().getData();
    myCvImageSrc.setFromPixels (cellsPixels, imgW, imgH);
}

//---------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255);
    
    // Copy the source image into the destination:
    myCvImageDst = myCvImageSrc;
    
    // Threshold the destination image.
    // Our threshold value is the mouseX,
    // but it could be a constant, like 127.
    myCvImageDst.threshold(mouseX);
    
    myCvImageSrc.draw ( 20,20,  320,240);
    myCvImageDst.draw (360,20,  320,240);
}