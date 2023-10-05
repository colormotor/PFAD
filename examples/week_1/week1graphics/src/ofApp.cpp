#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetCircleResolution(200);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  // Print X and Y mouse coordinates, the "endl" means "newline",
  // otherwise everything would be printed on the same line
  cout << "X:" << mouseX << " Y:" << mouseY << endl;
  
  // Draw a red circle with white outline
  // We draw the circle twice
  // First fill
  ofFill();
  ofSetColor(255, 0, 0);
  ofDrawCircle(mouseX, mouseY, 150);
  // Then draw outline
  ofSetLineWidth(4);
  ofNoFill();
  ofSetColor(255); //, 255, 0);
  ofDrawCircle(mouseX, mouseY, 150);
  
  ofDrawLine(0, 0, mouseX, mouseY);
  ofSetColor(255, 0, 0);
  ofBeginShape();
  ofVertex(20, 10);
  ofVertex(110, 10);
  ofVertex(100, 100);
  
  ofEndShape(OF_CLOSE);
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
