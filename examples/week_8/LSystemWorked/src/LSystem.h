#pragma once
#include "ofMain.h"

struct Rule{
  char predecessor;
  string successor;
};

class LSystem {
public:
  LSystem();
  void parseAxiom(const std::string& axiom, int numIterations);
  void addRule(char predecessor,
               const string& successor);
  void draw();
  
  /// To customize drawing, ovverride this by inheriting from LSystem
  virtual void drawSegment();
  
  // Calling this before draw will try to center the L-system
  // (assuming our origin as at the center of the window)
  void transformToCenter(bool scale=true);
  
  // Change these to
  float angle = 60.0;
  float distance = 10.0;
private:
  string findRule(char c);
  
  string lsystem;
  vector<Rule> rules;
};


