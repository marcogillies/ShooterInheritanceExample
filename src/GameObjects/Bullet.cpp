//
//  Bullet.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "Bullet.hpp"

// The constructor takes the x and y position as
// well as values for the speed and damage
// The position is passed to the superclass (GameObject)
// constructor while d and s are used to set the damage
// and speed variables
Bullet::Bullet(float x, float y, float d, float s)
:GameObject(x,y), damage(d), speed(s)
{
    
}

// This is the function that draws the bullet
// it moves the bullet based on speed and
// then draws a circles whose size depends on
// the damage
void Bullet::subclassDraw()
{
    pos.x += speed;
    ofSetColor(255);
    ofFill();
    ofDrawCircle(0, 0, 2*damage);
}
