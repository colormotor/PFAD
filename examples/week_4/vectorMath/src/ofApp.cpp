#include "ofApp.h"

using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofSetLineWidth(2);
    
    vec2 centerWindow = vec2(ofGetWidth()/2,ofGetHeight()/2);
    vec2 mousePosition = vec2(mouseX,mouseY);
    
    //vector subtraction
    //the order we do the subtraction matters to get the right direction
    vec2 result = mousePosition - centerWindow;
    
    //translate to the center of the window
    //and draw the result vector which is now only the instructions
    //for getting from the center to the mouse positions
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofDrawLine(0,0,result.x,result.y);
    ofPopMatrix();
    
    //this is how long the line is between the center and the mouse position
    float magnitude = length(result);
    
    // cout << magnitude << endl;
    
    ofDrawRectangle(0, 0, magnitude, 10);//draw at top left of window
    
    //this is direction the line is pointing from the center to the mouse
    vec2 direction = normalize(result);
    
    //vector multiplication
    direction *= 40;
    
    //draw direction in red
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofSetLineWidth(3);
    ofSetColor(255,0,0);
    ofDrawLine(0,0,direction.x,direction.y);
    ofPopMatrix();
    
    
   //lecture coding challenge grid starter code
  //    for(int x = 20; x < ofGetWidth(); x += 40){
  //        for(int y = 20; y < ofGetHeight(); y += 40){
  //
  //        }
  //    }

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
