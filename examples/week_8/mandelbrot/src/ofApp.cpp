#include "ofApp.h"

// Our "focus" point
float xpos = -0.7315572473394835; // real
float ypos = 0.20381401429483736; // imaginary
// Another point to explore
//float xpos = -0.74454996026480837012;
//float ypos = 0.1217213839516347233;

// This is our zoom value, larger will be closer
float zoom = 100;
// The number of iterations. Higher will give more details
int maxiterations = 150;

//--------------------------------------------------------------
void ofApp::setup(){
  img.allocate(0.75*ofGetWidth(), 0.75*ofGetHeight(), OF_IMAGE_GRAYSCALE);
}

float mandelbrot(float cx, float cy) {
  // we test, as we iterate z = z^2 + c does z tend towards infinity?
  // c here represents our coordinates on the plane and z starts from zero
  // we set this to cx, cy since for the first iteration z = c
  float za = cx;
  float zb = cy;
  float n = 0;
  float aa, bb;
  while (n < maxiterations) {
    // complex multiplication is
    // (a + i*b) * (c + i*d) = (ac - bd) + i*(ad + bc)
    // with a square (a + i*b) * (a + i*b) it simplifies to
    // (a*a - b*b) + i*(2ab)
    aa = za * za;
    bb = zb * zb;
    // Check for divergence here to avoid extra multiplications
    // Infinty in our finite world is simple, just check if abs(z) > 2
    // we avoid the square root here so it is 4
    if (aa + bb >= 4.0) {
        break; // Bail
    }

    float twoab = 2.0 * za * zb;
    za = aa - bb + cx;
    zb = twoab + cy;
    n++;
  }
  
  // This makes it smoother
  // https://www.codingame.com/playgrounds/2358/how-to-plot-the-mandelbrot-set/adding-some-colors
  return n + 1.0 - log(log2(sqrt(aa + bb)));
  return n;
}

//--------------------------------------------------------------
void ofApp::update(){
  zoom = ofMap(mouseX, 0, ofGetWidth(), 150, 3000);
  
  int width = img.getWidth();
  int height = img.getHeight();
  
  // We will be directly modifying pixels of the image
  ofPixels& px = img.getPixels();
  
  // Get bytes per pixel of image
  int bpp = px.getBytesPerPixel();
  
  float w = (float)width/zoom;
  float h = (float)height/zoom;
  float xmin = ofMap(0, 0, width, -w/2, w/2);
  float xmax = ofMap(width, 0, width, -w/2, w/2);
  float ymin = ofMap(0, 0, height, -h/2, h/2);
  float ymax = ofMap(height, 0, height, -h/2, h/2);
    
  // Calculate amount we increment x,y for each pixel
  float dx = (xmax - xmin) / width;
  float dy = (ymax - ymin) / height;

  // Start y
  float cy = ymin + ypos;

  for (int i = 0; i < height; i++) {
    // Start x
    float cx = xmin + xpos;

    for (float j = 0; j < width; j++) {
      float n = mandelbrot(cx, cy);
      //
      int ind = i*width*bpp + j*bpp;
      if (n == maxiterations) {
        px[ind] = 0;
        //px[ind+1] = 0;
        //px[ind+2] = 0;
      } else {
        n = n / maxiterations;
        int v = (int)(n*255);
        px[ind] = v; // Here you might want to use a palette to have a colored set
        //px[ind+1] = v;
        //px[ind+2] = v;
      }
      cx += dx;
    }
    cy += dy;
  }
  
  img.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  img.draw(0, 0, ofGetWidth(), ofGetHeight());
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
