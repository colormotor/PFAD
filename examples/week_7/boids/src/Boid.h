#pragma once
#include "ofMain.h"

using namespace glm;

class Boid{
public:
    Boid(int index_, const vec2& pos_, const ofColor& color_);
    
    void draw();
    void update(const vector<Boid>& boids, //vector<Boid> boids, //const vector<Boid>& boids,const vector<Boid>& boids,
                float speedlimit,
                float separationFactor,
                float cohesionFactor,
                float alignmentFactor,
                float checkdist,
                float bouncespeed,
                float dt);
  
private:
    void checkBoundary(float speed);
    void flock(const vector<Boid>& boids, //vector<Boid> boids, //const vector<Boid>& boids,const vector<Boid>& boids,
               float separationFactor,
               float cohesionFactor,
               float alignmentFactor,
               float checkdist);
    
    vec2 velocity;
    vec2 position;
    float distToCheck;
    ofColor color;
    int index;
};
