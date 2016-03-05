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

// A class representing a player
// It is a subclass of GameObject because it has a position
class Enemy : public  Entity
{
protected:
    float damage;
    
    virtual void collisionResponse(GameObject *other);
public:
    // The constructor takes the position of the player and
    // passes is to the super class (GameObject) constructor
    // It also creates an inventory and adds a weapon to it
    Enemy(float x, float y, float h, float s, float d);
    
    ~Enemy();
    
    // draw the player
    // move the player constantly forward then
    // draw a square for the player and a
    // health bar
    virtual void subclassDraw();
    
};


#endif /* Enemy_hpp */
