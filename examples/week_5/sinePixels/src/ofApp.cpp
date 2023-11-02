#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    rectSize = 3;
    sineFrequency = 0.5;
    sinePhase = 100;
    amplitude = 255;// the "height" of our waves is in the color domain 0 - 255
}

//--------------------------------------------------------------
void ofApp::update(){
    sineFrequency = ofMap(mouseX,0,ofGetWidth(),0.1,1.5,true);//frequency means "how many" waves we have, in our case bigger or smaller waves on the screen
    sinePhase = ofMap(mouseY,0,ofGetHeight(),0,50,true);//phase means "where we are" along the sine wave
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int x=0; x<ofGetWidth()/rectSize; x++)
    {
        for (int y=0; y < ofGetHeight()/rectSize; y++)
        {
            float sineXY = sin((x+y)*sineFrequency+sinePhase);//try use this instead of the sine variable in the the ofMap below
            float sine = sin(x*sineFrequency+sinePhase);
            float greyValue = ofMap(sineXY, -1,1,0,amplitude);
            ofSetColor(greyValue);
            ofDrawRectangle(x*rectSize,y*rectSize,rectSize,rectSize);
        }
    }
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
