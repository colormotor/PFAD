#pragma once
#include "ofMain.h"

using namespace glm;

class Snake {
public:
  Snake() {}
  void setup(ofColor c_) {
    targetC = c_;
  }
  
  void addLocation(float x, float y) {
    points.push_back(vec2(x, y));
    if (points.size() > 150)
      points.pop_front();
  }
  
  void draw() {
    if (!points.size())
      return;
    
    ofBeginShape();
    for (int i = 0; i < points.size(); i++)
      ofVertex(points[i]);
    ofEndShape();
  }
  
  deque<vec2> points;
  ofColor targetC;
};
class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void keyPressed(int key);
    
    ofVideoGrabber vidGrabber;
    int closestColorX, closestColorY;

    float rTarget;
    float gTarget;
    float bTarget;
    float threshold;

    int count;
    ofImage img;
    Snake snake;
};
