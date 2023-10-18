#include "ofApp.h"

float rot1 = 0.0;
float rot2 = 0.0;

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0, 0, 0); // Change background color here
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

  // Task: we will have two overlapping transparent rectangles rotating
  // in different directions
  // When we enter `ofApp::draw` the transformation is reset
  ofFill();
  ofSetColor(255, 128);
  
  // We want the rectangles to be centered in the screen,
  // so we shift the coordinate system so the origin is at the center
  // of the screen:
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  // We also want to draw the rectangles around their center:
  ofSetRectMode(OF_RECTMODE_CENTER);
  
  ofTranslate(20, 0);
  // draw the first rectangle
  ofPushMatrix(); // This starts a new "scope" for transformations
  ofRotateDeg(rot1);
  ofDrawRectangle(0, 0, 200, 200);
  ofPopMatrix(); // This ends the scope and resets the transformation
                 // to what it was before the last ofPushMatrix()
  rot1 += 1; // rotate clockwise

  ofPushMatrix();
  ofRotateDeg(rot2);
  ofDrawRectangle(0, 0, 200, 200);
  ofPopMatrix();

  rot2 -= 1; // rotate counterclockwise

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
