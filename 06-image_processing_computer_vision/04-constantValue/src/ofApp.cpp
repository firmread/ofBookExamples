// Example 4. Add a constant value to an image.
// This is ofApp.cpp
#include "ofApp.h"

void ofApp::setup(){
    
    // Load the image and ensure we're working in monochrome.
    // This is our source ("src") image.
    lincolnOfImageSrc.load("lincoln_120x160.png");
    lincolnOfImageSrc.setImageType(OF_IMAGE_GRAYSCALE);
    
    // Construct and allocate a new image with the same dimensions.
    // This will store our destination ("dst") image.
    int imgW = lincolnOfImageSrc.getWidth();
    int imgH = lincolnOfImageSrc.getHeight();
    lincolnOfImageDst.allocate(imgW, imgH, OF_IMAGE_GRAYSCALE);
    
    // Acquire pointers to the pixel buffers of both images.
    // These images use 8-bit unsigned chars to store gray values.
    // Note the convention 'src' and 'dst' -- this is very common.
    unsigned char* srcArray = lincolnOfImageSrc.getPixels().getData();
    unsigned char* dstArray = lincolnOfImageDst.getPixels().getData();
    
    // Loop over all of the destination image's pixels.
    // Each destination pixel will be 10 gray-levels brighter
    // than its corresponding source pixel.
    int nPixels = imgW * imgH;
    for(int i=0; i<nPixels; i++) {
        unsigned char srcValue = srcArray[i];
        dstArray[i] = srcValue + 10;
    }
    
    // Don't forget this!
    // We tell the ofImage to refresh its texture (stored on the GPU)
    // from its pixel buffer (stored on the CPU), which we have modified.
    lincolnOfImageDst.update();
}

//---------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255);
    
    lincolnOfImageSrc.draw ( 20,20, 120,160);
    lincolnOfImageDst.draw (160,20, 120,160);
}