#include "ofApp.h"

using namespace glm;

struct Cell {
  Cell(float x, float y) {
    pos = vec2(x, y);
    radius = 0.5;
    targetRadius = 0;
    intersects = false;
  }
  
  void resize(const vector<Cell>& cells,
              float maxSize=300) {
    /*
    - This method finds the closest cell to this cell
    - It calculates the distance from this.pos to the edge of that cell
    - If the distance is less than zero it sets intersects to true
    - Otherwise it sets the radius to the distance
    */
    float closest = 1000000000; // big number
    
    for (int i = 0; i < cells.size(); i++) {
      float d = distance(pos, cells[i].pos) - cells[i].targetRadius;
      if (d < closest) {
        closest = d;
        targetRadius = d;
      }
    }
    
    targetRadius = MIN(targetRadius, maxSize);
    
    if (closest < 0) {
      intersects = true;
    }
  }

  void draw() {
    ofNoFill();
    ofSetColor(255);
    ofDrawCircle(pos, radius);
  }
  
  vec2 pos;
  float radius;
  float targetRadius = 0;
  bool intersects = false;
};

vector <Cell> cells;

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  
  // Create a new cell in a random position
  Cell c = Cell(
      ofRandom(0, ofGetWidth()),
      ofRandom(0, ofGetHeight())
                );

  //Call the resizeCells method
  c.resize(cells);

  //if there is still a cell add the cells to the array
  if (!c.intersects) {
    cells.push_back(c);
  }

  for (int i = 0; i < cells.size(); i++) {
    //draw the cells
    cells[i].radius += (cells[i].targetRadius - cells[i].radius) * 0.1;
    cells[i].draw();
  }
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
