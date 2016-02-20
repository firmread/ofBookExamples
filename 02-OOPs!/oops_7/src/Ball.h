
#pragma once
#include "ofMain.h"

class Ball {
    
    public:
    
        Ball();
        void setup(float _x, float _y, int _dim);
        void update();
        void draw();
    
        float x;
        float y;
        float speedY;
        float speedX;
        int dim;
        ofColor color;

    
    private:

};