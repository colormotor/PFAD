#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  showTurtle = true;
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
}


void ofApp::drawTurtleShape(){
  /// Override the contents of this function to create different turtle shapes
  /// This can be literally anything :)
  /// But keep in mind drawing around the origin (0, 0)
  // Draw x and y axes
  float size = 40;
  ofNoFill();
  ofSetColor(255, 0, 0);
  ofDrawLine(0, 0, size, 0);
  ofSetColor(0, 255, 0);
  ofDrawLine(0, 0, 0, size);
  
  // Draw the turtle
  size = 10;
  ofFill();
  ofSetColor(255); //, 0, 0, 90);
  turtleTriangle(size);
  ofNoFill();
  ofSetLineWidth(3.0);
  ofSetColor(0);
  turtleTriangle(size);
}

//--------------------------------------------------------------
void ofApp::draw(){
  // This code explicitly draws the turtle using OF transformations
  turtleReset(ofGetWidth()/2, ofGetHeight()/2);
  drawTurtle();
  ofTranslate(100, 0);
  drawTurtle();
  ofRotateDeg(45);
  drawTurtle();
  ofTranslate(100, 0);
  drawTurtle();
  // End demo code
  
  // This code uses the turtle functions with
  // a loop for more concise code
  // Uncomment for lab exercise
//  float angle = ofMap(mouseY, 0, ofGetHeight(), 0, 180);
//
//  turtleReset(ofGetWidth()/2, ofGetHeight()/2);
//  for (int i = 0; i < 100; i++) {
//    turtleForward(100);
//    turtleRight(angle);
//    turtleScale(0.9);
//  }
  
  ofNoFill();
  ofSetColor(255, 90);
  ofSetLineWidth(2.0);
  drawLastTurtlePath();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key=='t')
    showTurtle = !showTurtle;
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

void ofApp::turtleTriangle(float size) {
  // Utility function to draw the turtle shape since we have to draw it more than once to get an outline for clarity
  ofBeginShape();
  ofVertex(-size*0.4, -size);
  ofVertex(size*2, 0);
  ofVertex(-size*0.4, size);
  ofVertex(0, 0);
  ofEndShape(OF_CLOSE);
}

void ofApp::drawTurtle() {
  // This stores the position of the turtle and
  // wraps our custom drawing code
  // so it does not interfere with other drawing code
  storeTurtlePos();
  
  if (!showTurtle)
    return;
  ofPushStyle();
  ofPushMatrix();
  drawTurtleShape();
  ofPopMatrix();
  ofPopStyle();
}

void ofApp::storeTurtlePos() {
  // This gets the current transformation (as a matrix)
  // which contains the transformed position
  // but this code assumes we are working after
  // ofSetupScreenOrtho has been called (see turtleReset)
  mat4 m = ofGetCurrentMatrix(OF_MATRIX_MODELVIEW);
  // Add the transformed position to an array
  positions.push_back(vec2(m[3].x, m[3].y));
}

void ofApp::drawLastTurtlePath() {
  // This draws the points that have been traced by the turtle
  // also requires ofSetupScreenOrtho to work
  ofPushStyle();
  ofPushMatrix();
  ofLoadIdentityMatrix();
  ofNoFill();
  ofBeginShape();
  for (int i = 0; i < positions.size(); i++)
    ofVertex(positions[i]);
  ofEndShape();
  ofPopMatrix();
  ofPopStyle();
}

void ofApp::turtleGoto(float x, float y) {
  ofTranslate(x, y);
  positions.clear();
  drawTurtle();
}

void ofApp::turtleReset(float x, float y) {
  // This is important for the turtle code to work
  ofSetupScreenOrtho(ofGetWidth(), ofGetHeight());
  // Move to specified position
  turtleGoto(x, y);
}

void ofApp::turtleForward(float distance) {
  ofTranslate(distance, 0);
  drawTurtle();
}

void ofApp::turtleRight(float degrees) {
  ofRotateDeg(degrees);
  // drawTurtle();
}

void ofApp::turtleLeft(float degrees) {
  ofRotateDeg(-degrees);
  // drawTurtle();
}

void ofApp::turtleScale(float scale) {
  ofScale(scale);
  // drawTurtle();
}
