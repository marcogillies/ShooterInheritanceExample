//
//  GameState.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef GameState_hpp
#define GameState_hpp

#include <stdio.h>

class ofApp;

class GameState
{
protected:
    ofApp *app;
public:
    GameState(ofApp *_app);
    virtual ~GameState();
    
    virtual void start()=0;
    virtual void draw()=0;
    virtual void keyPressed(int key)=0;
};

#endif /* GameState_hpp */
