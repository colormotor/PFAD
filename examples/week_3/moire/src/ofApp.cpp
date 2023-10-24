#include "ofApp.h"

float rot1 = 0;
float rot2 = 0;
bool stop = false;

void lineSequence(float x0, float x1, float spacing, float height) {
  for (float x = x0; x <= x1; x += spacing) {
    ofDrawLine(x, -height, x, height);
  }
}

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0, 0, 0);
  ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
  // Leave this at start of draw.
  // See `keyPressed` for where saving variable is changed
  if (saving) {
    ofBeginSaveScreenAsSVG("mySvg.svg");
  }

  ofNoFill();
  ofSetColor(255);
  ofSetLineWidth(1.5);
  
  // We want the patterns to be centered in the screen,
  // so we shift the coordinate system so the origin is at the center
  // of the screen:
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  
  // draw vertical lines with one rotation
  ofPushMatrix();
  ofRotateDeg(rot1);
  lineSequence(-ofGetWidth(), ofGetWidth(), 7, ofGetWidth());
  ofPopMatrix();
  
ofPushMatrix();
ofRotateDeg(rot2);
lineSequence(-ofGetWidth(), ofGetWidth(), 7, ofGetWidth());
ofPopMatrix();

  if (!stop) {
rot1 += 1;
rot2 -= 0.5;
  }
  // Leave this at end of draw
  if (saving) {
    ofEndSaveScreenAsSVG();
    cout << "Saved svg" << endl;
    saving = false; // reset the saving variable
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == ' ') { // If user presses space, we will save
    saving = true;
  }
  if (key == 's') {
    stop = !stop;
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
