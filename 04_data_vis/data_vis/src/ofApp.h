#pragma once
#include "ofMain.h"

typedef struct {
    
    int year;
    int ny;
    int lou;
    int ala;
    
} popData;


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector < popData > dataPoints;
    
    int minYear;
    int maxYear;
    float maxValue;
    
    ofRectangle dimensions;
    
    int which;
    
    ofTrueTypeFont font;
    ofTrueTypeFont labelFont;

};
