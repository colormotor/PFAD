#include "ofApp.h"

using namespace glm;

/// This returns a numRows*numCols array containing
/// points spaced on a grid that fits the window
vector<vec2> gridPoints(int numRows, int numCols) {
  vector<vec2> points;
  float cellWidth = ofGetWidth()/numCols;
  float cellHeight = ofGetHeight()/numRows;
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      points.push_back(vec2(cellWidth/2 + j*cellWidth,
                            cellHeight/2 + i*cellHeight));
    }
  }
  return points;
}

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  // Get points on a grid, note that the result does
  // not have to be a 2d array, we can simply store the
  // positions linearly
  vector<vec2> points = gridPoints(10, 20);
  
  // draw all points in grid
  ofSetColor(255);
  for (int i = 0; i < points.size(); i++) {
    ofDrawCircle(points[i], 5);
  }
  
  // try replacing the code inside the loop with your own
  // drawing code
  
  // draw the last point of the grid in red
  ofSetColor(255, 0, 0);
  ofDrawCircle(points.back(), 10);
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
