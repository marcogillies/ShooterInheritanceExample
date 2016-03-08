//
//  HealthPickup.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 05/03/2016.
//
//

#ifndef HealthPickup_hpp
#define HealthPickup_hpp

#include <stdio.h>
#include "Pickup.hpp"

/*
 *  a Pickup that adds health to the player
 */
class HealthPickup : public Pickup
{
    float health;
    
public:
    /*
     * parameters:
     * x, y: position
     * _health: amount of health to add
     */
    HealthPickup(float x, float y, float _health);
    
    ~HealthPickup();
    
    // apply the pickup to the player
    virtual void apply(Player *player);
    
    // draw the pickup
    virtual void subclassDraw();
};

#endif /* HealthPickup_hpp */
