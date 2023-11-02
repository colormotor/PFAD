#include "ofApp.h"

int seed=0;


//--------------------------------------------------------------
void ofApp::setup(){
  showTurtle = true;
  ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
}

void turtleTriangle(float size) {
  ofBeginShape();
  ofVertex(-size*0.4, -size);
  ofVertex(size*2, 0);
  ofVertex(-size*0.4, size);
  ofVertex(0, 0);
  ofEndShape(OF_CLOSE);
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
  drawTurtle();
}

void ofApp::turtleLeft(float degrees) {
  ofRotateDeg(-degrees);
  drawTurtle();
}

void ofApp::turtleScale(float scale) {
  ofScale(scale);
  drawTurtle();
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

  // This code uses the turtle functions with
  // a loop for more concise code
  float angle = ofMap(mouseY, 0, ofGetHeight(), 0, 180);
  
  for (int rot = 0; rot < 360; rot += 10) {
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

  
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key=='a')
    seed--;
  if (key=='d')
    seed++;
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

////--------------------------------------------------------------
//void ofApp::turtleReset(float x, float y) {
//  turtlePos = vec2(x, y);
//  turtleDir = vec2(1, 0);
//  turtlePolygons.clear();
//  turtleJump(x, y);
//}
//
//void ofApp::turtleRotateDeg(float angle) {
//  turtleDir = rotate(turtleDir, ofDegToRad(angle));
//}
//
//void ofApp::turtleRotateRad(float angle) {
//  turtleDir = rotate(turtleDir, angle);
//}
//
//void ofApp::turtleSetDirection(float x, float y) {
//  turtleDir = normalize(vec2(x, y));
//}
//
//void ofApp::turtleForward(float distance) {
//  turtlePos += turtleDir*distance;
//  if (isPenDown)
//    turtlePolygons.back().push_back(turtlePos);
//}
//
//void ofApp::turtlePenUp() {
//  isPenDown = false;
//}
//
//void ofApp::turtlePenDown() {
//  if (!isPenDown) {
//    turtlePolygons.push_back(vector<vec2>());
//    turtlePolygons.back().push_back(turtlePos);
//  }
//  isPenDown = true;
//}
//
//void ofApp::turtleJump(float x, float y) {
//  turtlePenUp();
//  turtlePos = vec2(x, y);
//  turtlePenDown();
//}
//
//void ofApp::turtleDraw() {
//  for (int i = 0; i < turtlePolygons.size(); i++) {
//    drawTurtlePolygon(turtlePolygons[i]);
//  }
//}
//
//void ofApp::turtleCircle(float radius, int steps, float extent) {
//  extent = ofDegToRad(extent);
//  float angleStep = extent/steps; //(steps-1);
//  float segmentLength = fabs(angleStep)*radius;
//  for (int i = 0; i < steps; i++) {
//    turtleForward(segmentLength);
//    turtleRotateRad(angleStep);
//  }
//}
//
//void ofApp::turtleSquare(float size) {
//  for (int i = 0; i < 4; i++) {
//    turtleForward(size);
//    turtleRotateDeg(90);
//  }
//}
//
//void ofApp::drawTurtlePolygon(const vector<vec2>& polygon) {
//  ofBeginShape();
//  for (int i = 0; i < polygon.size(); i++) {
//    ofVertex(polygon[i]);
//  }
//  ofEndShape();
//}


