#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
  
  ofImageLoadSettings settings;
  settings.grayscale = false;
  image.load("spock.jpg", settings);

  ofSetWindowShape(image.getWidth(), image.getHeight());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(255);
  image.draw(0, 0, ofGetWidth(), ofGetHeight());
  
  int x = ofMap(mouseX, 0, ofGetWidth(), 0, image.getWidth()-1, true);
  int y = ofMap(mouseY, 0, ofGetHeight(), 0, image.getHeight()-1, true);
  
  ofPixels &px = image.getPixels();
  ofColor clr = px.getColor(x, y);
  ofSetColor(clr);
  
  ofDrawRectangle(mouseX-10, mouseY-10, 20, 20);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == ' ') {
    // Set a random row of pixels to a given color
    ofPixels &px = image.getPixels();
    int x = ofRandom(0, px.getWidth());
    for (int y = 0; y < px.getHeight(); y++) {
      px.setColor(x, y, ofColor(255));
    }
    image.update(); // <- Important
  }
  
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}
