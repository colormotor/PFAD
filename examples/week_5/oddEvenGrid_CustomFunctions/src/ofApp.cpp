#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    numOfTilesX = 10;
    numOfTilesY = 10;
    
    tileSizeX = 100;
    tileSizeY = 100;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //converting to a float before the division keep things better aligned when window is resized
    //read up on explicit type conversion if you are interested: https://cplusplus.com/doc/oldtutorial/typecasting/
    tileSizeX = (float)ofGetWidth() / numOfTilesX;
    tileSizeY = (float)ofGetHeight() / numOfTilesY;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < numOfTilesY; i++)
    {
        for (int j = 0; j < numOfTilesY; j++)
        {
            float locX = j * tileSizeX + tileSizeX/2;
            float locY = i * tileSizeY + tileSizeY/2;
            
            //using two custom functions
            if(isEvenNumber(j)){
                textureTile(locX,locY,0,1.5,ofColor(255,0,0),false);
            }else{
                textureTile(locX,locY,180,1,ofColor(0,0,0),true);
            }
            
        }
    }
}

bool ofApp::isEvenNumber(int num){
    //modulo gives us the remainder after a division
    int modulo = num % 2;
    //returns a boolean value true if it's even (divisible by 2), false if it's odd
    return modulo == 0;
}

void ofApp::textureTile(int x, int y, int degrees, float scale, ofColor color, bool fill){
    ofPushMatrix();
    ofPushStyle();
    
    ofTranslate(x,y);
    ofRotateDeg(degrees);
    ofScale(scale);
    
    ofSetColor(color);
    if(fill){
        ofFill();
    }else{
        ofNoFill();
    }

    //Do your own drawing here
    ofDrawTriangle(0,-20,-20,20,20,20);
    
    
    ofPopStyle();
    ofPopMatrix();
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
