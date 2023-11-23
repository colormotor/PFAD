#include "ofApp.h"

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
float Agent::maxSpeed = 200; //500;
float Agent::maxForce = 1000; //0.1; //1000;
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
  vec2 force = desiredVelocity - velocity;
  if (length(force) > 0) {
    force = normalize(force)*maxForce;
  }
  return force;
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
  
//  vec2 desiredDirection = noiseFlow(pos, noiseScale, t);
//  vec2 direction = desiredDirection - velocity;
//
//  float directionMag = length(direction);
//  //we have to make sure that we aren't try to normalize a vector with no length
//  if(directionMag > 0){
//      direction = normalize(direction);
//  }
//
//  velocity += direction * force;
  
  const float margin = 5;
  float turnFactor = 10;
  float width = ofGetWidth();
  float height = ofGetHeight();

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
  
  // Uncomment to draw current target
//  ofFill();
//  ofSetColor(255, 0, 0, 50);
//  ofDrawCircle(target, 20);
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

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetCircleResolution(50);
  
  for (int i = 0; i < 103; i++) {
    agents.push_back(Agent(vec2(ofRandom(0, ofGetWidth()),
                                ofRandom(0, ofGetHeight())),
                           ofColor(255)));
  }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  
  agents[0].drawFlowField();
  
  ofFill();
  float dt = 0.01;
  for (int i = 0; i < agents.size(); i++) {
    agents[i].update(dt);
    agents[i].draw();
    agents[i].drawTrail();
  }
  // Update static time variable,
  // this way it is accessible here and inside the Agent class
  Agent::t += dt;
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
