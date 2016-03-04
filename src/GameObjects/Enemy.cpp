//
//  Enemy.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "Enemy.hpp"

// The constructor takes the position of the player and
// passes is to the super class (GameObject) constructor
// It also creates an inventory and adds a weapon to it
Enemy::Enemy(float x, float y, float h, float s, float d)
:Entity(x,y, h,s), damage(d)
{
    
}

Enemy::~Enemy()
{

}

// draw the player
// move the player constantly forward then
// draw a square for the player and a
// health bar
void Enemy::subclassDraw()
{
    Entity::subclassDraw();
    
    ofSetColor(255, 0, 0);
    ofFill();
    ofDrawRectangle(0, 0, 20, 20);
    
    pos.x -= speed;
}