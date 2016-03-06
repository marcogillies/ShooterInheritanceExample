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

class WeaponPickup : public Pickup
{
    Weapon weapon;
    
public:
    
    WeaponPickup(float x, float y, const Weapon &weapon);
    
    ~WeaponPickup();
    
    virtual void apply(Player *player);
    
    
    virtual void subclassDraw();
};


#endif /* WeaponPickup_hpp */
