#include "ofApp.h"

// Octave noise parameters
float noiseScale = 0.006;
int octaves = 1;
float t = 0.0;

// We use 2d noise, so we can "slice" along one axis resulting in an animation
float noise2(float x, float y) {
  float n = 0.0;
  float amplitude = 1.0;
  float frequency = 1.0;
  float normalization = 0.0;
  for (int i = 0; i < octaves; i++) {
    n += ofSignedNoise(x*frequency, y*frequency)*amplitude;
    normalization += amplitude;
    amplitude /= 2;
    frequency *= 2;
  }
  return n/normalization;
}

float noise(float x) {
  float n = 0.0;
  float amplitude = 1.0;
  float frequency = 1.0;
  float normalization = 0.0;
  for (int i = 0; i < octaves; i++) {
    n += ofSignedNoise(x*frequency)*amplitude;
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

//--------------------------------------------------------------
void ofApp::draw(){
  float amp = ofGetHeight()/4;
  
  ofNoFill();
  ofSetColor(255);
  ofBeginShape();
  for (float x = 0; x < ofGetWidth(); x+=2) {
    // This gives the impression of travelling along an infinite landscape
//    float y = ofGetHeight()/2 + noise(x*noiseScale + t)*amp;
    // This gives an animation
    float y = ofGetHeight()/2 + noise2(x*noiseScale, t)*amp;
    ofVertex(x, y);
  }
  ofEndShape();
  
  t += noiseScale;
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
