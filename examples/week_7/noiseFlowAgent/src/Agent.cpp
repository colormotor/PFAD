#include "Agent.h"

// Direction of noise flow given x and y position
vec2 noiseFlow(const vec2& pos, float noiseScale, float t) {
  // Get slice of noise based on x, y and t parameter
  float noiseVal = ofSignedNoise(pos.x * noiseScale, pos.y * noiseScale, t);
  
  // Get value of noise between -1 and 1 and convert to an angle
  // (between -PI and PI)
  float angle = noiseVal*PI;
  // Convert angle to a unit vector by getting point on circle
  return vec2(cos(angle), sin(angle));
}

// declare static variables. These are available to the class
// but act like global variables
float Agent::t = 0.0;
float Agent::maxSpeed = 200;
float Agent::maxForce = 1000;
float Agent::noiseScale = 0.0063;

Agent::Agent(const vec2& pos_, const ofColor& color_) {
  target = vec2(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
  pos = pos_;
  color = color_;
  trailIndex = 0;
  trailLength = 200;
  velocity = vec2(1, 0); //vec2(ofRandom(-1,1))
}

vec2 Agent::steerForce(const vec2& desiredVelocity) {
  return vec2(0, 0);
}

void Agent::wrapBounds() {
  const float margin = 35;
  float width = ofGetWidth();
  float height = ofGetHeight();

  color = ofColor(255);
  
  if (pos.x < -margin) {
    pos.x = width + margin;
  }
  if (pos.x > width + margin) {
    pos.x = -margin;
  }
  if (pos.y < -margin) {
    pos.y = height + margin;
  }
  if (pos.y > height + margin) {
    pos.y = -margin;
  }
  
}

void Agent::update(float dt) {
  
  vec2 desiredVelocity = noiseFlow(pos, noiseScale, t)*maxSpeed;
  
  vec2 accel = steerForce(desiredVelocity);
  velocity += accel*dt;
  
  if (length(velocity) > maxSpeed) {
    velocity = normalize(velocity)*maxSpeed;
  }
  pos += velocity*dt;
  
  wrapBounds();

  // Uncomment to draw trails
  // updateTrail(pos);
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

void Agent::draw() {
  ofSetColor(color);
  ofDrawCircle(pos, 5);
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

// This function is static
// (we do not need an Agent instance to use it)
void Agent::drawFlowField() {
  // Flow field draw
  ofNoFill();
  ofSetColor(0, 190, 255, 150);
  ofSetLineWidth(2);
  int step = 10;
  float width = ofGetWidth();
  float height = ofGetHeight();
  for (float y = 0; y < height; y+=step) {
    for (float x = 0; x < width; x+=step) {
      vec2 flow = noiseFlow(vec2(x, y),
                            noiseScale,
                            t);
      ofDrawLine(x, y, x+flow.x*step, y+flow.y*step);
    }
  }
}
