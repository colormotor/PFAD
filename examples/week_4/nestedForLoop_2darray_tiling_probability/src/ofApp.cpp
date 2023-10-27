#include "ofApp.h"

const int numOfTilesX=10; // const means we do not change the value
const int numOfTilesY=10;

float tileSizeX;
float tileSizeY;

float randomNumbers[numOfTilesY][numOfTilesX]; // we have to tell our computer how much memory we need for our array

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(0);
    
    //ofSeedRandom will mean that the following ofRandom call will always produce the same numbers
//    ofSeedRandom(100);
    
    for (int i = 0; i < numOfTilesY; i++)
    {
        for (int j = 0; j < numOfTilesX; j++)
        {
            randomNumbers[i][j] = ofRandom(1); // gives us a random value between 0 - 1
        }
    }
    
    
    tileSizeX = ofGetWidth() / numOfTilesX;
    tileSizeY = ofGetHeight() / numOfTilesY;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

  for (int i = 0; i < numOfTilesY; i++)
  {
      for (int j = 0; j < numOfTilesX; j++)
      {
            int locX = j * tileSizeX + tileSizeX/2;
            int locY = i * tileSizeY + tileSizeY/2;
            
            ofPushMatrix();
            ofPushStyle();
     
            ofTranslate(locX,locY);
   
            if(randomNumbers[i][j] > 0.7){
                ofDrawEllipse(0,0,tileSizeX/2,tileSizeY/2);
            }else{
                ofDrawRectangle(0,0,tileSizeX-20,tileSizeY-20);
            }
            
            ofPopStyle();
            ofPopMatrix();
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //roll the "dice" again!
    if(key == 'd'){
        
        for (int x = 0; x < numOfTilesX; x++)
        {
            for (int y = 0; y < numOfTilesY; y++)
            {
                randomNumbers[x][y] = ofRandom(1); // gives us a random value between 0 - 1
            }
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
