#include "ofApp.h"

using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetCircleResolution(100);
  palette.load("palette.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  int seed = 132;
  ofSetRandomSeed(seed);
  srand(seed);
  
  // This is our vertical position along the palette between 0 and 1
  // move the mouse horizontally to vary it
  float paletteY = ofMap(mouseX, 0, ofGetWidth(), 0, 1, true);
  
  float noiseScale = 0.01;
  for (int i = 0; i < 100; i++) {
    vec2 pos = vec2(ofRandom(0, ofGetWidth()),
                    ofRandom(0, ofGetHeight()));
    // Use random xy position to sample some noise and animate with
    // t as an increasing third noise coordinate
    float paletteX = ofNoise(pos.x*noiseScale,
                          pos.y*noiseScale,
                          t);
    // pick a color from the palette based on the noise and then draw it
    ofColor color = palette.color(paletteX, paletteY);
    ofSetColor(color);
    ofDrawCircle(pos, 50);
  }
  
  t += noiseScale;
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}
