#include "ofApp.h"

using namespace glm;

int seed = 0;
bool closed = false;
const int numKeypoints = 15;

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

void drawOpen(vec2 points[]) {
  ofBeginShape();
  ofCurveVertex(points[0]);
  for (int i = 0; i < numKeypoints; i++) {
    ofCurveVertex(points[i]);
  }
  ofCurveVertex(points[numKeypoints-1]);
  ofEndShape();
}

void drawClosed(vec2 points[]) {
  ofBeginShape();
  // Start from the last keypoint
  ofCurveVertex(points[numKeypoints-1]);
  // here we wrap around to end with point 0
  for (int i = 0; i < numKeypoints+1; i++) {
    ofCurveVertex(points[i%numKeypoints]);
  }
  // And then repeat the second point
  ofCurveVertex(points[1]);
  ofEndShape(OF_CLOSE);
}


//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  
  // random seed
  ofSetRandomSeed(seed);
  srand(seed);
  
  vec2 points[numKeypoints];
  
  ofFill();
  ofSetColor(255, 0, 0);
  
  // Initialize and draw keypoints
  if (closed) {
    // Points along a circle
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    float angleStep = TWO_PI/numKeypoints;
    float radius = ofGetHeight()/4;
    for (int i = 0; i < numKeypoints; i++) {
      float r = radius*ofRandom(0.5, 1.5);
      points[i] = vec2(cos(angleStep*i)*r,
                       sin(angleStep*i)*r);
      ofDrawCircle(points[i], 5);
    }
  } else {
    // Draw horizontally spaced points
    float xSpacing = ofGetWidth() / (numKeypoints-1);
    float amp = ofGetHeight()/4;
    float y = ofGetHeight()/2;
    
    for (int i = 0; i < numKeypoints; i++) {
      points[i] = vec2(xSpacing*i, y + ofRandom(-amp, amp));
      ofDrawCircle(points[i], 5);
    }
  }
  
  // Draw interpolation curve
  ofNoFill();
  ofSetLineWidth(2.5);
  ofSetColor(255);
  
  if (closed)
    drawClosed(points);
  else
    drawOpen(points);
  
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == 'a')
    seed--;
  if (key == 'd')
    seed++;
  if (key == 'c')
    closed = !closed;
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
