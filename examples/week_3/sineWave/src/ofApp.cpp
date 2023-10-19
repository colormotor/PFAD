#include "ofApp.h"

float phase = 0.0;

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

  
  ofNoFill();
  ofSetColor(255, 128);
  
  int numCircles = 200;
  
  // Mapping mouse to sine wave frequency for radius
  float freqRadius = ofMap(mouseX, 0, ofGetWidth(), 0.5, 10);
  // Mapping mouse to sine wave frequency for Y position
  float freqY = ofMap(mouseX, 0, ofGetWidth(), 0.5, 10);
  
  // Translate to middle vertically, so -1, 1 of sine creates a symmetric offset
  ofTranslate(0, ofGetHeight()/2);
  
  for (int i = 0; i < numCircles; i++) {
    // map index to a horizontal point between left and right of window
    float x = ofMap(i, 0, numCircles-1, 0, ofGetWidth());
    // Y oscillator
    float y = 100*sin(0.01*i*freqY + phase);
    // radius oscillator
    float r = sin(0.01*i*freqRadius);
    // we remap this to a positive value
    r = ofMap(r, -1, 1, 10, 100);
  
    ofDrawCircle(x, y, r);
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
  if (key == ' ') { // If user presses space, we will save in the next
                    // call to draw. Use OF_KEY_RETURN for enter
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
