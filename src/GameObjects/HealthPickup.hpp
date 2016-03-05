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

class HealthPickup : public Pickup
{
    float health;
    
public:
    
    HealthPickup(float x, float y, float _health);
    
    ~HealthPickup();
    
    virtual void apply(Player *player);
    
    
    virtual void subclassDraw();
};

#endif /* HealthPickup_hpp */
