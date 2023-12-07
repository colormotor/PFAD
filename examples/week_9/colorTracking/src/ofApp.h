#pragma once
#include "ofMain.h"

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
};
