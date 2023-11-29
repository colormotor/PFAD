#pragma once

#include "ofMain.h"

using namespace glm;

class ImagePalette {
public:
  ImagePalette() {}
  
  /// Load the palette
  void load(const std::string& imagePath) {
    palette.load(imagePath);
  }
  
  /// Sample a color from the palette, with a value of x, and y (optional) between 0 and 1
  ofColor color(float x, float y=0.0) const {
    int paletteCol = ofMap(x, 0, 1, 0, palette.getWidth()-1, true);
    int paletteRow = ofMap(y, 0, 1, 0, palette.getHeight()-1, true);
    return palette.getColor(paletteCol, paletteRow);
  }
  
  ofImage palette;
};

class BouncyPixel {
public:
  BouncyPixel(int imageX, int imageY);
  void update(ofPixels& px, float dt);
  void draw(const ImagePalette& palette);
  
  int imageX;
  int imageY;
  
  float velocity;
  float target;
  float pos;
  
  static float k;
  static float friction;
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
    vector<BouncyPixel> bpixels;
    ofVideoGrabber vidGrabber;
    bool showEffect = true;
};
