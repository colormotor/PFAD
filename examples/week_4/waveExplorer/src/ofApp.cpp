#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(60);
    
    //sun stuff
    numWaveVertices = 50;//careful if you increase this number too much you will slow your framerate down.

    timeCount = 0;
    exportVectorGraphics = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    waveAmplitude = ofGetHeight() / 10;
    // try remove the multiplication by 2 to see that the shape is shorter
    shapeDepth = waveAmplitude*2;
    vertexSpacing = ofGetWidth() / numWaveVertices;

    timeCount += 0.01;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
        
    if (exportVectorGraphics){
        ofBeginSaveScreenAsSVG("waves_"+ofGetTimestampString()+".svg");// so our svg names are unique & don't over-write eachother
//        ofBeginSaveScreenAsPDF("waves_"+ofGetTimestampString()+".pdf");// so our svg names are unique & don't over-write eachother
    }
    
    
    
    float baseResolution = ofMap(mouseY,0,ofGetHeight(),0.0001,0.001,true);
    float offsetAmt = ofMap(mouseX,0,ofGetWidth(),0,0.1,true);
  
    for(int y = 0; y < ofGetHeight(); y+=waveAmplitude){

        float greyValue = ofMap(y,0,ofGetHeight(),250,0);
        
        float yResolutionOffset = y*baseResolution;
        float yOffset = y*offsetAmt;


        ofPushMatrix();
        //translate down
        ofTranslate(0,y);

        //draw grey wave shape
        ofSetColor(greyValue);

        ofBeginShape();
        //gives us a sqaure bottom
        ofVertex(0, shapeDepth);

        for (int v = 0; v <= numWaveVertices; v++)
        {
            float waveVertPhase = (v * yResolutionOffset) + yOffset;
            //wavestep is our amplitude of the wave
            float vertY;

             vertY = ofNoise(waveVertPhase+timeCount) * waveAmplitude;

            //vertY = sin(waveVertPhase+timeCount) * (waveAmplitude/2);


            //control vertex for curves
            if(v==0){
                //need an extra at end & start as our control vertices
                //doesn't seem to export nicely if this one is a curveVertex
                ofVertex(v*vertexSpacing,vertY);
            }

            //curve vertex for each point on the wave
            ofCurveVertex(v*vertexSpacing,vertY);
//            ofVertex(v*vertexSpacing,vertY);

            //control vertex for curves
            if(v == numWaveVertices){
                //need an extra at end & start as our control vertices
                ofCurveVertex(v*vertexSpacing,vertY);
            }

        }

        //gives us a sqaure bottom
        ofVertex(ofGetWidth(), shapeDepth);

        ofEndShape();
        ofPopMatrix();


    }

    if(exportVectorGraphics){
        ofEndSaveScreenAsSVG();
//        ofEndSaveScreenAsPDF();
        exportVectorGraphics = false;
    }
    
}

void ofApp::keyPressed(int key)
{
    if(key == 's'){
        exportVectorGraphics = true;
    }
    
}
