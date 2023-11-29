#pragma once

#include "ofMain.h"

class ImagePalette {
public:
  ImagePalette() {}
  
  /// Load the palette
  void load(const std::string& imagePath) {
    palette.load(imagePath);
  }
  
  /// Sample a color from the palette, with a value of x, and y (optional) between 0 and 1
  ofColor color(float x, float y=0.0) {
    int paletteCol = ofMap(x, 0, 1, 0, palette.getWidth()-1, true);
    int paletteRow = ofMap(y, 0, 1, 0, palette.getHeight()-1, true);
    return palette.getColor(paletteCol, paletteRow);
  }
  
  ofImage palette;
};

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void mousePressed(int x, int y, int button) override;
		void windowResized(int w, int h) override;
  
  ImagePalette palette;
  float t = 0.0;
};
