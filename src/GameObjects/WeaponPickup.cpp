//
//  WeaponPickup.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 05/03/2016.
//
//

#include "WeaponPickup.hpp"
#include "Weapon.hpp"
#include "Player.hpp"

WeaponPickup::WeaponPickup(float x, float y, const Weapon &_weapon)
:Pickup(x,y), weapon(_weapon)
{
    
}

WeaponPickup::~WeaponPickup()
{
}

void WeaponPickup::apply(Player *player)
{
    if(player){
        player->addWeapon(weapon);
    }
}

void WeaponPickup::subclassDraw()
{
    ofSetColor(weapon.getColour());
    ofFill();
    ofDrawCircle(0, 0, getWidth());
}