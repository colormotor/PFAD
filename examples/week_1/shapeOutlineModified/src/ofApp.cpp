#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(70);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0); // black
  
  ofFill();  // fill everything from now on
  ofSetColor(255, 0, 0);
  ofDrawCircle(200, 200, 100);
  ofDrawRectangle(400, 400, 200, 50);
  
  ofNoFill(); // outline everything from now
  ofSetColor(255);
  ofSetLineWidth(5);
  ofDrawCircle(200, 200, 100);
  ofDrawRectangle(200, 300, 200, 50);
  
  ofFill();  // fill everything from now on
  ofBeginShape();
  ofVertex(0,0);
  ofVertex(mouseX, mouseY);
  ofVertex(200, 50);
  ofEndShape();
  
  ofDrawLine(600, 0, mouseX, mouseY);
  
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  // user pressed a key
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  // user released a key
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
