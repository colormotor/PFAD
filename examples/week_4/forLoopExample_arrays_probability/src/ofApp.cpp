#include "ofApp.h"

const int numOfStripes = 50; // const means we do not

float stripeSpacing;

float randomNumbers[numOfStripes]; // we have to tell our computer how much memory we need for our array

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int i = 0; i < numOfStripes; i++)
    {
        randomNumbers[i] = ofRandom(1); // gives us a random value between 0 - 1
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    stripeSpacing = ofGetWidth() / numOfStripes;
}

//--------------------------------------------------------------
void ofApp::draw(){
    

    for (int i = 0; i < numOfStripes; i ++)
    {
        int locX = i * stripeSpacing;
        int startX = locX + stripeSpacing/2;//our rectmode is set to center so we start drawing at the center of our stripe space
        
        ofDrawRectangle(startX, ofGetHeight()/2, stripeSpacing*randomNumbers[i], ofGetHeight());
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //roll the "dice" again!
    if(key == 'd'){
        for (int i = 0; i < numOfStripes; i++)
        {
            randomNumbers[i] = ofRandom(1); // gives us a random value between 0 - 1
        }
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
