#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void mousePressed(int x, int y, int button) override;
		void windowResized(int w, int h) override;
  
  ofImage image;
};
