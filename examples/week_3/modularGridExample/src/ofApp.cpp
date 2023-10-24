#include "ofApp.h"

int numRows = 20;
int numCols = 20;

int seed = -12; //2567;

void drawTile(int row, int col, float cellWidth, float cellHeight) {
  ofSetColor(0);
  ofScale(0.5);
  int choice = ofRandom(0, 2);
  if (choice==0) {
    ofDrawLine(-cellWidth, -cellHeight, cellWidth, cellHeight);
  } else if (choice==1) {
    ofDrawLine(cellWidth, -cellHeight, -cellWidth, cellHeight);
  }
}

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255, 255, 255); // Change background color here
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

  
  srand(seed);
  ofSetRandomSeed(seed);
  
  float tileWidth = ofGetWidth()/numCols;
  float tileHeight = ofGetHeight()/numRows;
  
  // We want to draw from the center of cell
  ofTranslate(tileWidth/2, tileHeight/2);
  
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      ofPushMatrix();
      ofTranslate(tileWidth*j, tileHeight*i);
      drawTile(i, j, tileWidth, tileHeight);
      ofPopMatrix();
    }
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
  if (key == ' ') {
    saving = true;
  }
  if (key == 'a') {
    seed--;
  }
  if (key == 'd') {
    seed++;
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
