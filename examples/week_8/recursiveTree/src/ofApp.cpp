#include "ofApp.h"


void branch(float length, float angle) {
  if(length > 5 )
  //when the branch gets too short stop drawing
  {
    ofDrawLine(0,0,0,-length);
    ofTranslate(0,-length);
    
    ofPushMatrix();
    ofRotateDeg(angle); //rotate the branch in one direction
    branch(length * 0.7, angle); //recursive function call
    ofPopMatrix();

    ofPushMatrix();
    ofRotateDeg(-angle); //rotate the branch in the other direction
    branch(length * 0.7, -angle); //recursive function call
    ofPopMatrix();
  }
}


//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255);
  ofSetColor(0);
  ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofTranslate(ofGetWidth()/2, ofGetHeight() * 0.75);
  branch(100, mouseX/10);
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
