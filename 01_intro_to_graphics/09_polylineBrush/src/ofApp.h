
#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
    
        bool leftMouseButtonPressed;
        float minDistance;
        ofVec2f lastPoint;
        ofPolyline currentPolyline;
		vector <ofPolyline> polylines;

};
