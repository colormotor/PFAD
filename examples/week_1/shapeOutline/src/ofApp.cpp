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
  ofBackground(0);
  ofFill();               // explain result when I remove this line
  ofSetColor(255,0,0);
  ofDrawCircle(400,400,150);
  ofNoFill();
  ofSetColor(255);
  ofSetLineWidth(5);
  ofDrawCircle(400,400,200);
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
