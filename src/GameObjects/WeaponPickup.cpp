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

// adds the weapon to the player
void WeaponPickup::apply(Player *player)
{
    if(player){
        player->addWeapon(weapon);
    }
}

// draws the pickup in the colour of the weapon
void WeaponPickup::subclassDraw()
{
    ofSetColor(weapon.getColour());
    ofFill();
    ofDrawCircle(0, 0, getWidth());
}