//
//  Weapon.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "Weapon.hpp"
#include "Level.hpp"
#include "GameObject.hpp"
#include "Bullet.hpp"

// the constructor take the damage, speed and reload time
Weapon::Weapon(float d, float s, float t)
:damage(d), speed(s), reloadTime(t), lastFireTime(0.0f), owner(nullptr)
{
    
    // give it a random colour
    colour = ofColor (ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

// when copying, the last fire time is not copied because
// it is transient data
Weapon::Weapon (const Weapon &other)
: damage(other.damage),
    speed(other.speed),
    reloadTime(other.reloadTime),
    colour(other.colour),
    lastFireTime(0.0f),
    owner(nullptr)
{
    
}

// when copying, the last fire time is not copied because
// it is transient data
Weapon &Weapon::operator = (const Weapon &other)
{
    damage = other.damage;
    speed = other.speed;
    reloadTime = other.reloadTime;
    colour = other.colour;
    lastFireTime = 0.0f;
    owner = nullptr;
    
    return *this;
}

// shoot a bullet
void Weapon::fire()
{
    // check whether enough time has passed
    if(ofGetElapsedTimeMillis()/1000.0 - lastFireTime > reloadTime)
    {
        lastFireTime = ofGetElapsedTimeMillis()/1000.0;
        // create a new bullet at the intial position of the owner
        // and damage and speed based on the weapon parameters
        Level * level = Level::getCurrentLevel();
        if(level){
            ofVec2f pos = owner->getPosition();
            level->addGameObject(new Bullet(pos.x, pos.y, damage, speed));
        }
    }
}