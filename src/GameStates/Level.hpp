//
//  Level.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef Level_hpp
#define Level_hpp

#include <stdio.h>
#include <vector>
#include "GameState.hpp"

class GameObject;

class Level : public GameState
{
    std::vector<GameObject *> gameObjects;
public:
    Level (ofApp *_app);
    ~Level();
    
    void clear();
    
    virtual void start();
    virtual void draw();
    virtual void keyPressed(int key);
};

#endif /* Level_hpp */
