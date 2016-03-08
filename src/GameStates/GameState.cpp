//
//  GameState.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "GameState.hpp"


/*
 *  define the static variables
 */
std::vector<std::unique_ptr<GameState> > GameState::gameStates;

int GameState::currentGameState = -1;

/*
 * base class constructor and destructor do nothing as the
 * base class contains no data
 */

GameState::GameState()
{
    
}

GameState::~GameState()
{
    
}