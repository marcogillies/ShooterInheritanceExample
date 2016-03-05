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
    ofRectangle boundingBox;
    
    virtual void collisionResponse(GameObject *other);
    
public:
    // generic constructor that sets the position
    GameObject(float x, float y, float w, float h);
    
    virtual ~GameObject();
    
    
    // this is a generic draw method that
    // sets the position of the object and
    // then calls a method that does the
    // specific drawing code for the subclass
    void draw();
    
    // this needs to be overriden in the
    // subclass to provide specific drawing code
    virtual void subclassDraw()=0;
    
    virtual void keyPressed(int key);
    
    ofPoint getPosition(){
        return boundingBox.getCenter();
    }
    
    void move(float x, float y){
        boundingBox.setPosition(boundingBox.getX() + x, boundingBox.getY() + y);
    }
    
    float getHeight(){
        return boundingBox.getHeight();
    }
    
    float getWidth(){
        return boundingBox.getWidth();
    }
    
    void collide (GameObject *other);
    
    virtual void die();
    
    bool isAlive(){
        return !dead;
    }
};

#endif /* GameObject_hpp */
