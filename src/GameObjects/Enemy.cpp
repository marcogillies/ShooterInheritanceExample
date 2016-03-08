//
//  Enemy.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "Enemy.hpp"
#include "Player.hpp"

// The constructor takes the position of the enemy and
// passes is to the super class (Entity) constructor
Enemy::Enemy(float x, float y, float h, float s, float d)
:Entity(x,y, 20, 20, h,s), damage(d)
{
    
}

Enemy::~Enemy()
{

}

// draw the enemy
// move the enemy constantly forward then
// draw a square for the enemy and a
// health bar
void Enemy::subclassDraw()
{
    // move forward
    move(-speed, 0);
    
    // draw the health bar from the
    // Entity class
    Entity::subclassDraw();
    
    // draw the enemy as a red square
    ofSetColor(255, 0, 0);
    ofFill();
    ofDrawRectangle(0, 0, 20, 20);
    
}


// respond to a collision with another object
// if the other object is a player it will do
// damage to it
void Enemy::collisionResponse(GameObject *other)
{
    // attempt to cast the object to a player
    Player *player = dynamic_cast<Player *>(other);
    // if it is a player do damage and then die
    if(player){
        player->takeDamage(damage);
        die();
    }
    
}
