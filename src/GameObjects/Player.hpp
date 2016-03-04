//
//  Player.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <vector>
#include "GameObject.hpp"

// A class representing a player
// It is a subclass of GameObject because it has a position
class Player : public  GameObject
{
protected:
    // a health value
    float health = 40;
    // how fast it can move up or down
    float speed = 5;
    // the inventory of weapons the player can use
    //std::vector <Weapon> inventory;
    // the current weapon the player is using
    //Weapon currentWeapon;
public:
    // The constructor takes the position of the player and
    // passes is to the super class (GameObject) constructor
    // It also creates an inventory and adds a weapon to it
    Player(float x, float y);
    
    ~Player();
    
    // add a new weapon to the inventory
    // and set it as the current weapon
    //void addWeapon(Weapon w);
    // Select a new weapon from the inventory.
    // A weapon is selected by a number which is
    // it's index into the inventory
    //void chooseWeapon(int i);
    
    // fire the weapon
    void fire();
    
    // draw the player
    // move the player constantly forward then
    // draw a square for the player and a
    // health bar
    virtual void subclassDraw();
    
    virtual void keyPressed(int key);
    
    // move the player up or down
    // (called from keyPressed)
    void up();
    void down();
    
};

#endif /* Player_hpp */