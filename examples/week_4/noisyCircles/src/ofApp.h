#pragma once

#include "ofMain.h"


class SvgSaver {
public:
  SvgSaver() {}
  
  // Place this before drawing
  void begin(){
    if (saving) {
      ofBeginSaveScreenAsSVG(filename);
    }
  }
  
  // Place this after drawing
  void end(){
    if (saving) {
      ofEndSaveScreenAsSVG();
      cout << "Saved svg" << endl;
      saving = false;
    }
  }
  
  // Call this inside keyPressed
  void save(const std::string& filename_) {
    filename = filename_;
    saving = true;
  }
  
  std::string filename;
  bool saving = false;
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
	
  SvgSaver svg;
  
};
