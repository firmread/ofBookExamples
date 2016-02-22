#include "ofApp.h"

#define RECONNECT_TIME 400

//--------------------------------------------------------------
void ofApp::setup(){
	// we don't want to be running to fast
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

    //create the socket and set to send to 127.0.0.1:11999
	udpConnection.Create();
	udpConnection.Connect("127.0.0.1",11999);
	udpConnection.SetNonBlocking(true);


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(20);
	for(unsigned int i=1;i<stroke.size();i++){
		ofDrawLine(stroke[i-1].x,stroke[i-1].y,stroke[i].x,stroke[i].y);
	}
    
    string s = "openFrameworks UDP Send Example\n";
    s += "drag to draw";
    ofDrawBitmapStringHighlight(s, 15, 30);
    
}


//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	stroke.push_back(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	stroke.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	string message="";
	for(unsigned int i=0; i<stroke.size(); i++){
		message+=ofToString(stroke[i].x)+"|"+ofToString(stroke[i].y)+"[/p]";
	}
	udpConnection.Send(message.c_str(),message.length());
}
