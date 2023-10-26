#include "ofApp.h"

using namespace glm;

const int numKeypoints = 15;

// Octave noise parameters
float noiseScale = 0.01;
int octaves = 1;
float t = 0.0; // noise phase

// 2d noise with phase on y
float noise2(const vec2& p) {
  float n = 0.0;
  float amplitude = 1.0;
  float frequency = 1.0;
  float normalization = 0.0;
  for (int i = 0; i < octaves; i++) {
    n += ofSignedNoise(p.x*frequency, p.y*frequency + t)*amplitude;
    normalization += amplitude;
    amplitude /= 2;
    frequency *= 2;
  }
  return n/normalization;
}

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
  
  vec2 points[numKeypoints];
  
  ofNoFill();
  ofSetColor(255, 128);
  
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  
  int numCircles = 140;
  float layoutRadius = ofGetHeight()/4;
  
  for (int i = 0; i < numCircles; i++) {
    float angle = (TWO_PI / numCircles) * i;
    vec2 center = vec2(cos(angle)*layoutRadius,
                       sin(angle)*layoutRadius);
    
    float angleStep = TWO_PI/numKeypoints;
    float radius = layoutRadius*0.5;
    for (int j = 0; j < numKeypoints; j++) {
      vec2 circlePoint = center + vec2(cos(angleStep*j)*radius,
                                       sin(angleStep*j)*radius);
      float offset = ofMap(noise2(circlePoint*noiseScale), -1, 1, 0.8, 1.2);
      
      points[j] = center + vec2(cos(angleStep*j)*radius*offset,
                                sin(angleStep*j)*radius*offset);
    }
    drawClosed(points);
  }
  
  t += 0.01;
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == OF_KEY_RETURN) {
    svg.save("circles.svg");
  }
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
