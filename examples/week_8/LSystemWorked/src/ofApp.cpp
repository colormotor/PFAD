#include "ofApp.h"

class MyLSystem: public LSystem {
public:
  void drawSegment() {
    ofDrawRectangle(0, -5, distance, 10);
  }
};

LSystem lsystem;

//--------------------------------------------------------------
void ofApp::setup(){
  // https://paulbourke.net/fractals/lsys/
  
//  lsystem.angle = 20;
//  lsystem.distance = 2.0;
//  lsystem.addRule('F', "FF");
//  lsystem.addRule('X', "F[+X]F[-X]+X");
//  lsystem.parseAxiom("X", 5);
//
//  lsystem.angle = 22.5;
//  lsystem.distance = 5.0;
//  lsystem.addRule('F', "FF+[+F-F-F]-[-F+F+F]");
//  lsystem.parseAxiom("F", 5);
  
  // Bush
  // lsystem.addRule('F', "FF+[+F-F-F]-[-F+F+F]");
  // lsystem.parseAxiom("F", 3);
  
  // Square
//  lsystem.addRule('F', "FF+F-F+F+FF");
//  lsystem.parseAxiom("F+F+F+F", 3);
//
//  // Koch
//  lsystem.angle = 60;
//  lsystem.addRule('F', "F-F++F-F");
//  //lsystem.parseAxiom("F", 3); // curve
//  lsystem.parseAxiom("F++F++F", 3); // snowflake
  // From bourke
  lsystem.angle = 90;
  lsystem.addRule('X', "XFX-YF-YF+FX+FX-YF-YFFX+YF+FXFXYF-FX+YF+FXFX+YF-FXYF-YF-FX+FX+YFYF-");
  lsystem.addRule('Y', "+FXFX-YF-YF+FX+FXYF+FX-YFYF-FX-YF+FXYFYF-FX-YFFX+FX+YF-YF-FX+FX+YFY");
  lsystem.parseAxiom("-YF", 3);
  
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  // Translate origin to center of screen
  ofTranslate(ofGetWidth()/2,
              ofGetHeight()/2);
  // and rotate so X points up
  ofRotateDeg(-90);
  
  lsystem.angle = ofMap(mouseX, 0, ofGetWidth(), -90, 90);
  lsystem.transformToCenter(true);
  lsystem.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}
