#include "simpleParticle.h"

//-----------------------------------------------
SimpleParticle::SimpleParticle(vec2 _loc)
{
    loc = vec2(_loc);
    vel = vec2(0,0);
    accel = vec2(0,0);
    lifespan =  150;

    agingRate = 2;
    radius = 10;
    color = ofColor(255);

}
//------------------------------------------------------------------
void SimpleParticle::applyForce(vec2 f)
{
    accel += f;
}
//------------------------------------------------------------------
void SimpleParticle::update()
{
    vel+=accel;
    loc+=vel;
    accel*=0;

    lifespan -= agingRate;
    lifespan = ofClamp(lifespan, 0, 255);

}
//-----------------------------------------------------------------------
bool SimpleParticle::isDead()
{
    if (lifespan <= 0) return true;
    else return false;
}
