//
//  Level.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "Level.hpp"
#include "ofMain.h"
#include "Player.hpp"
#include "Enemy.hpp"
#include "HealthPickup.hpp"
#include "WeaponPickup.hpp"
#include "Weapon.hpp"
#include "GameOver.hpp"



// just calls get Current game state and casts the result to a level
// (returns null if the current game state is not a level
Level *Level::getCurrentLevel()
{
    Level * currentLevel = dynamic_cast<Level *>(GameState::getCurrentGameState());
    return currentLevel;
}

Level::Level (int enemies, int pickups)
:GameState(), numEnemies(enemies), numPickups(pickups), state(not_started)
{
    
}
Level::~Level()
{
    end();
}

// delete all game object at the end of the level
void Level::end(){
    for(GameObject *go : gameObjects){
        delete go;
    }
    // removes all contents of the vector
    // NB does not delete content
    gameObjects.clear();
}

// randomly create game objects at when the level start
void Level::start()
{
    state = playing;
    
    ofBackground(0, 0, 100);
    
    // create a player
    Player *player = new Player(20, ofGetHeight()/2);
    player->addWeapon(Weapon(1, 2, 0.1));
    gameObjects.push_back(player);
    
    
    // create enemies
    for (int i = 0; i < numEnemies; i++){
        Enemy *enemy = new Enemy(ofRandom(50, 2*ofGetWidth()), // x
                                 ofRandom(0, ofGetHeight()), //y
                                 ofRandom(5, 20), //health
                                 ofRandom(0, 1.0), //speed
                                 ofRandom(1,20));//damage
        gameObjects.push_back(enemy);
    }
    
    // create pickups, randomly choosing between weapon and health pickups
    for (int i = 0; i < numPickups; i++){
        if(ofRandom(1.0) > 0.5f){
            HealthPickup *pickup= new HealthPickup(ofRandom(50, ofGetWidth()), // x
                                            ofRandom(0, ofGetHeight()), //y
                                            ofRandom(5, 20)); //health
            gameObjects.push_back(pickup);
        } else {
            Weapon weapon (ofRandom(1, 10), // damage
                                          ofRandom(0, 3.0f), //speed
                                          ofRandom(0.0f, 1.0f)); // reload time
            WeaponPickup *pickup= new WeaponPickup(ofRandom(50, ofGetWidth()), // x
                                                   ofRandom(0, ofGetHeight()), //y
                                                   weapon);
            gameObjects.push_back(pickup);

        }
    }
}


// this draws all of the game objects
void Level::draw()
{
    // draw all game objects
    for (GameObject *go : gameObjects){
        go->draw();
    }
    
    // perform collision between all game objects
    for(int i = 0; i < gameObjects.size()-1; i++){
        // only do game objects after 1 in the inner
        // loop so you don't collide 2 objects twice
        for (int j = i+1; j < gameObjects.size(); j++){
            gameObjects[i]->collide((gameObjects[j]));
        }
    }
    
    // remove all dead objects
    // only do this after the two loops to avoid
    // invalidated iterators
    auto toremove = std::remove_if(gameObjects.begin(), gameObjects.end(),
                             [](GameObject *go){
                                 bool dead = !go->isAlive();
                                 // delete any dead game objects
                                 if(dead){
                                     delete go;
                                 }
                                 return dead;
                             });
    gameObjects.erase(toremove, gameObjects.end());
    
    // if we are in the faild state go to gamover
    // only do this after the main loops to avoid
    // acting on deleted objects
    if(state == failed){
        //GameState::setGameState(GameState::getNumGameStates());

        //GameState::setGameState(GameState::getNumGameStates()-1);

        GameOver::goToGameOver();
        state = not_started;
    }
    // if we have completed the level go to the
    // next on, or back to the start
    // screen if we have completed all levels
    if(state == complete){
        GameState::nextGameState();
        if(getCurrentLevel() == nullptr){
            GameState::setGameState(0);
        }
        state = not_started;
    }

}

// pass on the keypress to all of the game objects
void Level::keyPressed(int key)
{
    for (int i = 0; i < gameObjects.size(); i++){
        gameObjects[i]->keyPressed(key);
    }
}


