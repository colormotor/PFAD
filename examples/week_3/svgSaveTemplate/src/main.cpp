#include "ofMain.h"
#include "ofApp.h" // includes the whole contents of ofApp.h into this file
									 // so we can initialize OF and run the functionalities we
									 // specified

bool autoClear = false;

int main( ) {
  // Change your window size here
  int width = 640;
  int height = 480;
  
  ofGLFWWindowSettings settings;
  settings.doubleBuffering = autoClear;
  settings.setSize(width, height);
  settings.windowMode = OF_WINDOW;
  
  auto mainWindow = ofCreateWindow(settings);
  auto mainApp = make_shared<ofApp>();
  mainWindow->setWindowTitle("My app");
  ofRunApp(mainWindow, mainApp);//new ofApp());
  ofRunMainLoop();
}
