//
//  Weapon.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include <stdio.h>
#include "ofMain.h"

class GameObject;

// This class represents a player weapon
// It determines the damage and speed of the
// bullets fired
class Weapon
{
    // how much damage bullets cause
    float damage;
    // how fast bullets move
    float speed;
    // how much time you have to wait before shooting again
    float reloadTime;
    
    // this is a variable for storing the
    // last time the weapon fired, used for implementing a delay
    float lastFireTime;
    // the colour of the weapon
    ofColor colour;
    
    // the player that owns the weapon
    GameObject *owner;
    
    
public:
    // the constructor take the damage, speed and reload time
    Weapon(float d, float s, float t);
    
    // copy constructor
    Weapon (const Weapon &other);
    //assignment operator
    Weapon &operator = (const Weapon &other);
    
    // shoot a bullet
    void fire();
    
    // the colour determines the colour of the player
    ofColor getColour(){
        return colour;
    }
    
    // the game object using this weapon
    void setOwner(GameObject *go){
        owner = go;
    }
};


#endif /* Weapon_hpp */
