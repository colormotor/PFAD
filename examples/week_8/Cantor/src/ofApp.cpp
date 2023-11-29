#include "ofApp.h"

float thickness = 20;

void cantor(float x, float y, float length) {
  // Stop recursing if length is < 1
  if (length > 1) {
    // Draw a line of the specified length
    ofDrawLine(x, y, x+length, y);
    // Divide the line into three segments
    length = length/3;
    // Move down and draw the first and third segment
    y = y + thickness*4;
    cantor(x, y, length);
    cantor(x+length*2, y, length);
  }
}

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetLineWidth(thickness);
  cantor(0, thickness, ofGetWidth());
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
