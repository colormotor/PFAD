#pragma once // this includes this file only once

#include "ofMain.h"

// We will use this flag to specify if we want
// an animaton, or if we want each frame to incrementally
// draw on the window
#define AUTO_CLEAR false // Set this to 0 (or false) to not clear each frame

// This is a C++ definition of a class.
// OpenFrameworks uses this to define your "App"
// It will be used in main.cpp to actually run the application
class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
