#include "ofApp.h"

// Constructor
Boid::Boid(int index_, const vec2& pos_, const ofColor& color_){
  index = index_;
  position = pos_;
  color = color_;
  velocity = vec2(ofRandom(-1,1),ofRandom(-1,1))*100;
}

//--------------------------------------------------------------
void Boid::update(const vector<Boid>& boids, //vector<Boid> boids, //const vector<Boid>& boids,
                  float speedlimit,
                  float separationFactor,
                  float cohesionFactor,
                  float alignmentFactor,
                  float distToCheck,
                  float bouncespeed,
                  float dt){
    
  
  //Keep Boids in a sphere
  checkBoundary(bouncespeed);

  //Add flocking behavior
  flock(boids,
        separationFactor,
        cohesionFactor,
        alignmentFactor,
        distToCheck);
  
  //Limit how fast a boid can go
  if(length(velocity) > speedlimit){
      velocity = normalize(velocity) * speedlimit;
  }
  
  position += velocity*dt;
}

void Boid::draw(){
  ofPushMatrix();
  ofTranslate(position);
  float angle = atan2(velocity.y, velocity.x);
  ofRotateRad(angle);
  ofScale(5);
  ofSetColor(color);
  //ofDrawCircle(0, 0, 1);
  ofDrawTriangle(0, -1,
             2, 0,
             0, 1);
  ofPopMatrix();
}
//
//void separation(const vector<Boid>& boids, float factor) {
//}
//
//void cohesion(const vector<Boid>& boids, float factor) {
//}
//
//void alignment(const vector<Boid>& boid, float factor) {
//}

void Boid::flock(const vector<Boid>& boids, //vector<Boid> boids, //const vector<Boid>& boids,
                 float separationFactor,
                 float cohesionFactor,
                 float alignmentFactor,
                 float distToCheck){
    vec2 separation = vec2(0,0);
    vec2 cohesion = vec2(0,0);
    vec2 align = vec2(0,0);
    int numCohesionNeighbours = 0;
    int numAlignNeighbours = 0;
    int numSeparationNeighbors = 0;
  
    // query the entire flock
    for(int i = 0 ; i < boids.size(); i++){
      if (i==index)
        continue;
      
        float dist = distance(position, boids[i].position);
        if(dist < distToCheck){
            // it's close enough >> add a difference vector
          separation += position - boids[i].position + vec2(ofRandom(-1,1), ofRandom(-1,1));
          numSeparationNeighbors++;
        }
        
        if(dist < distToCheck+20){
            // its close enough >> add its position to the avarage
          cohesion += boids[i].position;
            numCohesionNeighbours++;
        }
        
        if(dist < distToCheck+10){
            // it's close enough >> add its velocity to the avarage
          align += boids[i].velocity;
          numAlignNeighbours++;
        }
    }
    
    separation *= separationFactor;
    velocity += separation;
    
    if(numCohesionNeighbours == 0){
      cohesion = vec2(0,0);
    } else{
      cohesion /= numCohesionNeighbours;
      cohesion -= position;
      cohesion *= cohesionFactor;
    }
    
    velocity += cohesion;
    
    if(numAlignNeighbours == 0){
      align = vec2(0,0);
    }else{
      align /= numAlignNeighbours;
      align *= alignmentFactor;
    }
  
    velocity += align;
}

//If the distance between the Boid and the center is greater
//than radius (size) of sphere then reverse the direction
void Boid::checkBoundary(float turnFactor) {
  const float margin = 5;
  float width = ofGetWidth();
  float height = ofGetHeight();
//  color = ofColor(255);
  if (position.x < margin) {
    //color = ofColor(255, 0, 0);
    velocity.x += turnFactor;
  }
  if (position.x > width - margin) {
    //color = ofColor(255, 0, 0);
    velocity.x -= turnFactor;
  }
  if (position.y < margin) {
    //color = ofColor(255, 0, 0);
    velocity.y += turnFactor;
  }
  if (position.y > height - margin) {
    //color = ofColor(255, 0, 0);
    velocity.y -= turnFactor;
  }

//    vec2 desired = vec2(0,0) - position;
//
//    //The size variable is the radius of a circle at the origin
//    if(length(desired) > size){
//        desired = normalize(desired)*bouncespeed;
//        velocity = desired - velocity;
//    }
}

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetCircleResolution(50);
  
  //GUI
  gui.setup();
//
//  gui.add(slider_speedlimit.setup("speed limit",2,1,20,200,20));
//  gui.add(slider_separation.setup("separation",0.07,0,1,200,20));
//  gui.add(slider_cohesion.setup("cohesion",0.01,0,0.5,200,20));
//  gui.add(slider_alignment.setup("alignment",0.3,0,1,200,20));
//
  gui.add(speedlimit.setup("speed limit",105,1,220));
  gui.add(separation.setup("separation",0.15,0,10));
  gui.add(cohesion.setup("cohesion",0.01,0,5));
  gui.add(alignment.setup("alignment",0.3,0,5));
  
  gui.add(checkdist.setup("check neighbors distance",30,10,60));
  gui.add(radius.setup("radius",500,50,600));
  gui.add(bounce.setup("edge bounciness",10,0.1,100));
      
  for(int i = 0; i < 10; i++){
    vec2 pos = vec2(ofRandom(0,ofGetWidth()),
                    ofRandom(0,ofGetHeight()));
    boids.push_back(Boid(i, pos, ofColor(0, 200)));
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  for(int i = 0; i < boids.size(); i++){
    boids[i].update(boids,
                    105,
                    0.15,
                    0.01,
                    0.3,
                    50,
                    10,
                    0.02);
//    boids[i].update(boids,
//                    speedlimit,
//                    separation,
//                    cohesion,
//                    alignment,
//                    checkdist,
//                    radius,
//                    bounce);
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(37, 159, 202);
  
  for(int i = 0; i < boids.size(); i++){
    boids[i].draw();
  }
  ofSetColor(255);
  gui.draw();
  ofSetColor(255);
  ofDrawBitmapString(to_string(ofGetFrameRate()), ofGetWidth()/2, 20);
}

//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
