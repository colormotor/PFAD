#pragma once

#include "ofMain.h"

using namespace glm;
//
//struct Circle {
//  Circle(float x, float y, float radius_);
//  Circle(const vec2& pos_, float radius_);
//
//  void draw();
//
//  vec2 pos;
//  float radius;
//};

class Circle {
public:
  Circle(float x, float y, float radius_);
  Circle(const vec2& pos_, float radius_);
  
  void draw();
private:
  vec2 pos;
  float radius;
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
		
    std::vector<Circle> circles;
    float curRadius;
};
