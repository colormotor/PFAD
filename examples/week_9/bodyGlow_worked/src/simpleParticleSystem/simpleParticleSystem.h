#pragma once
#include "ofMain.h"
#include "simpleParticle.h"

using namespace glm;

class SimpleParticleSystem{

	public:
	    //class functions
  SimpleParticleSystem();
        void addParticle(float _x, float _y);
        void activateParticle(int x, int y);
        void setupAsGrid(float _size, float _agingRate, float _lifespan);
        void update();
        void draw();
        void applyForce(vec2 f);

        //class variables
        vector <SimpleParticle> particles;
        float gridCellSize;
        bool removeOffScreenParticles;
        bool removeDeadParticles;
        float lifespan;
};
