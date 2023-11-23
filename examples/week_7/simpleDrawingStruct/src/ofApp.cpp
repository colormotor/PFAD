#include "ofApp.h"

Circle::Circle(const vec2& pos_, float radius_) {
  pos = pos_;
  radius = radius_;
}

Circle::Circle(float x, float y, float radius_) {
  pos = vec2(x, y);
  radius = radius_;
}


void Circle::draw() {
  ofDrawCircle(pos, radius);
}

//--------------------------------------------------------------
void ofApp::setup(){
  curRadius = 1;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  if (ofGetMousePressed()) {
    Circle c(mouseX, mouseY, curRadius);
    circles.push_back(c);
    curRadius+=0.1;
  }
  
  for (int i = 0; i < circles.size(); i++) {
    circles[i].draw();
  }
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
  curRadius = 1;
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
