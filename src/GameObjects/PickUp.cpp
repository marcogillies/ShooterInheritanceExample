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
// constructor while the height and width are always
// set to a constant value of 10
Pickup::Pickup(float x, float y)
:GameObject(x,y, 10, 10)
{
}

Pickup::~Pickup()
{
    
}

// if the collision is with a player, then apply
// the pickup to the player
void Pickup::collisionResponse(GameObject *other)
{
    // attempt to cast the object to a player
    Player *player = dynamic_cast<Player *>(other);
    // if it is a player apply the pickup and then die
    if(player){
        apply(player);
        die();
    }
}
