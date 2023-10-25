#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    numOfTilesX = 10;
    numOfTilesY = 10;
    
    tileSizeX = ofGetWidth() / numOfTilesX;
    tileSizeY = ofGetHeight() / numOfTilesY;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    numOfTilesX = 10;
//    numOfTilesY = 10;
//
//    tileSizeX = ofGetWidth() / numOfTilesX;
//    tileSizeY = ofGetHeight() / numOfTilesY;


    for (int x = 0; x < numOfTilesX; x++)
    {
        for (int y = 0; y < numOfTilesY; y++)
        {
            //multiplying tile number by the size of each tile then adding half to get to the center of each tile
            float locX = x * tileSizeX + tileSizeX/2;
            float locY = y * tileSizeY + tileSizeY/2;
            ofDrawEllipse(locX, locY, 20, 20);
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
