//
//  WeaponPickup.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 05/03/2016.
//
//

#ifndef WeaponPickup_hpp
#define WeaponPickup_hpp

#include <stdio.h>
#include "Pickup.hpp"
#include "Weapon.hpp"

/*
 *  A pickup that gives a new weapon to the player
 */
class WeaponPickup : public Pickup
{
    Weapon weapon; // the weapon to add
    
public:
    // parameters:
    // x,y: position
    // weapon: the weapon to add
    WeaponPickup(float x, float y, const Weapon &weapon);
    
    ~WeaponPickup();
    
    // apply the pickup to the player
    virtual void apply(Player *player);
    
    // draw the pickup
    virtual void subclassDraw();
};


#endif /* WeaponPickup_hpp */
