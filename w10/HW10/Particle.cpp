//
//  Particle.cpp
//  particleSystem
//
//  Created by peterobbin on 10/30/16.


#include "Particle.h"
// using the constructor to initialize all the variables
Particle::Particle(ofVec2f position)
:mPosition(position)
, mVelocity( ofRandom(-2.f, 2.f), ofRandom(-2.f, 2.f))
, mAcceleration(ofVec2f(0))
, mLifeSpan(180.f)
{
    
    }
//-------------------------------------
void Particle::resetForces()
{
        // reset the acceleration
        mAcceleration *= 0;
    }
//-------------------------------------
void Particle::applyForce(ofVec2f force)
{
        // adding for to acceleration
        mAcceleration += force;
    }
//-------------------------------------
void Particle::update(float multiplier)
{
        // apply accelearation to velocity
        mVelocity += mAcceleration;
        mPosition += mVelocity * multiplier;
    
        // decreasing the particle life
        if (mLifeSpan > 0){
                mLifeSpan -= 5.f;
            }
    
    }
//-------------------------------------
void Particle::draw()
{
        if( mLifeSpan > 1000 ){
                // new born particle will be brighter
                ofSetColor(mLifeSpan);
            } else if ( mLifeSpan <= 1000 ){
                    // do some sparkle!
                ofSetColor(255, ofRandom(0,70), 0);
                
                };
    
        // closer particle is smaller
        ofDrawCircle(mPosition, 3.f * ofMap(mLifeSpan, 0, 400.f, 0, 1.f));
    
    }
