#pragma once // Include this file only once
#include "ofMain.h"

using namespace glm;

struct Agent {
  Agent(float x, float y);
  void update(float dt);
  void draw();
  
  void updateTrail(const vec2& pos);
  void drawTrail();
  
  vector<vec2> trail;
  int trailIndex;
  int trailLength;
  
  vec2 target;
  vec2 pos;
  
  float angle;
    
  float speed;
  float turningRadius;
  
};
