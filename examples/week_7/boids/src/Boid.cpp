#include "Boid.h"

// Constructor
Boid::Boid(int index_, const vec2& pos_, const ofColor& color_){
  index = index_;
  position = pos_;
  color = color_;
  velocity = vec2(ofRandom(-1,1),ofRandom(-1,1))*100;
}

//--------------------------------------------------------------
void Boid::update(vector<Boid> boids,
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

void Boid::flock(vector<Boid> boids,
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
  
  // Uncomment to see when boids touch boundary
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
}
