// Example 3. Finding the Brightest Pixel in an Image

#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    

    ofVideoGrabber vidGrabber;
    int closestColorX, closestColorY;
    float threshold;
    int count;
};
