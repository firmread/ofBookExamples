
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);

    // Set some colors for us to use.  They are slighty transparent,
    // so that we can see shapes even if they overlap
    ofColor blueColor(50, 187, 250, 200);
    ofColor purpleColor(231, 49, 247, 200);

    // Loop to draw a grid
    for (int rows=0; rows<4; rows++) {

        ofPushMatrix(); // Save the coordinate system before we shift it horizontally
            // It is often helpful to indent any code in-between push and pop matrix for readability

            // Loop and draw a row within the grid
            for (int cols=0; cols<7; cols++) {

                // Draw the stick figure family
                ofSetColor(blueColor);
                ofDrawCircle(30, 30, 30);
                ofDrawRectangle(5, 70, 50, 100);
                ofSetColor(blueColor);
                ofDrawCircle(95, 30, 30);
                ofDrawRectangle(70, 70, 50, 100);
                ofSetColor(purpleColor);
                ofDrawCircle(45, 90, 15);
                ofDrawRectangle(30, 110, 30, 60);
                ofSetColor(purpleColor);
                ofDrawCircle(80, 90, 15);
                ofDrawRectangle(65, 110, 30, 60);

                ofTranslate(150, 0); // Shift horizontally
            }

        ofPopMatrix(); // Return to the coordinate system before we shifted it horizontally
        ofTranslate(0, 200); // Shift vertically
    }
}
