#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
using namespace cv;

class OpticalFlow {
public:
  OpticalFlow()
  {
    hasFlow = false;
  }
  
  void setup(float scaleFactor_) {
    scaleFactor = scaleFactor_;
  }
  
  void addPixels(const ofPixels& pixels) {
    if (images.size() > 1) {
      images.pop_front();
    }
    
    ofxCvGrayscaleImage image;
    //image.allocate(pixels.getWidth(), pixels.getHeight());
    if (pixels.getPixelFormat() == OF_PIXELS_GRAY) {
      image.setFromPixels(pixels);
    }else{
      ofxCvColorImage cimage;
      cimage.setFromPixels(pixels);
      image = cimage;
    }
    
    image.resize(scaleFactor*image.getWidth(), scaleFactor*image.getHeight());
    image.flagImageChanged();
    images.push_back(image);
    
    if (images.size() > 1) {
      computeFlow();
      hasFlow = true;
    }
  }

  void computeFlow() {
    cv::Mat flow;
    cv::calcOpticalFlowFarneback( images[0].getCvMat(), images[1].getCvMat(), flow, 0.7, 3, 11, 5, 5, 1.1, 0 );
    //Split flow into separate images
    vector<cv::Mat> flowPlanes;
    cv::split( flow, flowPlanes );
    //Copy float planes to ofxCv images flowX and flowY
    //we call this to convert back from native openCV to ofxOpenCV data types
    IplImage iplx = cvIplImage(flowPlanes[0]);
    flowX = &iplx;
    IplImage iply = cvIplImage(flowPlanes[1]);
    flowY = &iply;
  }
  
  glm::vec2 getFlow(int x, int y) {
    if (!hasFlow)
      return glm::vec2(0,0);
    
    x = scaleFactor * x;
    y = scaleFactor * y;
    int w = flowX.getWidth();
    int h = flowX.getHeight();
    float *flowXPixels = flowX.getPixelsAsFloats();
    float *flowYPixels = flowY.getPixelsAsFloats();
    float fx = flowXPixels[ x + w * y ];
    float fy = flowYPixels[ x + w * y ];
    return glm::vec2(fx, fy);
  }
  
  void drawFlow() {
    if (!hasFlow)
      return;
    
    ofPushMatrix();
    ofScale( 1.0/scaleFactor, 1.0/scaleFactor );
    int w = flowX.getWidth();
    int h = flowX.getHeight();
    //Optical flow
    float *flowXPixels = flowX.getPixelsAsFloats();
    float *flowYPixels = flowY.getPixelsAsFloats();
    for (int y=0; y<h; y+=5) {
        for (int x=0; x<w; x+=5) {
            float fx = flowXPixels[ x + w * y ];
            float fy = flowYPixels[ x + w * y ];
            //Draw only long vectors
            if ( fabs( fx ) + fabs( fy ) > 1 ) {
                ofDrawRectangle( x-0.5, y-0.5, 1, 1 );
                ofDrawLine( x, y, x + fx, y + fy );
            }
        }
    }
    ofPopMatrix();
  }
  
  bool hasFlow;
  ofxCvFloatImage flowX, flowY;    //Resulted optical flow in x and y axes
  float scaleFactor;
  deque<ofxCvGrayscaleImage> images;
};

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

  ofVideoGrabber video;
	bool calculatedFlow;
  OpticalFlow flow;
};
