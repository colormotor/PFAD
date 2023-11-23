#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetCircleResolution(50);
  
  //GUI
  gui.setup();
//
//  gui.add(slider_speedlimit.setup("speed limit",2,1,20,200,20));
//  gui.add(slider_separation.setup("separation",0.07,0,1,200,20));
//  gui.add(slider_cohesion.setup("cohesion",0.01,0,0.5,200,20));
//  gui.add(slider_alignment.setup("alignment",0.3,0,1,200,20));
//
  gui.add(speedlimit.setup("speed limit",105,1,220));
  gui.add(separation.setup("separation",0.15,0,10));
  gui.add(cohesion.setup("cohesion",0.01,0,5));
  gui.add(alignment.setup("alignment",0.3,0,5));
  
  gui.add(checkdist.setup("check neighbors distance",30,10,60));
  gui.add(radius.setup("radius",500,50,600));
  gui.add(bounce.setup("edge bounciness",10,0.1,100));
      
  for(int i = 0; i < 10; i++){
    vec2 pos = vec2(ofRandom(0,ofGetWidth()),
                    ofRandom(0,ofGetHeight()));
    boids.push_back(Boid(i, pos, ofColor(0, 200)));
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  for(int i = 0; i < boids.size(); i++){
    boids[i].update(boids,
                    105,
                    0.15,
                    0.01,
                    0.3,
                    50,
                    10,
                    0.02);
//    boids[i].update(boids,
//                    speedlimit,
//                    separation,
//                    cohesion,
//                    alignment,
//                    checkdist,
//                    radius,
//                    bounce);
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(37, 159, 202);
  
  for(int i = 0; i < boids.size(); i++){
    boids[i].draw();
  }
  ofSetColor(255);
  gui.draw();
  ofSetColor(255);
  ofDrawBitmapString(to_string(ofGetFrameRate()), ofGetWidth()/2, 20);
}

//--------------------------------------------------------------
void ofApp::exit(){

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
