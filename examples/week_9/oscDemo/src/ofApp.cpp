#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  receiver.setup(9999); // Receiving on port 9999
  sender.setup("localhost", 9998); // Sending to localhost on port 9998
}

//--------------------------------------------------------------
void ofApp::update(){
  while(receiver.hasWaitingMessages()){
    
    // get the next message
    ofxOscMessage m;
    receiver.getNextMessage(m);
    if(m.getAddress() == "/bg"){
      float intensity = m.getArgAsFloat(0); // get first argument
      cout << "Received: " << intensity << endl;
      backgroundColor = ofColor(intensity);
    } // else if (m.getAddress() == "/another/address") {} etc etc...
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(backgroundColor);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  // Send a random value when key pressed
  ofxOscMessage m;
  m.setAddress("/value");
  float value = ofRandom(0, 1);
  m.addFloatArg(value);
  sender.sendMessage(m, false);
  cout << "Sending " << value << endl;
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
