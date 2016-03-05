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

class Pickup : public GameObject
{
    virtual void collisionResponse(GameObject *other);
public:
    Pickup(float x, float y);
    
    ~Pickup();
    
    virtual void apply(Player *player) = 0;
};

#endif /* PickUp_hpp */
