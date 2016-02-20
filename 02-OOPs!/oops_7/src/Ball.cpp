#include "Ball.h"

Ball::Ball(){
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
};

void Ball::setup(float _x, float _y, int _dim){
    x = _x;
    y = _y;
    dim = _dim;
    
    speedX = ofRandom(-5, 5);
    speedY = ofRandom(-5, 5);
}


void Ball::update(){
    
    if(x < 0 ){
        x = 0;
        speedX *= -1;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if(y < 0 ){
        y = 0;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x+=speedX;
    y+=speedY;
    
}

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
}
