//
//  PickUp.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 05/03/2016.
//
//

#include "PickUp.hpp"
#include "Player.hpp"

// The constructor takes the x and y position as
// well as values for the speed and damage
// The position is passed to the superclass (GameObject)
// constructor while d and s are used to set the damage
// and speed variables
Pickup::Pickup(float x, float y)
:GameObject(x,y, 20, 20)
{
}

Pickup::~Pickup()
{
    
}

void Pickup::collisionResponse(GameObject *other)
{
    Player *player = dynamic_cast<Player *>(other);
    if(player){
        apply(player);
        die();
    }
}
