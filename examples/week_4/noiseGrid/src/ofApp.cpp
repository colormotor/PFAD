#include "ofApp.h"

using namespace glm;

const int numX=25; // const means it is constant (cannot change it). We need this so we can initialize an array with it
const int numY=25;

int spacingX, spacingY;
int startingX, startingY;

float stepSize;
float noiseSeeds[numY][numX]; //a 2D array -> size given at compile time

double t = 0.0;

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  
  spacingX = ofGetWidth() / numX;
  spacingY = ofGetHeight() / numY;

  startingX = spacingX / 2;
  startingY = spacingY / 2;

  stepSize = 20;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  int n = numY*numX;
  vec2 gridPoints[n];
  
  ofSetColor(255);
  
  float freq = 0.79;
  int k = 0;
  for (int i = 0; i < numY; i++) {
    for (int j =0 ; j < numX; j++) {
      vec2 pos = vec2(startingX + spacingX * j,
                      startingY + spacingY * i);
      // Move diagonally along 2d noise
      float angle = ofSignedNoise(pos.x * freq + t, pos.y * freq + t)*PI;
      // Offset the points
      vec2 offsetPos = pos + vec2(cos(angle)*stepSize,
                                  sin(angle)*stepSize);
      ofDrawCircle(offsetPos, 2);
      gridPoints[k] = offsetPos;
      k++;
    }
  }
  
  // Draw lines between close points
  ofSetColor(255, 180);
  for (int i = 0; i < n; i++) {
    for (int j = i ; j < n; j++) {
      if (distance(gridPoints[i], gridPoints[j]) < spacingX*0.75) {
        ofDrawLine(gridPoints[i], gridPoints[j]);
      }
    }
  }
  
  t += 0.001;
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
