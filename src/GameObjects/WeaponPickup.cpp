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

WeaponPickup::WeaponPickup(float x, float y, Weapon *_weapon)
:Pickup(x,y), weapon(_weapon)
{
    
}

WeaponPickup::~WeaponPickup()
{
    if(weapon) delete weapon;
}

void WeaponPickup::apply(Player *player)
{
    if(player){
        player->addWeapon(weapon);
        weapon = nullptr;
    }
}

void WeaponPickup::subclassDraw()
{
    ofSetColor(weapon->getColour());
    ofFill();
    ofDrawCircle(0, 0, getWidth());
}