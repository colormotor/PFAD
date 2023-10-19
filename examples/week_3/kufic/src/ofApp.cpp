#include "ofApp.h"

bool saving = false;
int seed = 10;

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255); // Change background color here
  // This tells OF to not automatically clear the window
  ofSetBackgroundAuto(true);
	ofSetFrameRate(60); // This is important to keep framerate fixed
}

//--------------------------------------------------------------
void ofApp::update(){
}


//--------------------------------------------------------------
void ofApp::draw(){
  if (saving) {
    ofBeginSaveScreenAsSVG("mySvg.svg");
  }

  ofFill();
  ofSetColor(0);

  int cellSize = 20; // assume square screen
  int numCols = ofGetWidth()/cellSize;
  int numRows = ofGetHeight()/cellSize;

  ofSeedRandom(seed); // does not work with latest OF
  srand(seed);        // so we also use this C function in case
  
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofTranslate(cellSize*0.5, cellSize*0.5);
  for (int i = 0; i < numRows-1; i+=2) {
    for (int j = 0; j < numCols-1; j+=2) {
      ofDrawRectangle((i+1)*cellSize,   (j+1)*cellSize, cellSize, cellSize);
      if (ofRandom(1) < 0.5) {
        ofDrawRectangle((i)*cellSize,   (j+1)*cellSize, cellSize, cellSize);
      }
      if (ofRandom(1) < 0.5) {
        ofDrawRectangle((i+1)*cellSize,   (j)*cellSize, cellSize, cellSize);
      }
    }
  }

  if (saving) {
    ofEndSaveScreenAsSVG();
    cout << "Saved svg" << endl;
    saving = false;
  }
  return;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == ' ') {
    saving = true;
  }
  
  if (key == 'a')
    seed--;
  if (key == 'd')
    seed++;
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
