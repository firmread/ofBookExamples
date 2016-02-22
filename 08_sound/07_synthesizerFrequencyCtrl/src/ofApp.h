#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void updateWaveform(int waveformResolution);
        void audioOut(ofSoundBuffer &buffer);
        void keyPressed(int key);
    
        vector<float> waveform; // this is the lookup table
        double phase;
        float frequency;
        
        ofMutex waveformMutex;
        ofPolyline waveLine;
        ofPolyline outLine;
    
        float volume;
        float frequencyTarget;

};
