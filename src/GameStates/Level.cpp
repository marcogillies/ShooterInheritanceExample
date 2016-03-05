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


//Level * Level::currentLevel = nullptr;

//void Level::setCurrentLevel(Level *l)
//{
//    currentLevel = l;
//}
Level *Level::getCurrentLevel()
{
    Level * currentLevel = dynamic_cast<Level *>(GameState::getCurrentGameState());
    return currentLevel;
}

Level::Level (ofApp *_app, int enemies, int pickups)
:GameState(_app), numEnemies(enemies), numPickups(pickups), state(not_started)
{
    
}
Level::~Level()
{
    end();
}

void Level::end(){
    for(GameObject *go : gameObjects){
        delete go;
    }
    gameObjects.clear();
}

void Level::start()
{
    //setCurrentLevel(this);
    
    state = playing;
    
    ofBackground(0, 0, 100);
    Player *player = new Player(20, ofGetHeight()/2);
    player->addWeapon(new Weapon(1, 2, 0.1));
    gameObjects.push_back(player);
    
    for (int i = 0; i < numEnemies; i++){
        Enemy *enemy = new Enemy(ofRandom(50, 2*ofGetWidth()), // x
                                 ofRandom(0, ofGetHeight()), //y
                                 ofRandom(5, 20), //health
                                 ofRandom(0, 1.0), //speed
                                 ofRandom(1,20));//damage
        gameObjects.push_back(enemy);
    }
    
    for (int i = 0; i < numPickups; i++){
        if(ofRandom(1.0) > 0.5f){
            HealthPickup *pickup= new HealthPickup(ofRandom(50, ofGetWidth()), // x
                                            ofRandom(0, ofGetHeight()), //y
                                            ofRandom(5, 20)); //health
            gameObjects.push_back(pickup);
        } else {
            Weapon * weapon = new Weapon (ofRandom(1, 10), // damage
                                          ofRandom(0, 3.0f), //speed
                                          ofRandom(0.0f, 1.0f)); // reload time
            WeaponPickup *pickup= new WeaponPickup(ofRandom(50, ofGetWidth()), // x
                                                   ofRandom(0, ofGetHeight()), //y
                                                   weapon);
            gameObjects.push_back(pickup);

        }
    }
}

void Level::draw()
{
    for (GameObject *go : gameObjects){
        go->draw();
    }
    for(int i = 0; i < gameObjects.size()-1; i++){
        for (int j = i+1; j < gameObjects.size(); j++){
            gameObjects[i]->collide((gameObjects[j]));
        }
    }
    auto it = std::remove_if(gameObjects.begin(), gameObjects.end(),
                             [](GameObject *go){
                                 return !go->isAlive();
                             });
    gameObjects.erase(it, gameObjects.end());
    
    if(state == failed){
        GameState::setGameState(GameState::getNumGameStates()-1);
        state = not_started;
    }
    if(state == complete){
        GameState::nextGameState();
        if(getCurrentLevel() == nullptr){
            GameState::setGameState(0);
        }
        state = not_started;
    }

}

void Level::keyPressed(int key)
{
    for (int i = 0; i < gameObjects.size(); i++){
        gameObjects[i]->keyPressed(key);
    }
}

//void Level::gameOver()
//{
//    nextGameState = GameState::getNumGameStates()-1;
//}
//
//void Level::win()
//{
//    nextGameState = GameState::getCurrentGameState();
//    if(getCurrentLevel() == nullptr){
//        GameState::setGameState(0);
//    }
//}

