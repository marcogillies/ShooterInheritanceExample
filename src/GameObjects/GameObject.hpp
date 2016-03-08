//
//  GameObject.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "ofMain.h"

/*
 *  Super class of all objects in the game
 */
class GameObject
{
private:
    // do not copy
    GameObject(const GameObject &gs){
        // do not copy;
    }
    // do not copy
    GameObject &operator=(const GameObject &gs){
        return *this;
    }
    
protected:
    // if this becomes true, the object should
    // be removed
    bool dead = false;
    
    //ofVec2f pos;
    
    // the bounding box of the object
    // used for finding the position
    // and for collision
    ofRectangle boundingBox;
    
    // do sub-class specific responses to collision
    virtual void collisionResponse(GameObject *other);
    
    // this needs to be overriden in the
    // subclass to provide specific drawing code
    virtual void subclassDraw()=0;
    
public:
    // generic constructor that sets the position
    // width, and height
    GameObject(float x, float y, float w, float h);
    
    virtual ~GameObject();
    
    
    // this is a generic draw method that
    // sets the position of the object and
    // then calls a method that does the
    // specific drawing code for the subclass
    void draw();
    
    
    
    // should be overridden in all sub classes
    // that need to respond to key pressed
    virtual void keyPressed(int key);
    
    // get the position (from the bouding box)
    ofPoint getPosition(){
        return boundingBox.getCenter();
    }
    
    
    float getHeight(){
        return boundingBox.getHeight();
    }
    
    float getWidth(){
        return boundingBox.getWidth();
    }

    // move the object right by x and up by y
    void move(float x, float y){
        boundingBox.setPosition(boundingBox.getX() + x, boundingBox.getY() + y);
    }
    
    // check for and respond to a collision with another object
    void collide (GameObject *other);
    
    // set the object to dead
    virtual void die();
    
    // checks if the object is alive
    bool isAlive(){
        return !dead;
    }
};

#endif /* GameObject_hpp */
