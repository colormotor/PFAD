#pragma once

#include "ofMain.h"

using namespace glm;

struct Agent {
  Agent(const vec2& pos_, const ofColor& color_);
  void update(float dt);
  void draw();
  void updateTrail(const vec2& pos);
  void drawTrail();
  vec2 steerForce(const vec2& desiredVelocity);
  void wrapBounds();
  void drawFlowField();
  
  vector<vec2> trail;
  int trailLength;
  int trailIndex;
  
  vec2 target;
  vec2 pos;
  vec2 velocity;
  ofColor color;

  static float t;
  static float maxSpeed;
  static float maxForce;
  static float noiseScale;
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
