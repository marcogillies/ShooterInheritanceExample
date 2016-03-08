//
//  PickUp.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 05/03/2016.
//
//

#ifndef PickUp_hpp
#define PickUp_hpp

#include <stdio.h>
#include "GameObject.hpp"

class Player;

/*
 *  a super class for pickups
 */
class Pickup : public GameObject
{
    // if it collides with the player it applies the
    // pickup
    virtual void collisionResponse(GameObject *other);
public:
    // parameters: x and y position
    Pickup(float x, float y);
    
    ~Pickup();
    
    // applies the pickup to a player
    // to be overriden in the sub classes
    virtual void apply(Player *player) = 0;
};

#endif /* PickUp_hpp */
