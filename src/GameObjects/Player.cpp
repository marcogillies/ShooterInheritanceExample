//
//  Player.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "Player.hpp"
#include "Level.hpp"

// The constructor takes the position of the player and
// passes is to the super class (GameObject) constructor
// It also creates an inventory and adds a weapon to it
Player::Player(float x, float y)
:Entity(x,y, 20, 20, 40, 5), currentWeapon(-1)
{
    //inventory = new ArrayList <Weapon>();
    //addWeapon(new Weapon(1, 2, 0.1));
}

Player::~Player()
{
    inventory.clear();
}

// add a new weapon to the inventory
// and set it as the current weapon
void Player::addWeapon(const Weapon &w)
{
    inventory.push_back(w);
    currentWeapon = inventory.size()-1;
    inventory[currentWeapon].setOwner(this);
}

// Select a new weapon from the inventory.
// A weapon is selected by a number which is
// it's index into the inventory
void Player::chooseWeapon(int i)
{
    // we need to check that i is actually
    // in the inventory
    if(i >= 0 && i < inventory.size())
    {
        // get weapon i and set it as the current weapon
        currentWeapon = i;
    }
}

// fire the weapon
void Player::fire()
{
    if(currentWeapon >= 0 && currentWeapon < inventory.size())
    {
        inventory[currentWeapon].fire();
    }
}

// draw the player
// move the player constantly forward then
// draw a square for the player and a
// health bar
void Player::subclassDraw()
{
    // move fowrad
    move(1, 0);;
   
    // draw the health bar from the entity class
    Entity::subclassDraw();
    
    
    // draw the player as a square with the
    // same colour as the current weapon
    ofColor col (255, 0, 0);
    if(currentWeapon){
        col =inventory[currentWeapon].getColour();
    }
    ofSetColor(col);
    ofFill();
    ofDrawRectangle(0, 0, getHeight(), getWidth());
    
    // if we reach the end of the screen, go to the
    // win state
    if(getPosition().x > ofGetWidth()){
        Level::getCurrentLevel()->win();
    }
}

// respond to keys
void Player::keyPressed(int key)
{
    // space for fire
    if(key == ' '){
        fire();
    }
    
    // arrow keys to move
    if(key == OF_KEY_UP){
        up();
    }
    if(key == OF_KEY_DOWN){
        down();
    }
    
    // number keys to change weapon
    if (key >= '0' && key <= '9') {
        chooseWeapon(key - '0');
    }
}

// move the player up or down
// (called from keyPressed)
void Player::up()
{
    move(0, -speed);
}
void Player::down()
{
    move(0, speed);
}

// if hte player dies, go to the gameover state
void Player::die(){
    Level * level = Level::getCurrentLevel();
    if(level){
        level->gameOver();
    }
}


    

