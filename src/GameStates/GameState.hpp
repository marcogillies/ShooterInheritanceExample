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
#include <vector>
#include <memory>

class ofApp;

class GameState
{
protected:
    static std::vector<std::unique_ptr<GameState> > gameStates;
    static int currentGameState;
    
    ofApp *app;
public:
    static void addGameState(GameState *gs)
    {
        gameStates.push_back(std::unique_ptr<GameState> (gs));
    }
    static GameState *getCurrentGameState()
    {
        return gameStates[currentGameState].get();
    }
    static void setGameState(int i)
    {
        if(i >= 0 && i < gameStates.size()){
            
            if(currentGameState > 0 || currentGameState < gameStates.size()){
                gameStates[currentGameState]->end();
            }
            
            currentGameState = i;
            gameStates[currentGameState]->start();
        }
    }
    static void nextGameState()
    {
        if(currentGameState < getNumGameStates()-1){
            setGameState(currentGameState+1);
        }
    }
    static int getNumGameStates(){
        return gameStates.size();
    }
    
    GameState(ofApp *_app);
    virtual ~GameState();
    
    virtual void start()=0;
    virtual void end()=0;
    
    virtual void draw()=0;
    virtual void keyPressed(int key)=0;
};

#endif /* GameState_hpp */
