#include "ofApp.h"

int resolution = 100;

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0, 0, 0); // Change background color here
  ofSetCircleResolution(resolution);
}

//--------------------------------------------------------------
void ofApp::update(){
}

void drawCircle(float x, float y, float radius, int resolution) {
  float step = TWO_PI / resolution;
  ofBeginShape();
  for (int i = 0; i < resolution; i++) {
    float theta = step * i;
    ofVertex(x + cos(theta)*radius,
             y + sin(theta)*radius);
  }
  ofEndShape(OF_CLOSE);
}


//--------------------------------------------------------------
void ofApp::draw(){
  // Leave this at start of draw.
  // See `keyPressed` for where saving variable is changed
  if (saving) {
    ofBeginSaveScreenAsSVG("mySvg.svg");
  }

  // Translate to center of screen
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  ofNoFill();
  ofSetLineWidth(7);
  ofSetColor(255, 0, 0, 128);
  float radius = 70;
  // Draw circle as a reference
  ofDrawCircle(0, 0, radius);
  
  ofSetLineWidth(2);
  ofSetColor(255);
  // Manually draw a circle
  drawCircle(0, 0, radius, resolution);
  
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
