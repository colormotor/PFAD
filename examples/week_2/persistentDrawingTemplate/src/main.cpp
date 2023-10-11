#include "ofMain.h"
#include "ofApp.h" // includes the whole contents of ofApp.h into this file
									 // so we can initialize OF and run the functionalities we
									 // specified

int main( ) {
  // Change your window size here
  int width = 640;
  int height = 480;
  // this will be passed into the intialization below
#if AUTO_CLEAR
  // Your normal setup
  ofSetupOpenGL(width, height, OF_WINDOW);      // <-------- setup the GL context
  ofRunApp( new ofApp());
#else
	ofGLFWWindowSettings settings;
	settings.doubleBuffering = false;
	settings.setSize(width, height);
	settings.windowMode = OF_WINDOW;

	auto mainWindow = ofCreateWindow(settings);
	auto mainApp = make_shared<ofApp>();

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
#endif
}
