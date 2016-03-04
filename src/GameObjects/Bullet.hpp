//
//  Bullet.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "GameObject.hpp"


// This class represents bullets fired by the player
// it is a GameObject and in addition has a level of
// damage and speed of movement
class Bullet : public GameObject
{
    float damage;
    float speed;
    
    
public:
    // The constructor takes the x and y position as
    // well as values for the speed and damage
    // The position is passed to the superclass (GameObject)
    // constructor while d and s are used to set the damage
    // and speed variables
    Bullet(float x, float y, float d, float s);
    // This is the function that draws the bullet
    // it moves the bullet based on speed and
    // then draws a circles whose size depends on
    // the damage
    void subclassDraw();
};

#endif /* Bullet_hpp */
