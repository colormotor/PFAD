#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  // We don't need the full resolution here
  vidGrabber.setup(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
  vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  if (!showEffect) {
    ofSetColor(255);
    vidGrabber.draw(0, 0, ofGetWidth(), ofGetHeight());
  } else {
    // Replace the contents of this "else" block with your code
    ofPushMatrix();
    
    // Do something with the pixels
    ofPixels& px = vidGrabber.getPixels();
    int w = vidGrabber.getWidth();
    int h = vidGrabber.getHeight();

    // Scale to match video and window
    ofScale((float)ofGetWidth()/w,
            (float)ofGetHeight()/h);
    
    float radius = ofMap(mouseX, 0, w, 10, 400);
    ofNoFill();
    
    ofSetColor(255, 50);
    
    int step = 8;
    for (int y = 0; y < h; y+=step) {
      for (int x = 0; x < w; x+=step) {
        // Get pixel and lightness
        ofColor c = px.getColor(x, y);
        float l = c.getLightness() / 255.0;
        ofDrawCircle(x, y, l*radius);
      }
    }
    
    ofPopMatrix();
  }
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == ' ')
    showEffect = !showEffect;
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}


//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

