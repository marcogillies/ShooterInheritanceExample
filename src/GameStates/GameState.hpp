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

/*
 * This is the superclass of all game states including
 * menus and levels.
 */
class GameState
{
private:
    // do not copy
    GameState(const GameState &gs){
        // do not copy;
    }
    // do not copy
    GameState &operator=(const GameState &gs){
        return *this;
    }
    
protected:
    // a singleton list of game states
    // this is the definitive store of game states
    static std::vector<std::unique_ptr<GameState> > gameStates;
    // the current game state
    static int currentGameState;
public:
    
    /*
     *  These are static functions that act on the singleton
     *  list of game states.
     */
    
    // add a new game state
    static void addGameState(GameState *gs)
    {
        gameStates.push_back(std::unique_ptr<GameState> (gs));
    }
    
    // get the current game state
    // NB the caller does not own the returned pointer
    // and should not keep a reference to the pointer
    static GameState *getCurrentGameState()
    {
        return gameStates[currentGameState].get();
    }
    
    // sets the current game state
    // calls end on the previous game state
    // and start on the new one
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
    
    // move to the next game state
    static void nextGameState()
    {
        if(currentGameState < getNumGameStates()-1){
            setGameState(currentGameState+1);
        }
    }
    
    // return the number of game states
    static int getNumGameStates(){
        return gameStates.size();
    }
    
    // constructor is default (the base class has no data).
    GameState();
    
    // destructor is virtual because this is a base class
    virtual ~GameState();
    
    /*
     *  Member functions to be implemented by sub classes
     */
    
    // anything that needs to be done when a state starts
    virtual void start()=0;
    // any clean up at the end
    virtual void end()=0;
    
    // draw the game
    virtual void draw()=0;
    // respond to key presses
    virtual void keyPressed(int key)=0;
};

#endif /* GameState_hpp */
