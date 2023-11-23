#include "Agent.h"

float angleBetween(const vec2& a, const vec2& b) {
  return atan2( a.x*b.y - a.y*b.x,
                a.x*b.x + a.y*b.y );
}

Agent::Agent(float x, float y) {
  angle = 0.0;
  target = vec2(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
  pos = vec2(x, y);
  trailIndex = 0;
  speed = 200;
  turningRadius = 30;
  trailLength = 200;
}

void Agent::update(float dt) {
  float angleSpeed = speed / turningRadius;
  
  vec2 direction = target - pos;
  
  float angleDiff = angleBetween(vec2(cos(angle), sin(angle)), direction);
  angleDiff += ofRandom(-0.2, 0.2);
  float angleInc = (angleDiff/fabs(angleDiff))*angleSpeed;
    
  angle += angleInc*dt;
  pos += vec2(cos(angle), sin(angle))*speed*dt;
  
  if (distance(pos, target) < turningRadius) {
    target = vec2(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
  }
  
  updateTrail(pos);
}

void Agent::updateTrail(const vec2& p) {
  if (trail.size() < trailLength) {
    // Before the trail is full just add positions
    trail.push_back(pos);
  }else{
    // When the trail is full we will "wrap" it using modulo
    // we add a new position at the current trailIndex modulo the length, this means that for trailIndex=0 we index 0 and also every multiple of trailLength, trailIndex%trailLength is again 0
    trail[trailIndex%trailLength] = pos;
    // so now we start reading the array from the next element with the previous trail
    trailIndex += 1;
  }
}

void Agent::drawTrail() {
  int n = trail.size();
  // for drawing we will start start counting from "trailIndex" and use modulo again to wrap
  for (int i = 0; i < n; i++) {
    vec2 pos = trail[(i + trailIndex)%n];
    float r = 0.1*i;
    ofFill();
    ofSetColor(255);
    ofDrawCircle(pos, r);
    ofNoFill();
    ofSetColor(0, 128);
    ofDrawCircle(pos, r);
  }
}

void Agent::draw() {
  ofSetColor(255);
  ofDrawCircle(pos, 5);
}
