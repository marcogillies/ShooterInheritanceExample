//
//  Player.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "Player.hpp"

// The constructor takes the position of the player and
// passes is to the super class (GameObject) constructor
// It also creates an inventory and adds a weapon to it
Player::Player(float x, float y)
:GameObject(x,y)
{
    //inventory = new ArrayList <Weapon>();
    //addWeapon(new Weapon(1, 2, 0.1));
}

Player::~Player()
{
    
}

// add a new weapon to the inventory
// and set it as the current weapon
//void Player::addWeapon(Weapon w)
//{
//    inventory.add(w);
//    currentWeapon = w;
//    currentWeapon.owner = this;
//}

// Select a new weapon from the inventory.
// A weapon is selected by a number which is
// it's index into the inventory
//void Player::chooseWeapon(int i)
//{
//    // we need to check that i is actually
//    // in the inventory
//    if(i >= 0 && i < inventory.size())
//    {
//        // get weapon i and set it as the current weapon
//        currentWeapon = inventory.get(i);
//    }
//}

// fire the weapon
void Player::fire()
{
    std::cout << "bang\n";
    //if(currentWeapon!= null)
    //{
    //    currentWeapon.fire();
    //}
}

// draw the player
// move the player constantly forward then
// draw a square for the player and a
// health bar
void Player::subclassDraw()
{
    // move fowrad
    pos.x += 1;
    // health bar
    ofSetColor(0, 255, 0);
    ofFill();
    ofDrawRectangle(0, -12, health, 4);
    // player
    //ofSetColor(currentWeapon.colour);
    ofSetColor(255, 0, 0);
    ofFill();
    ofDrawRectangle(0, 0, 20, 20);
}

void Player::keyPressed(int key)
{
    if(key == ' '){
        fire();
    }
    if(key == OF_KEY_UP){
        up();
    }
    if(key == OF_KEY_DOWN){
        down();
    }
}

// move the player up or down
// (called from keyPressed)
void Player::up()
{
    pos.y -= speed;
}
void Player::down()
{
    pos.y += speed;
}
