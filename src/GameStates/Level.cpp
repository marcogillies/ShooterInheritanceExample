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


Level::Level (ofApp *_app)
:GameState(_app)
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
    clear();
    
    ofBackground(0, 0, 100);
    gameObjects.push_back(new Player(20, ofGetHeight()/2));
}

void Level::draw()
{
    for (GameObject *go : gameObjects){
        go->draw();
    }
}
void Level::keyPressed(int key)
{
    for (GameObject *go : gameObjects){
        go->keyPressed(key);
    }
}