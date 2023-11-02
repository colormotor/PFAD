#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetCircleResolution(100);
  ofSetFrameRate(60);
  
  // setup UI
  gui.setup();
  gui.add(radius.setup("Radius", 100, 10, 250)); // value, min, max
  gui.add(numPoints.setup("Num points", 200, 5, 400));
  gui.add(amplitude.setup("Amplitude", 250, 0, 400));
  gui.add(frequency.setup("Frequency", 1, 1, 20));
  gui.add(showNoise.setup("Show noise", true));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  // This will draw the gui under your graphics
  // If you want to draw it on top, you might
  // have to wrap your drawing code in ofPushMatrix()/ofPopMatrix()
  gui.draw();
  
  ofFill();
  ofSetColor(255, 0, 0);
  ofDrawCircle(ofGetWidth()/2, 100, radius);
  
  // Move to vertical center
  ofTranslate(0, ofGetHeight()/2);
  
  float step = 1.0 / (numPoints-1);

  ofNoFill();
  ofSetLineWidth(3.0);
  
  // draw a sine wave
  ofSetColor(255);
  ofBeginShape();
  for (int i = 0; i < numPoints; i++) {
    float v = step*i;
    ofVertex(v*ofGetWidth(),
             sin(v*TWO_PI*frequency + t*TWO_PI)*amplitude);
  }
  ofEndShape();
             
  if (showNoise) {
    ofSetColor(0, 128, 255);
    ofBeginShape();
    for (int i = 0; i < numPoints; i++) {
      float v = step*i;
      ofVertex(v*ofGetWidth(),
               ofSignedNoise(v*frequency + t)*amplitude);
    }
    ofEndShape();
  }
  
  t += 0.01;
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
