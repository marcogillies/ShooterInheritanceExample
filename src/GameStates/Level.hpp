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
#include "GameState.hpp"

class Level : public GameState
{
    
public:
    Level (ofApp *_app);
    ~Level();
    
    virtual void start();
    virtual void draw();
    virtual void keyPressed(int key);
};

#endif /* Level_hpp */
