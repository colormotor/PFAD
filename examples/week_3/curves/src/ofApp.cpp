#include "ofApp.h"

bool autoClear = true;
bool saving = 0;
double t = 0.0;

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0, 0, 0); // Change background color here
  // This tells OF to not automatically clear the window
  ofSetBackgroundAuto(autoClear);
	ofSetFrameRate(60); // This is important to keep framerate fixed
}

//--------------------------------------------------------------
void ofApp::update(){
}

float pendulum(float t, float freq, float phase, float damping) {
  return sin(t*freq + phase)*exp(-damping*t);
}


void drawHarmonograph(int n, float step, float r, float f1, float f2, float p1, float p2, float damping=0.01) {
  ofBeginShape();
  for (int i = 0; i < n; i++) {
    float t = i*step;
    ofVertex(r*pendulum(t, f1, p1, damping),
             r*pendulum(t, f2, p2, damping));
  }
  ofEndShape();
}

void drawSpirograph(int n, float step, float r, float k, float l) {
  ofBeginShape();
  std::cout << k << ", " << l << endl;
  for (int i = 0; i < n; i++) {
    float t = step * i;
    float x = r*((1-k)*cos(t) + l*k*cos((1 - k)/k*t));
    float y = r*((1-k)*sin(t) + l*k*sin((1 - k)/k*t));
    ofVertex(x, y);
  }
  ofEndShape();
}

void drawLissajous(int n, float step, float r, float a, float b, float phase) {
  ofBeginShape();
  for (int i = 0; i < n; i++) {
    float t = step * i;
    float x = r*cos(t*a + phase);
    float y = r*sin(t*b);
    ofVertex(x, y);
  }
  ofEndShape();
}

//--------------------------------------------------------------
void ofApp::draw(){
  // Move origin to center
  if (saving) {
    ofBeginSaveScreenAsSVG("test.svg");
  }
  
  ofNoFill();
  ofSetLineWidth(1);
  ofSetColor(255);

  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  //drawLissajous(1000, PI/100, ofGetWidth()/4, 5, 4, PI/2);
  //drawSpirograph(10000, PI/100, ofGetWidth()/4, 0.60153, 0.728);
  drawHarmonograph(10000, PI/100, ofGetWidth()/4, 2.4, 0.9, 0.24, 0.15);
  if (saving) {
    ofEndSaveScreenAsSVG();
    saving = 0;
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == ' ') {
    saving = 1;
    t = 0.0;
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
