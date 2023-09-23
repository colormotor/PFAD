#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

//	ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context
//
//  ofGLFWWindowSettings settings;
//    settings.doubleBuffering = false;
//    settings.setSize(640, 480);
//    settings.windowMode = OF_WINDOW;
//
//    auto mainWindow = ofCreateWindow(settings);
//    auto mainApp = make_shared<ofApp>();
    
  ofGLFWWindowSettings settings;
  settings.doubleBuffering = false;
  settings.setSize(640, 480);
  settings.windowMode = OF_WINDOW;
      
  auto mainWindow = ofCreateWindow(settings);
  auto mainApp = make_shared<ofApp>();

  ofRunApp(mainWindow, mainApp);
  ofRunMainLoop();
  
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new ofApp());

}
