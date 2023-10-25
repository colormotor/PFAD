#include "ofApp.h"

using namespace glm;

// Octave noise parameters
float noiseScale = 0.005;
int octaves = 4;
float t = 0.0;

// We use 3d noise, so we "slice" along the noise volume resulting
// in an animated flow field
float noise(float x, float y, float z) {
  float n = 0.0;
  float amplitude = 1.0;
  float frequency = 1.0;
  float normalization = 0.0;
  for (int i = 0; i < octaves; i++) {
    n += ofSignedNoise(x*frequency, y*frequency, z*frequency)*amplitude;
    normalization += amplitude;
    amplitude /= 2;
    frequency *= 2;
  }
  return n/normalization;
}

// Direction of noise flow given x and y position
vec2 noiseFlow(float x, float y) {
  // Get slice of noise based on x, y and t parameter
  float noiseVal = noise(x * noiseScale, y * noiseScale, t);
  float angle = noiseVal*PI;
  return vec2(cos(angle), sin(angle));
}

// Direction going outwards from center (assuming origin at center)
vec2 outerFlow(float x, float y) {
  return normalize(vec2(x, y));
}

// Direction going in circles (assuming origin at center)
vec2 circularFlow(float x, float y) {
  return normalize(vec2(-y, x));
}

// Use this to combine different flow fields
vec2 flowAt(float x, float y) {
  return circularFlow(x, y) + noiseFlow(x, y)*0.5 + outerFlow(x, y)*0.2;
}


//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){

}


//--------------------------------------------------------------
void ofApp::draw(){
  int width = ofGetWidth();
  int height = ofGetHeight();
  
  // Center origin
  ofTranslate(width/2, height/2);
  
  ofBackground(0);
  ofNoFill();
  ofSetColor(0, 190, 255, 150);
  ofSetLineWidth(2);
  int step = 10;
  
  for (float y = -height/2; y < height/2; y+=step) {
    for (float x = -width/2; x < width/2; x+=step) {
      vec2 flow = flowAt(x, y);
      ofDrawLine(x, y, x+flow.x*20, y+flow.y*20);
    }
  }
  
  t += 0.01;
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
