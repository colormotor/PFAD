#pragma once
#include "ofMain.h"

using namespace glm;

class SimpleParticle{

	public:
        //member functions
		SimpleParticle(vec2 _location);
    void update();
    bool isDead();
    void applyForce(vec2 f);

    //member variables
    string partStr;
    vec2 loc;
    vec2 vel;
    vec2 accel;
    float lifespan;
    float agingRate;
    ofColor color;
    int radius;
};
