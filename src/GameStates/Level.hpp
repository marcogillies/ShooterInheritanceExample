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
    int numEnemies;
    int numPickups;
    //static Level * currentLevel;
    std::vector<GameObject *> gameObjects;
public:
    //static void setCurrentLevel(Level *l);
    static Level *getCurrentLevel();
    
    Level (ofApp *_app, int enemies, int pickups);
    ~Level();
    
    void clear();
    
    virtual void start();
    virtual void draw();
    virtual void keyPressed(int key);
    
    void addGameObject(GameObject *go){
        gameObjects.push_back(go);
    }
    
    void gameOver();
    void win();
};

#endif /* Level_hpp */
