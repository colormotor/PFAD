#include "ofApp.h"
//#include "tracking.hpp"
#include "opencv2/opencv.hpp"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(60);
  video.setDeviceID(0);
  video.setDesiredFrameRate(60);
  video.initGrabber(640, 480);
  flow.setup(0.3);
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();		//Decode the new frame if needed

	if ( video.isFrameNew() )
  {
    flow.addPixels(video.getPixels());
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 255, 255, 255);	//Set the background color
  ofSetColor(255);
  video.draw(0, 0);
  ofSetColor(0, 128, 255);
  flow.drawFlow();
  
  ofColor color;
  for (int i = 0; i < video.getHeight(); i+= 10) {
    for (int j = 0; j < video.getWidth(); j+= 10) {
      glm::vec2 f = flow.getFlow(j, i);
      color.setHsb(glm::length(f)*20, 255, 255);
      ofSetColor(color, 10);
      ofDrawCircle(j, i, glm::length(f)*3+1);
    }
  }
}
