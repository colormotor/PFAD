#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sampleRate = 44100;
    bufferSize = 512;
    
    // settings for ofxMaxim.
    maxiSettings::setup(sampleRate, 2, bufferSize);
    
    ofSoundStreamSettings settings;
    
    //Not getting your microhpone correctly?
    //You should read what devices + IDs are printed to your console
    //Especially if you have an external mic
    soundStream.printDeviceList();//prints out devices to console
    //E.G. the device ID is 0 > "[OSX Core Audio: 0]" full example seen below:
    //(CONSOLE PRINT EXAMPLE): ofBaseSoundStream::printDeviceList: [OSX Core Audio: 0] Apple Inc.: MacBook Air Microphone [in:1 out:0]
    
    // by name "default" like this should work for most
    auto devices = soundStream.getMatchingDevices("default");
    if(!devices.empty()){
        // if not 0 try change the ID to your microphone device ID see comments above
        settings.setInDevice(devices[0]);
    }
    
    // This will tell the audio input to call
    // the audioIn method we defined when we receive a new sound buffer
    settings.setInListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 0;
    settings.numInputChannels = 1;//on mac can only do 1, change to 2 on windows
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    
    //sets up the soundStream object with default devices
    fft.setup(fftSize, 512, 256); //just a forward FFT
    // computes pitch-like features from fft, last parameter is the number features
    fftOctaves.setup(sampleRate, fft.getNumBins(), 12);
    cout << fft.getNumBins() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);

}

//--------------------------------------------------------------
void ofApp::draw(){
    //
    ofDrawBitmapString("Octaves",10,200);
    float xinc = (float)400 / fftOctaves.nAverages;
    
    for(int i=0; i < fftOctaves.nAverages; i++) {
        float height = fftOctaves.averages[i]*10;
        ofDrawRectangle(50 + (xinc*i),200 - height,10, height);
    }
    
    // microphone input raw audio wave
    ofDrawBitmapString("Audio Wave",10,ofGetHeight()/2 - 5);
    waveLine.draw();
    
    //scale volume
    ofDrawBitmapString("Volume:",10,ofGetHeight()*0.75 - 5);
    ofDrawRectangle(10, ofGetHeight()*0.75, 40, scaledVol*200);
}


//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer & input){
    
    waveLine.clear();
    
    volume = 0;
    //samples are interleaved
    float numCounted = 0.0;
    double left, right;
   
    for (unsigned int i = 0; i < input.getNumFrames(); i++){
        left = input[i*input.getNumChannels()] * 0.5;
        right = input[i*input.getNumChannels()+1] * 0.5;
                
        //calculate the volume / rms
        volume += left * left;
        volume += right * right;
        numCounted += 2.0;
        
        wave = left + right; // we already divided by 2 above
        
        // Calculate fft and octaves
        if (fft.process(wave)) { //is the window buffer full?
            // mags = fft.getMagnitudes();
            // phases = fft.getMagnitudes();
            fftOctaves.calculate(fft.getMagnitudes());
        }
        
        //viusalise sound wave
        waveLine.addVertex(ofMap(i, 0, input.getNumFrames() - 1, 0, ofGetWidth()), ofMap(input[i*input.getNumChannels()], -1, 1, 0, ofGetHeight()));
    }
    
    
    volume /= numCounted;//mean
    volume = sqrt(volume);//square root
    if (isinf(volume)) volume = 0;
    
    smoothedVol *= 0.93;
    smoothedVol += volume * 0.07;
}

//--------------------------------------------------------------
void ofApp::exit() {
    ofSoundStreamClose();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
