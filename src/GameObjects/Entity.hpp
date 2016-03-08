//
//  Entity.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "GameObject.hpp"


// A class representing an entity with health and movement
// It is a subclass of GameObject because it has a position
class Entity : public  GameObject
{
protected:
    // a health value
    float health;
    // how fast it can move up or down
    float speed;
    
public:
    // The constructor takes the position of the entity and
    // passes is to the super class (GameObject) constructor
    // Also sets up health and speed
    Entity(float x, float y, float w, float h, float _health, float _speed);
    
    ~Entity();
    
    // draw the player
    // move the player constantly forward then
    // draw a square for the player and a
    // health bar
    virtual void subclassDraw();
    
    
    // take damage from another game object
    void takeDamage(float d);
    
    // increase health
    void addHealth(float h);
};

#endif /* Entity_hpp */