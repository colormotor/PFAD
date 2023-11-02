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
  ofNoFill();
  ofSetColor(255, 128);
  ofDrawCircle(0, 0, 200);
}

//--------------------------------------------------------------
void ofApp::draw(){
  float angle = ofMap(mouseY, 0, ofGetHeight(), 0, 180);

  for (int rot=0; rot < 360; rot += 10) {
    turtleReset(ofGetWidth()/2, ofGetHeight()/2);
    turtleRight(rot);

    for (int i = 0; i < 100; i++) {
      turtleForward(100);
      turtleRight(angle);
      turtleScale(0.9);
    }

    ofNoFill();
    ofSetColor(255, 90);
    ofSetLineWidth(2.0);
    drawLastTurtlePath();
  }
  
//  for (int rot=0; rot < 360; rot += 10) {
//    ofPushMatrix();
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
//    drawTurtleShape();
//    ofRotateDeg(rot);
//    for (int i = 0; i < 100; i++) {
//      ofTranslate(100, 0);
//      drawTurtleShape();
//      ofRotateDeg(angle);
//      ofScale(0.9);
//    }
//    ofPopMatrix();
//  }
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
  ofCurveVertex(positions[0]);
  for (int i = 0; i < positions.size(); i++) {
    ofCurveVertex(positions[i]);
  }
  ofCurveVertex(positions.back());
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
  //drawTurtle();
}

void ofApp::turtleLeft(float degrees) {
  ofRotateDeg(-degrees);
  //drawTurtle();
}

void ofApp::turtleScale(float scale) {
  ofScale(scale);
  //drawTurtle();
}
