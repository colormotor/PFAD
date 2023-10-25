#include "ofApp.h"

using namespace glm;
const int numPoints = 10;

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
  
  ofBackground(255);
  ofNoFill();
  ofSetColor(0);
  
  float xSpacing = 5; //the distance that the verticle lines are apart
  float ySpacing = (float)height / (numPoints-1); //the distance between points on a line
  // initial pen position

  vec2 line[numPoints];
  
  // points for the first (hidden) line
  for (int i = 0; i < numPoints; i++) {
    line[i] = vec2(-xSpacing, i*ySpacing);
  }

  srand(100);
  float x = 0.0;
  float offsetAmt = 0.9; //ofMap(mouseX, 0, width, -2.0, 2.0);
  while (x < width) {
    // Compute line points
    for (int i = 0; i < numPoints; i++) {
      float xoffset = ofRandom(-1, 1)*xSpacing*offsetAmt;
      line[i] = line[i] + vec2(xSpacing + xoffset, 0);
    }
    // Draw line
    // repeating the first and last vertex makes the curve reach the end
    ofBeginShape();
    ofCurveVertex(line[0]);
    for (int i = 0; i < numPoints; i++) {
      ofCurveVertex(line[i]);
    }
    ofCurveVertex(line[numPoints-1]);
    ofEndShape();
    
    x += xSpacing;
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
