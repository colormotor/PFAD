#include "ofApp.h"

using namespace glm;

// Octave noise parameters
float noiseScale = 0.005;
int octaves = 4;
float t = 0.0;
float flowAngle = PI/2;

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



// Direction going outwards from center (assuming origin at center)
vec2 outerFlow(float x, float y) {
  return normalize(vec2(x, y));
}

// Direction going in circles (assuming origin at center)
vec2 circularFlow(float x, float y) {
  return normalize(vec2(-y, x));
  // return normalize(rotate(vec2(x,y), flowAngle)); // <- this is a more general version that creates spirals depending on parameter
}

// Direction of noise flow given x and y position
vec2 noiseFlow(float x, float y) {
  // Get slice of noise based on x, y and t parameter
  // Replace ofSignedNoise with "noise" to get octaves
  float noiseVal = ofSignedNoise(x * noiseScale, y * noiseScale, t);
  // Get value of noise between -1 and 1 and convert to an angle
  // (between -PI and PI)
  float angle = noiseVal*PI;
  // Convert angle to a unit vector by getting point on circle
  return vec2(cos(angle), sin(angle));
}

// Use this to combine different flow fields
vec2 flowAt(float x, float y) {
  return noiseFlow(x, y);
  // return outerFlow(x, y);
  //  Use below as example for weighted sum of different fields
//  return noiseFlow(x, y)*0.5 + circularFlow(x, y) + outerFlow(x, y)*0.1;
}


//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){

}


//--------------------------------------------------------------
void ofApp::draw(){
  int width = ofGetWidth();
  int height = ofGetHeight();
  flowAngle = ofMap(mouseX, 0, ofGetWidth(), 0, TWO_PI, true);
  
  ofBackground(0);
  
  svg.begin();
  
  // Center origin
  ofTranslate(width/2, height/2);
  
  // Flow field draw
  ofNoFill();
  ofSetColor(0, 190, 255, 150);
  ofSetLineWidth(2);
  int step = 10;
  
  for (float y = -height/2; y < height/2; y+=step) {
    for (float x = -width/2; x < width/2; x+=step) {
      vec2 flow = flowAt(x, y);
      ofDrawLine(x, y, x+flow.x*20, y+flow.y*20);
    }
  }
  // end flow field draw
  
  t += 0.01;
  
  svg.end();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
