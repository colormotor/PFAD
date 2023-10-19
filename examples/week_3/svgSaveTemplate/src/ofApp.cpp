#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0, 0, 0); // Change background color here
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
    // the file will end up in the ./bin/data directory
    ofBeginSaveScreenAsSVG("mySvg.svg");
  }

  // Drawing code goes here
  ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 200);
  
  // Leave this at end of draw
  if (saving) {
    ofEndSaveScreenAsSVG();
    cout << "Saved svg" << endl;
    saving = false; // reset the saving variable
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == ' ') {
    saving = true;
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
