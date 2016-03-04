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
protected:
    // this is the position of the object
    ofVec2f pos;
    // if this becomes true, the object should
    // be removed
    bool dead = false;
    
public:
    // generic constructor that sets the position
    GameObject(float x, float y);
    
    virtual ~GameObject();
    
    
    // this is a generic draw method that
    // sets the position of the object and
    // then calls a method that does the
    // specific drawing code for the subclass
    void draw();
    
    // this needs to be overriden in the
    // subclass to provide specific drawing code
    virtual void subclassDraw()=0;
    
    virtual void keyPressed(int key)=0;
};

#endif /* GameObject_hpp */
