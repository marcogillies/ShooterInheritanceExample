//
//  Enemy.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>

#include <stdio.h>
#include "Entity.hpp"

// A class representing an enemy
// It is a subclass of Entity because it has health and a speed
class Enemy : public  Entity
{
protected:
    // damage done in collision
    float damage;
    
    // respond to a collision with another object
    // if the other object is a player it will do
    // damage to it
    virtual void collisionResponse(GameObject *other);
public:
    // The constructor takes the position of the enemy and
    // passes is to the super class (Entity) constructor
    Enemy(float x, float y, float h, float s, float d);
    
    ~Enemy();
    
    // draw the enemy
    // move the enemy constantly forward then
    // draw a square for the enemy and a
    // health bar
    virtual void subclassDraw();
    
};


#endif /* Enemy_hpp */
