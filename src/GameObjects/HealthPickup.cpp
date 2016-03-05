//
//  HealthPickup.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 05/03/2016.
//
//

#include "HealthPickup.hpp"
#include "Player.hpp"

HealthPickup::HealthPickup(float x, float y, float _health)
:Pickup(x,y), health(_health)
{
    
}
    
HealthPickup::~HealthPickup()
{
    
}
    
void HealthPickup::apply(Player *player)
{
    if(player)
        player->addHealth(health);
}