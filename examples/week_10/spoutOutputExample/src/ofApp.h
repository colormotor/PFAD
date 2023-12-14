#pragma once

#include "ofMain.h"
#include "ofxSpout.h"


class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

    void sendScreen();
  
    ofxSpout::Sender sender;
};
