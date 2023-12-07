#include "ofApp.h"

//---------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(640,480);
    rTarget = 255;
    gTarget = 182;
    bTarget = 193;
    threshold = 2.5;
}
//---------------------
void ofApp::update(){
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew()){

        // these are used in the search for the location of the pixel
        // whose color is the closest to our target color.
        closestColorX = 0;
        closestColorY = 0;
        int w = vidGrabber.getWidth();
        int h = vidGrabber.getHeight();
        count = 0;

        for (int y=0; y<h; y++) {
            for (int x=0; x<w; x++) {
                
                // Extract the color components of the pixel at (x,y)
                // from myVideoGrabber (or some other image source)
                ofColor colorAtXY = vidGrabber.getPixels().getColor(x, y);
                float rAtXY = colorAtXY.r;
                float gAtXY = colorAtXY.g;
                float bAtXY = colorAtXY.b;
                
                float colorDistance = ofDist(rAtXY, gAtXY, bAtXY, rTarget, gTarget, bTarget);
                //use this if your computer is slow. It's faster as it doesn't do the root calculation
                //float colorDistance = ofDistSquared(rAtXY, gAtXY, bAtXY, rTarget, gTarget, bTarget);
                
                //if color similar then add coordinates to sum
                if(colorDistance < threshold){
                    closestColorX+= x;
                    closestColorY+= y;
                    count++;
                }
            }
        }
        
        //calculate the average coordinate
        if (count>0) {
            closestColorX = closestColorX / count;
            closestColorY = closestColorY / count;
        }
    }
}

//---------------------
void ofApp::draw(){
    vidGrabber.draw(0,0);
    ofDrawBitmapString(threshold, 20, 20);
    ofDrawEllipse (closestColorX, closestColorY, 40,40);
}
//---------------------
void ofApp::mousePressed(int x, int y, int button){
    ofColor tempColor = vidGrabber.getPixels().getColor(x, y);
    rTarget = tempColor.r;
    gTarget = tempColor.g;
    bTarget = tempColor.b;
}
//-----------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_UP) threshold+=1;//UP ARROW
    else if (key==OF_KEY_DOWN) threshold-=1;//DOWN ARROW
}
