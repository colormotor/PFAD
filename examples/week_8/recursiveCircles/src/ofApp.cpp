#include "ofApp.h"

using namespace glm;

void drawRecursive(const vec2& pos, float radius, float rotation, float hue) {
  ofColor color;
  color.setHsb(hue, 255, 255);
  ofSetColor(color);
  ofPushMatrix();
  ofTranslate(pos);
  ofRotateDeg(rotation);
  ofDrawCircle(0, 0, radius*0.5);
  
  if (radius > 10) {
    hue = hue*0.9;
    drawRecursive(vec2(radius, 0), radius-20, rotation, hue);
    drawRecursive(vec2(-radius, 0), radius-20, rotation, hue);
    drawRecursive(vec2(0, radius), radius-20, rotation, hue);
    drawRecursive(vec2(0, -radius), radius-20, rotation, hue);
  }
  ofPopMatrix();

}

void recursive(int n) {
  cout << "my input is " << n << endl;
  if (n >= 0) {
    recursive(n-1);
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
  ofBackground(0);
  ofSetLineWidth(3);
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  float rotation = ofMap(mouseX, 0, ofGetWidth(), -180, 180);
  ofNoFill();
  drawRecursive(vec2(0, 0), 100, rotation, 255);
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
