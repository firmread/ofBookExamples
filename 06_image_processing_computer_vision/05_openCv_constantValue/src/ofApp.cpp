// Example 5: Add a constant value to an image, with ofxOpenCv.
// This is ofApp.cpp
#include "ofApp.h"

void ofApp::setup(){
    
    // ofxOpenCV doesn't have image loading.
    // So first, load the .png file into a temporary ofImage.
    ofImage lincolnOfImage;
    lincolnOfImage.load("lincoln_120x160.png");
    lincolnOfImage.setImageType(OF_IMAGE_GRAYSCALE);
    
    // Set the lincolnCvImage from the pixels of this ofImage.
    int imgW = lincolnOfImage.getWidth();
    int imgH = lincolnOfImage.getHeight();
    unsigned char *lincolnPixels = lincolnOfImage.getPixels().getData();
    lincolnCvImageSrc.setFromPixels( lincolnPixels, imgW, imgH);
    
    // Make a copy of the source image into the destination.
    lincolnCvImageDst = lincolnCvImageSrc;
    
    // ofxOpenCV has handy operators for in-place image arithmetic.
    lincolnCvImageDst += 60;
}

//---------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255);
    
    lincolnCvImageSrc.draw ( 20,20, 120,160);
    lincolnCvImageDst.draw (160,20, 120,160);
}