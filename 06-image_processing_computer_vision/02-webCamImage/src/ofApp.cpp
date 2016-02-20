// Example 2. An application to capture, invert,
// and display live video from a webcam.

#include "ofApp.h"

void ofApp::setup(){
    
    // Set capture dimensions of 320x240, a common video size.
    camWidth = 320;
    camHeight = 240;
    
    // Open an ofVideoGrabber for the default camera
    myVideoGrabber.initGrabber (camWidth,camHeight);
    
    // Create resources to store and display another copy of the data
    invertedVideoData = new unsigned char [camWidth * camHeight * 3];
    myTexture.allocate (camWidth,camHeight, GL_RGB);
}

void ofApp::update(){
    
    // Ask the grabber to refresh its data.
    myVideoGrabber.update();
    
    // If the grabber indeed has fresh data,
    if(myVideoGrabber.isFrameNew()){
        
        // Obtain a pointer to the grabber's image data.
        unsigned char* pixelData = myVideoGrabber.getPixels().getData();
        
        // Reckon the total number of bytes to examine.
        // This is the image's width times its height,
        // times 3 -- because each pixel requires 3 bytes
        // to store its R, G, and B color components.
        int nTotalBytes = camWidth * camHeight * 3;
        
        // For every byte of the RGB image data,
        for(int i=0; i<nTotalBytes; i++){
            
            // pixelData[i] is the i'th byte of the image;
            // subtract it from 255, to make a "photo negative"
            invertedVideoData[i] = 255 - pixelData[i];
        }
        
        // Now stash the inverted data in an ofTexture
        myTexture.loadData (invertedVideoData, camWidth,camHeight, GL_RGB);
    }
}

void ofApp::draw(){
    ofBackground(100,100,100);
    ofSetColor(255,255,255);
    
    // Draw the grabber, and next to it, the "negative" ofTexture.
    myVideoGrabber.draw(10,10);
    myTexture.draw(340, 10);
}