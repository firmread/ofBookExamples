#pragma once

#include "ofMain.h"

class Line {
public:
	ofPoint a;
	ofPoint b;
};

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	
	vector < ofPoint > drawnPoints;
	vector < Line > lines;
};
