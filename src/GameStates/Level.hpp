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

// pre-declare GameObject
class GameObject;

/*
 * A class for game levels
 * Levels are defined by the game objects they contain
 */
class Level : public GameState
{
    // the state of the level
    // used for transitioning between levels
    enum State {
        not_started,
        playing,
        complete,
        failed
    };
    State state;
    
    int numEnemies; // number of enemies in the level
    int numPickups; // number of pickups in the level
    
    // stores all of the game objects in the level
    // this is the definitive store
    // gameobejcts are not stored separately by type
    std::vector<GameObject *> gameObjects;
public:
    // a singleton like function for getting the
    // current level
    // (returns null if the current game state is not a level
    static Level *getCurrentLevel();
    
    /*
     *  Parameters
     *  enemies: number of enemies in the level
     *  pickups: number of pickups in the level
     */
    Level (int enemies, int pickups);
    ~Level();
    
    
    /*
    * implemented from the base class
    */
    
    // anything that needs to be done when a state starts
    virtual void start();
    // any clean up at the end
    virtual void end();
    
    // draw the game
    virtual void draw();
    // respond to key presses
    virtual void keyPressed(int key);
    
    // add a new game object to the level
    void addGameObject(GameObject *go){
        gameObjects.push_back(go);
    }
    
    // enter the game over state
    // this does not do anything immediately to
    // stop things crashing if this is called in the middle
    // of the draw loop
    void gameOver(){
        state = failed;
    };
    // enter the win state
    // this does not do anything immediately to
    // stop things crashing if this is called in the middle
    // of the draw loop
    void win(){
        state = complete;
    }
};

#endif /* Level_hpp */
