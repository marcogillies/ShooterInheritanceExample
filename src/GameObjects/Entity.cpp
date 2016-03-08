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
Entity::Entity(float x, float y, float w, float h, float _health, float _speed)
:GameObject(x,y, w, h),health(_health), speed(_speed)
{
}

Entity::~Entity()
{
    
}


// draws a health bar for the entity
void Entity::subclassDraw()
{
    // health bar
    ofSetColor(0, 255, 0);
    ofFill();
    ofDrawRectangle(0, -12, health, 4);
}

// reduce health and die of health reaches 0
void Entity::takeDamage(float d)
{
    health -= d;
    if (health <= 0){
        die();
    }
}

// increase health
void Entity::addHealth(float h)
{
    health += h;
}