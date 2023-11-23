#pragma once

#include "ofMain.h"

using namespace glm;

struct Agent {
  Agent(float x, float y);
  void update(float dt);
  void draw();
  
  vector<vec2> trail;
  vec2 target;
  vec2 pos;
  float angle;
  int trailIndex;
  float speed;
  float turningRadius;
  int trailLength;
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
		
    vector<Agent> agents;
};
