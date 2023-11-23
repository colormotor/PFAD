#pragma once
#include "ofMain.h"

using namespace glm;

struct Agent {
  Agent(const vec2& pos_, const ofColor& color_);
  void update(float dt);
  void draw();
  void updateTrail(const vec2& pos);
  void drawTrail();
  vec2 steerForce(const vec2& desiredVelocity);
  void wrapBounds();
  
  // This function is global, it used with Agent::drawFlowField()
  static void drawFlowField();
  
  vector<vec2> trail;
  int trailLength;
  int trailIndex;
  
  vec2 target;
  vec2 pos;
  vec2 velocity;
  ofColor color;

  // These variables are global
  static float t;
  static float maxSpeed;
  static float maxForce;
  static float noiseScale;
};
