#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        //custom functions
        //void means nothing is returned
        void textureTile(int x, int y, int degrees, float scale, ofColor color, bool fill);
    
        //a boolean is returned
        bool isEvenNumber(int num);
    
    
        int numOfTilesX;
        int numOfTilesY;
    
        float tileSizeX;
        float tileSizeY;
    
};
