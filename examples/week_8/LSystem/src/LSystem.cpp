#include "LSystem.h"

using namespace glm;

LSystem::LSystem() {
}

void LSystem::parseAxiom(const std::string& axiom, int numIterations) {
  lsystem = axiom;
  cout << "Axiom: " << axiom << endl;
  for (int i = 0; i < numIterations; i++) {
    string current = "";
    for (int j = 0; j < lsystem.length(); j++) {
      current = current + findRule(lsystem[j]);
    }
    lsystem = current;
    cout << "Iteration " << (i+1) << ": " << lsystem << endl;
  }
}

void LSystem::addRule(char predecessor,
                      const string& successor) {
  rules.push_back({predecessor, successor});
}

void LSystem::draw() {
  for (int i = 0; i < lsystem.length(); i++) {
    char c = lsystem[i];
    switch (c) {
      case 'F': case 'G': case 'A':
        // draw and forward
        drawSegment();
        ofTranslate(distance, 0);
        break;
      case 'f': case 'B':
        // forward without drawing
        ofTranslate(distance, 0);
        break;
      case '+':
        // turn right
        ofRotateDeg(angle);
        break;
      case '-':
        // turn left
        ofRotateDeg(-angle);
        break;
      case '[':
        // save state
        ofPushMatrix();
        break;
      case ']':
        // restore state
        ofPopMatrix();
        break;
    }
  }
}

string LSystem::findRule(char c) {
  for (int i = 0; i < rules.size(); i++) {
    if (rules[i].predecessor == c)
      return rules[i].successor;
  }
  return string(1, c); // This creates a string with a single character
}

void LSystem::drawSegment() {
  ofSetColor(255);
  ofDrawLine(0, 0, distance, 0);
}

void LSystem::transformToCenter(bool scale) {
  // Uses GLM (3d) transformations and a matrix stack to find points of the LSystem
  std::vector <vec2> points;
  std::vector <mat4> stack;
  stack.push_back(mat4());
  // This extracts a 2d position from the 4x4 (affine 3d) matrix
#define POS vec2(stack.back()[3].x, stack.back()[3].y)
  for (int i = 0; i < lsystem.length(); i++) {
    char c = lsystem[i];
    switch (c) {
      case 'F': case 'G': case 'A':
        // draw and forward
        points.push_back(POS);
        stack.back() = glm::translate(stack.back(), glm::vec3(distance, 0.0, 0.0));
        points.push_back(POS);
        break;
      case 'f': case 'B':
        // forward without drawing
        stack.back() = glm::translate(stack.back(), glm::vec3(distance, 0.0, 0.0));
        break;
      case '+':
        // turn right
        stack.back() = glm::rotate(stack.back(), ofDegToRad(angle), vec3(0, 0, 1.0));
        break;
      case '-':
        // turn left
        stack.back() = glm::rotate(stack.back(), -ofDegToRad(angle), vec3(0, 0, 1.0));
        break;
      case '[':
        // save state
        stack.push_back(stack.back());
        break;
      case ']':
        // restore state
        stack.pop_back();
        break;
    }
  }

  // find center
  vec2 center = vec2(0, 0);
  for (int i = 0; i < points.size(); i++) {
    center += points[i];
  }
  center /= points.size();

  // Scale if necessary
  if (scale) {
    float maxSqDist = 0.0f;
    for (int i = 0; i < points.size(); i++) {
      vec2 d = points[i] - center;
      maxSqDist = MAX(maxSqDist, dot(d, d));
    }
    float radius = sqrt(maxSqDist);
    
    float destRadius = MIN(ofGetWidth(), ofGetHeight())/2;
    ofScale(destRadius/radius);
  }
  
  // Shift it all
  ofTranslate(-center);
}
