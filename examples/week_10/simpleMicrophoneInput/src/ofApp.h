#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

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
    
    void audioIn(ofSoundBuffer & input);
    void exit();
        
    ofSoundStream soundStream;

    //Maximilian stuff
    maxiFFT fft;
    maxiFFTOctaveAnalyzer fftOctaves;
    double wave;
    int fftSize = 1024;
    int sampleRate;
    int bufferSize;
    
    float volume;
    float smoothedVol;
    float scaledVol;

    ofPolyline waveLine;
};
