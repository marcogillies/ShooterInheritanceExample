//
//  Entity.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "Entity.hpp"

// The constructor takes the position of the player and
// passes is to the super class (GameObject) constructor
// It also creates an inventory and adds a weapon to it
Entity::Entity(float x, float y, float w, float h, float _health, float _speed)
:GameObject(x,y, w, h),health(_health), speed(_speed)
{
    //inventory = new ArrayList <Weapon>();
    //addWeapon(new Weapon(1, 2, 0.1));
}

Entity::~Entity()
{
    
}


// draw the player
// move the player constantly forward then
// draw a square for the player and a
// health bar
void Entity::subclassDraw()
{
    // health bar
    ofSetColor(0, 255, 0);
    ofFill();
    ofDrawRectangle(0, -12, health, 4);
    // player
}


void Entity::takeDamage(float d)
{
    health -= d;
    if (health <= 0){
        die();
    }
}


void Entity::addHealth(float h)
{
    health += h;
}