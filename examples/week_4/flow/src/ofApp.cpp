#include "ofApp.h"

using namespace glm;

// Number of particles (and thus trajectories) and
// number of points for each trajectory
// these are const so we can initialize an array
const int numParticles = 200;
const int maxPoints = 1500;
// Number of points along particle trajectory
// we have computed so far
int pointCount = 1;

// Store points for each particles for a fixed (maxPoints)
// number of steps
vec2 trajectories[numParticles][maxPoints];

// Octave noise parameters
float noiseScale = 0.005;
int octaves = 4;
float t = 0.0;

// We use 3d noise, so we "slice" along the noise volume resulting
// in an animated flow field
float noise(float x, float y, float z) {
  float n = 0.0;
  float amplitude = 1.0;
  float frequency = 1.0;
  float normalization = 0.0;
  for (int i = 0; i < octaves; i++) {
    n += ofSignedNoise(x*frequency, y*frequency, z*frequency)*amplitude;
    normalization += amplitude;
    amplitude /= 2;
    frequency *= 2;
  }
  return n/normalization;
}

// Direction of noise flow given x and y position
vec2 noiseFlow(float x, float y) {
  float noiseVal = noise(x * noiseScale, y * noiseScale, t);
  float angle = noiseVal*PI;
  return vec2(cos(angle), sin(angle));
}

// Direction going outwards from center (assuming center of window)
vec2 outerFlow(float x, float y) {
  return normalize(vec2(x, y));
}

// Direction going outwards from center
vec2 circularFlow(float x, float y) {
  return normalize(vec2(-y, x));
}

// Use this to combine different flow fields
vec2 flowAt(float x, float y) {
  return circularFlow(x, y) + noiseFlow(x, y)*0.5 + outerFlow(x, y)*0.2;
}

// Use this to visually inspect the flow field
void drawFlowField() {
  ofNoFill();
  ofSetColor(0, 190, 255, 100);
  ofSetLineWidth(0.5);
  int width = ofGetWidth();
  int height = ofGetHeight();
  int step = 10;
  
  for (float y = -height/2; y < height/2; y+=step) {
    for (float x = -width/2; x < width/2; x+=step) {
      vec2 flow = flowAt(x, y);
      ofDrawLine(x, y, x+flow.x*20, y+flow.y*20);
    }
  }
}

// Resets all particles to a random initial position
void reset() {
  pointCount = 1;
  
  int width = ofGetWidth();
  int height = ofGetHeight();
  
  // Initialize first point
  float extent = 0.25;
  for (int i = 0; i < numParticles; i++) {
    trajectories[i][0] = vec2(ofRandom(-width/2, width/2)*extent,
                              ofRandom(-height/2, height/2)*extent);
  }
}

//--------------------------------------------------------------
void ofApp::setup(){
  reset();
}

//--------------------------------------------------------------
void ofApp::update(){
  for (int rep = 0; rep < 1; rep++) {
    // Compute incrementally
    // This will speed things up in case we draw many points
    if (pointCount < maxPoints) {
      for (int i = 0; i < numParticles; i++) {
        vec2 p = trajectories[i][pointCount-1];
        vec2 flow = flowAt(p.x, p.y);
        trajectories[i][pointCount] = p + flow;
      }
      pointCount++;
      t += 0.01;
    }
  }
}


//--------------------------------------------------------------
void ofApp::draw(){
  int width = ofGetWidth();
  int height = ofGetHeight();
  
  ofTranslate(width/2, height/2);
  
  ofBackground(255);
  drawFlowField();
  
  svg.begin();
  
  ofNoFill();
  ofSetColor(0);
  ofSetLineWidth(1);
  
  for (int i = 0; i < numParticles; i++) {
    ofBeginShape();
    // Only draw up to current point
    for (int j = 0; j < pointCount; j++) {
      ofVertex(trajectories[i][j]);
    }
    ofEndShape();
  }
  
  svg.end();
  
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == ' ')
    reset();
  if (key == OF_KEY_RETURN) {
    svg.save("flow.svg");
  }
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
