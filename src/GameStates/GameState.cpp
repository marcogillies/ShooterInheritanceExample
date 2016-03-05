//
//  GameState.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "GameState.hpp"



std::vector<std::unique_ptr<GameState> > GameState::gameStates;

int GameState::currentGameState = -1;

GameState::GameState(ofApp *_app) : app(_app)
{
    
}

GameState::~GameState()
{
    
}