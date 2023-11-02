#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(60);
    ofBackground(200);

    
    //Change this scale to make bigger images! You will need to scale up all your drawing
    fboScale = 5;
    
    //595x842 is an A4 page at 72 DPI
    //DON'T change these pixel values / numbers only change the fboScale to get bigger images
    fboWidth = 595*fboScale;//so multiply it to make it bigger
    fboHeight = 842*fboScale;
    scaleFactor = 595/fboWidth;
    
   
    
    canvasFbo.allocate(fboWidth,fboHeight,GL_RGBA,4);
    
    canvasFbo.begin();
    ofClear(255,255,255,255);
    
    canvasFbo.end();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    canvasFbo.begin();
    
    ofPushMatrix();
    
    ofTranslate(mouseX*fboScale,mouseY*fboScale);

    ofSetColor(0);
    ofDrawCircle(0,0,50);
    
    ofPopMatrix();
    
    canvasFbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //set white so the canvas fbo color isn't changed.
    ofSetColor(255);
    canvasFbo.draw(0,0,ofGetWidth(),ofGetHeight());

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    if(key == 's'){
        //now save our high resolution image
        ofPixels pix;
        canvasFbo.readToPixels(pix);
        ofSaveImage(pix, "ParametricPoster_" + ofGetTimestampString() + ".png", OF_IMAGE_QUALITY_BEST);
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
