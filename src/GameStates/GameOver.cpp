//
//  GameOver.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "GameOver.hpp"

GameOver::GameOver(std::shared_ptr<ofTrueTypeFont>_font)
: Menu(_font, "Game Over")
{
}

GameOver::~GameOver()
{
    
}

// doesn't actually do anything
void GameOver::keyPressed(int key)
{

}