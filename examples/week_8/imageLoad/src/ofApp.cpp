#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
  ofImageLoadSettings settings;
  settings.grayscale = true;
  image.load("spock.jpg", settings);
  ofSetWindowShape(image.getWidth(), image.getHeight());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  image.draw(0, 0, ofGetWidth(), ofGetHeight());
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
