#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
   
        int numWaveVertices;
        float timeCount;
        bool exportVectorGraphics;
    
    
        float waveAmplitude;
            // try remove the multiplication by 2 to see that the shape is shorter
        float shapeDepth;
        float vertexSpacing;

};
