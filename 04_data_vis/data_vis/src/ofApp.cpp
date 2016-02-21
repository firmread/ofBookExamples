#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    font.load("Quicksand-Bold.otf", 20);
    labelFont.load("Quicksand-Regular.otf", 10);
    
    
    ofBuffer file = ofBufferFromFile("population.tsv");
//    ofLog() << file.getText();
    
    // grab the first line, which is just labels.
//    string nameLine = file.getFirstLine();
    string nameLine = file.getLines().begin().asString();
    
    
//    while (!file.isLastLine()){
//        string line = file.getNextLine();
//        vector < string > split = ofSplitString(line, "\t");
//        popData data;
//        data.year = ofToInt(split[0]);
//        data.ny = ofToInt(split[1]);
//        data.ala = ofToInt(split[2]);
//        data.lou = ofToInt(split[3]);
//        dataPoints.push_back(data);
//    }

    for (auto l: file.getLines()){
        string line = l;
        if (l != file.getLines().begin().asString() && !l.empty()) {
            vector<string> split = ofSplitString(line, "\t");
            popData data;
            data.year = ofToInt(split[0]);
            data.ny = ofToInt(split[1]);
            data.ala = ofToInt(split[2]);
            data.lou = ofToInt(split[3]);
            dataPoints.push_back(data);
        }
    }
    
    // let's find the min and max years, and the max value for the data.
    // years are easy, we know it's the first and last year of the array.
    
    minYear = dataPoints[0].year;
    maxYear = dataPoints[dataPoints.size()-1].year;
    
    // search linearly through the data to find the max value;
    
    maxValue = 0;
    for (int i = 0; i < dataPoints.size(); i++){
        if (dataPoints[i].ny > maxValue){
            maxValue = dataPoints[i].ny;
        }
        if (dataPoints[i].lou > maxValue){
            maxValue = dataPoints[i].ala;
        }
        if (dataPoints[i].ala > maxValue){
            maxValue = dataPoints[i].lou;
        }
    }
    
    // let's round up to the next "10" on the max value
    maxValue = ceil(maxValue / 10) * 10;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    dimensions.x = ofGetWidth()/10;
    dimensions.y = ofGetHeight()/10;
    dimensions.width = ofGetWidth()*8/10;
    dimensions.height = ofGetHeight()*8/10;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(255, 80);
    
    ofSetColor(255,150);
    ofDrawRectangle(dimensions.x, dimensions.y, dimensions.width, dimensions.height);
    
    for (int i = 0; i < dataPoints.size(); i++){
        
        float value;
        if (which == 0) value = dataPoints[i].ny;
        if (which == 1) value = dataPoints[i].ala;
        if (which == 2) value = dataPoints[i].lou;
        
        float x = dimensions.x + ofMap( dataPoints[i].year, minYear, maxYear, 0,dimensions.width);
        float y = dimensions.y + ofMap( value, 0, maxValue, dimensions.height, 0);
        
        
        ofSetColor(ofColor::green);
        ofDrawCircle(x,y, 5);
        
        ofSetColor(255);
        labelFont.drawString(ofToString(dataPoints[i].year), x, dimensions.y+dimensions.height+15);
    }
    
    if (which == 0) ofSetColor(ofColor::salmon);
    else ofSetColor(255);
    font.drawString("New York", dimensions.x, dimensions.y-15);
    
    if (which == 1) ofSetColor(ofColor::salmon);
    else ofSetColor(255);
    font.drawString("Alabama", dimensions.x + 160, dimensions.y-15);
    
    if (which == 2) ofSetColor(ofColor::salmon);
    else ofSetColor(255);
    font.drawString("Louisana", dimensions.x + 320, dimensions.y-15);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    ofRectangle rect = font.getStringBoundingBox("NewYork", dimensions.x, dimensions.y-15);
    if (rect.inside(ofPoint(x,y))){
        which = 0;
    }
    
    rect = font.getStringBoundingBox("Alabama", dimensions.x + 160, dimensions.y-15);
    if (rect.inside(ofPoint(x,y))){
        which = 1;
    }
    
    rect = font.getStringBoundingBox("Louisiana", dimensions.x + 320, dimensions.y-15);
    if (rect.inside(ofPoint(x,y))){
        which = 2;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
