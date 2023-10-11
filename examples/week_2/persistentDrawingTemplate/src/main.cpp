#include "ofMain.h"
#include "ofApp.h" // includes the whole contents of ofApp.h into this file
									 // so we can initialize OF and run the functionalities we
									 // specified


// Set your width and height here
// we do this to use the values later
#define APP_WIDTH    640
#define APP_HEIGHT   480

int main( ) {
#if AUTO_CLEAR
  // Your normal setup
  ofSetupOpenGL(APP_WIDTH, APP_HEIGHT, OF_WINDOW);      // <-------- setup the GL context
  ofRunApp( new ofApp());
#else
	ofGLFWWindowSettings settings;
	settings.doubleBuffering = false;
	settings.setSize(APP_WIDTH, APP_HEIGHT);
	settings.windowMode = OF_WINDOW;

	auto mainWindow = ofCreateWindow(settings);
	auto mainApp = make_shared<ofApp>();

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
#endif
}
