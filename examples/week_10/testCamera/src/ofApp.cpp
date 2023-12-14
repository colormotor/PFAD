#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  position = vec3(0, 0, 0);
  rotation = vec3(0, 0, 0);
  cam.setNearClip(0.001);
}

//--------------------------------------------------------------
void ofApp::update(){

  // Calculate player position and rotation
  position.z += -(wsad[0] + wsad[1]) * cos(ofDegToRad(rotation.x));
  position.x += (wsad[0] + wsad[1]) * sin(ofDegToRad(rotation.x));

  float alpha = ofDegToRad(180 - rotation.x);
  position.z += -(wsad[2] + wsad[3]) * sin(alpha);
  position.x += (wsad[2] + wsad[3]) * cos(alpha);

  cam.setPosition(position.x, position.y, position.z);
  cam.setOrientation(vec3(rotation.y, -rotation.x, 0));

}

void ofApp::keyPressed(int key) {
  switch (key)
  {
  case 'w':
    wsad[0] = 1;
    break;
  case 's':
    wsad[1] = -1;
    break;
  case 'a':
    wsad[2] = 1;
    break;
  case 'd':
    wsad[3] = -1;
    break;
  default:
    break;
  }
}
//--------------------------------------------------------------
void ofApp::draw(){
  vec3 pos = cam.getPosition();
  cam.begin();
  int n = 260;
  
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      vec2 p = vec2(pos.x -0.5*n + j,
                    pos.z - 0.5*n + i);
      float r = ofNoise(0.13*p.x, 0.13*p.y)*0.3;
      ofDrawIcoSphere(p.x, -2, p.y, r);
    }
  }
  cam.end();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  // When key is realeased set movement speed to 0
  for (int i = 0; i < 4; i++)
    wsad[i] = 0;
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
