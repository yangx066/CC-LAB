//  ParticleSystem.hpp
//  particleSystem
//
//  Created by peterobbin on 10/30/16.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.h"

class ParticleSystem{
    public:
        ParticleSystem(ofVec2f position);
        void update(ofVec2f force);
        void draw();
    
    
        vector<Particle>    mParticleList; // vectors are like fancy, high-end arrays
        ofVec2f             mPosition;
        int                 mEmitRate;
        bool                mIsAddingParticles;
    
    };
