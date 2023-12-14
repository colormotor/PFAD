#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetCircleResolution(50);
  // the Spout server just needs a name and it will appear in the list of available servers in apps that support Spout
  sender.init("MyOFApp");
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::sendScreen() {
  int w = ofGetWidth();
  int h = ofGetHeight();
    
  ofTexture tex;
  tex.allocate(w, h, GL_RGBA);
    
  tex.loadScreenData(0, 0, w, h);
  sender.send(tex);
  tex.clear();
}
//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  ofSetColor(255, 0, 0);
  ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 200);
  
  // To send the scren with spout we need a texture so we have a convenience function
  sendScreen();
  
  // This won't appear in the output because we draw it after publishing
  ofSetColor(0, 255, 255);
  ofDrawCircle(0, 0, 30);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

