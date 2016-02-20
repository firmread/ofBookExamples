#pragma once
#include "ofMain.h"
#include "particle.h"

class spring {
	public:
		particle * particleA;
		particle * particleB;

		spring();
		
		float distance;
		float springiness;	 // this is the k, springiness constant
		void update();
		void draw();
};
