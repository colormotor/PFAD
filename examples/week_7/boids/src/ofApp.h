#pragma once

#include "ofMain.h"
#include "ofxGui.h"

using namespace glm;

class Boid{
public:
    Boid(int index_, const vec2& pos_, const ofColor& color_);
    
    void draw();
    void update(const vector<Boid>& boids, //vector<Boid> boids, //const vector<Boid>& boids,const vector<Boid>& boids,
                float speedlimit,
                float separationFactor,
                float cohesionFactor,
                float alignmentFactor,
                float checkdist,
                float bouncespeed,
                float dt);
  
  
private:
    void checkBoundary(float speed);
//    void separation(const vector<Boid>& boids, float factor);
//    void cohesion(const vector<Boid>& boids, float factor);
//    void alignment(const vector<Boid>& boid, float factor);
//  
    void flock(const vector<Boid>& boids, //vector<Boid> boids, //const vector<Boid>& boids,const vector<Boid>& boids,
               float separationFactor,
               float cohesionFactor,
               float alignmentFactor,
               float checkdist);
    
    vec2 velocity;
    vec2 position;
    float distToCheck;
    ofColor color;
    int index;
};

class ofApp : public ofBaseApp{
	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
		
    vector<Boid> boids;
  
    //Gui
    ofxPanel gui;

    ofxFloatSlider speedlimit;
    ofxFloatSlider separation;
    ofxFloatSlider cohesion;
    ofxFloatSlider alignment;

    ofxFloatSlider radius;
    ofxFloatSlider checkdist;
    ofxFloatSlider bounce;
};
