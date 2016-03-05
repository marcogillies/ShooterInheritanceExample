//
//  GameObject.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "GameObject.hpp"

// generic constructor that sets the position
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
    ofPushMatrix();
    ofTranslate(boundingBox.getLeft(), boundingBox.getTop());
    subclassDraw();
    ofPopMatrix();
};


void GameObject::keyPressed(int key)
{
    
}


void GameObject::collide (GameObject *other)
{
    if(this->boundingBox.intersects(other->boundingBox)){
        this->collisionResponse(other);
        other->collisionResponse(this);
    }
}

 void GameObject::collisionResponse(GameObject *other)
{
    
}

