#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  
  ofBackground(255);
  ofSetFrameRate(60);
  
  font.load("Arial", 100, false, false, true);

  sentence = "Goldsmiths";
  stringPoints = sampleStringPoints(sentence, 5.0);

  t = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofPushMatrix();
  // Set origin so the text is centered
  ofTranslate(ofGetWidth()/2 - font.stringWidth(sentence)/2, ofGetHeight()/2 + font.stringHeight(sentence)/2);

  float noiseSize = ofMap(mouseX, 0, ofGetWidth(), 0, 40);
  
  ofNoFill();
  for (int i=0; i<stringPoints.size(); i++){
    // Shifted point
    float phase = t + 0.123*i;
    vec2 offset = vec2(ofSignedNoise(phase, 0.0),
                       ofSignedNoise(phase, 0.233))*noiseSize;
    vec2 newPoint = stringPoints[i] + offset;
    
    // Varying radius
    float pointSize = ofNoise(phase, 0.7232) * 16;
    ofDrawCircle(newPoint, pointSize);
    
    // Interpolate color
    ofColor clr1 = ofColor(ofColor::black);
    ofColor clr2 = ofColor(ofColor::gray);
    ofColor c = clr1.lerp(clr2, ofNoise(phase, 123.232));
    ofSetColor(c);
  }
  t += 0.01;
  ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

}

vector<vec2> ofApp::sampleStringPoints(string s, float ds){
  vector<ofPath> paths = font.getStringAsPoints(s, false, false);
  
  vector<vec2> points;
  // Iterate through all paths
  for (int i = 0; i < paths.size(); i++) {
    // A single ofPath can actually consist of multiple sub-paths (ofPolylines),
    // so iterate through these also
    vector<ofPolyline> polylines = paths[i].getOutline();
    for (const ofPolyline& poly: polylines) {
      // get total length of polygon
      float length = poly.getPerimeter();
      // step along the polygon and get points
      for (float s = 0.0; s < length; s += ds) {
        points.push_back(poly.getPointAtLength(s));
      }
    }
  }
  return points;
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){
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
