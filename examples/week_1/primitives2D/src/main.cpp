#include "ofMain.h"
#include "ofApp.h"

// This is for week 2.
// We will use this as a hack to have "Persistent drawing" on both Mac and Windows
// #define SINGLEBUFFER

#define APP_WIDTH 640
#define APP_HEIGHT 480

//========================================================================
int main( ){
#ifdef SINGLEBUFFER
	ofGLFWWindowSettings settings;
	settings.doubleBuffering = false;
	settings.setSize(APP_WIDTH, APP_HEIGHT);
	settings.windowMode = OF_WINDOW;

	auto mainWindow = ofCreateWindow(settings);
	auto mainApp = make_shared<ofApp>();

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
#else
	ofSetupOpenGL(APP_WIDTH, APP_HEIGHT, OF_WINDOW);			// <-------- setup the GL context
	ofRunApp( new ofApp());
#endif
}
