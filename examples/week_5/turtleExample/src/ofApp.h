#pragma once

#include "ofMain.h"

using namespace glm;

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
		
    //////////////////////////////////////////////////
    /// Turtle implementation
    // Interface
    void drawLastTurtlePath(); 
    void turtleReset(float x, float y);
    void turtleGoto(float x, float y);
    void turtleForward(float distance);
    void turtleRight(float degrees);
    void turtleLeft(float degrees);
    void turtleScale(float scale);
    void turtlePenUp();
    void turtlePenDown();
  
    // internal
    void drawTurtleShape();
    void storeTurtlePos();
    void drawTurtle();
    void turtleTriangle(float size);
  
    vector<vec2> positions;
    bool showTurtle = true;
    /// End of turtle implementation
};
