//
//  GameObject.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "GameObject.hpp"

// generic constructor that sets the position, width and height
GameObject::GameObject(float x, float y, float w, float h)
: boundingBox(x,y,w,h)
{
}

GameObject::~GameObject()
{
    
}

// this is a generic draw method that
// sets the position of the object and
// then calls a method that does the
// specific drawing code for the subclass
void GameObject::draw()
{
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(boundingBox.getLeft(), boundingBox.getTop());
    subclassDraw();
    ofPopMatrix();
    ofPopStyle();
};


// by default it does not respond to keypresses
void GameObject::keyPressed(int key)
{
    
}


// first check if there is a collision and if so
// respond to it
void GameObject::collide (GameObject *other)
{
    // check for collision by seeing if the bouding
    // boxes intersect
    if(this->boundingBox.intersects(other->boundingBox)){
        // do the response both ways to ensure that
        // we do any relevant response action
        this->collisionResponse(other);
        other->collisionResponse(this);
    }
}

// by default do nothing on collision
void GameObject::collisionResponse(GameObject *other)
{
    
}

// by default just set dead to true
void GameObject::die(){
    dead = true;
}

