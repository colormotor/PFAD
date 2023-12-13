#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetCircleResolution(50);
  // the Syphon server just needs a name and it will appear in the list of available servers in apps that support Syphon
  syphonServer.setName("MyOFApp");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  ofSetColor(255, 0, 0);
  ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 200);
  
  // This will send all the contents of the current window to syphon
  syphonServer.publishScreen();
  
  // This won't appear in the output because we draw it after publishing
  ofSetColor(0, 255, 255);
  ofDrawCircle(0, 0, 30);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

