#include "ofApp.h"

float BouncyPixel::k = 70;
float BouncyPixel::friction = 1;

BouncyPixel::BouncyPixel(int imageX, int imageY):
imageX(imageX), imageY(imageY) {
  pos = 0.0;
  velocity = 0.0;
  target = 0.0;
}

// Simple 1d model of a spring with friction
// can be trivially extended to 2d or 3d with vectors
// for force, target, pos and velocity
void BouncyPixel::update(ofPixels& px, float dt) {
  target = px.getColor(imageX, imageY).getLightness()/255;
  float force = (target - pos)*k;
  float accel = force - velocity*friction;
  velocity = (velocity + accel*dt);
  pos = pos + velocity*dt;
}

void BouncyPixel::draw(const ImagePalette& palette) {
  ofSetColor(palette.color(pos, 0.0));
  ofDrawCircle(imageX, imageY, 10*pos);
}


//--------------------------------------------------------------
void ofApp::setup(){
  // We don't need the full resolution here
  vidGrabber.setup(ofGetWidth(), ofGetHeight());
  palette.load("palette.png");
  
  int step = 8;
  for (int y = 0; y < vidGrabber.getHeight(); y+=step) {
    for (int x = 0; x < vidGrabber.getWidth(); x+=step) {
      bpixels.push_back(BouncyPixel(x, y));
    }
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  vidGrabber.update();
  ofPixels& px = vidGrabber.getPixels();
  for (int i = 0; i < bpixels.size(); i++)
    bpixels[i].update(px, 0.01);
}

//--------------------------------------------------------------
void ofApp::draw(){
  if (!showEffect) {
    ofSetColor(255);
    vidGrabber.draw(0, 0, ofGetWidth(), ofGetHeight());
  } else {
    // Replace the contents of this "else" block with your code
    ofPushMatrix();
    
    // Do something with the pixels

    int w = vidGrabber.getWidth();
    int h = vidGrabber.getHeight();

    // Scale to match video and window
    ofScale((float)ofGetWidth()/w,
            (float)ofGetHeight()/h);

    for (int i = 0; i < bpixels.size(); i++)
      bpixels[i].draw(palette);
    
    ofPopMatrix();
  }
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == ' ')
    showEffect = !showEffect;
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}


//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

