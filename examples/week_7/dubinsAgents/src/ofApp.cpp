#include "ofApp.h"

Agent::Agent(float x, float y) {
  angle = 0.0f;
  target = vec2(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
  pos = vec2(x, y);
  trailIndex = 0;
  speed = 200;
  turningRadius = 30;
  trailLength = 200;
}

void Agent::update(float dt) {
  float angleSpeed = speed / turningRadius;
  vec2 d = target - pos;
  float angleDiff = atan2(d.y, d.x) - angle;
  angleDiff = atan2(sin(angleDiff), cos(angleDiff));
  angleDiff += ofRandom(-0.2, 0.2);
  float angleInc = (angleDiff/fabs(angleDiff))*angleSpeed;
  
  angle += angleInc*dt;
  pos += vec2(cos(angle), sin(angle))*speed*dt;
  
  if (distance(pos, target) < turningRadius) {
    target = vec2(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
  }
  
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

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetCircleResolution(50);
  
  for (int i = 0; i < 50; i++) {
    agents.push_back(Agent(ofRandom(0, ofGetWidth()),
                           ofRandom(0, ofGetHeight())));
  }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  for (int i = 0; i < agents.size(); i++) {
    agents[i].update(0.01);
    agents[i].draw();
  }
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
