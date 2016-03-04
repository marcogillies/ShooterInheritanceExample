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


Level * Level::currentLevel = nullptr;

void Level::setCurrentLevel(Level *l)
{
    currentLevel = l;
}
Level *Level::getCurrentLevel()
{
    return currentLevel;
}

Level::Level (ofApp *_app, int enemies, int pickups)
:GameState(_app), numEnemies(enemies), numPickups(pickups)
{
    
}
Level::~Level()
{
    clear();
}

void Level::clear(){
    for(GameObject *go : gameObjects){
        delete go;
    }
    gameObjects.clear();
}

void Level::start()
{
    setCurrentLevel(this);
    
    clear();
    
    ofBackground(0, 0, 100);
    Player *player = new Player(20, ofGetHeight()/2);
    player->addWeapon(new Weapon(1, 2, 0.1));
    gameObjects.push_back(player);
    
    for (int i = 0; i < numEnemies; i++){
        Enemy *enemy = new Enemy(ofRandom(50, ofGetWidth()), // x
                                 ofRandom(0, ofGetHeight()), //y
                                 ofRandom(5, 20), //health
                                 ofRandom(0, 1.0), //speed
                                 ofRandom(1,5));//damage
        gameObjects.push_back(enemy);
    }
}

void Level::draw()
{
    for (GameObject *go : gameObjects){
        go->draw();
    }
}

void Level::keyPressed(int key)
{
    for (int i = 0; i < gameObjects.size(); i++){
        gameObjects[i]->keyPressed(key);
    }
}