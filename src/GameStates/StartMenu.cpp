//
//  StartMenu.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "StartMenu.hpp"

StartMenu::StartMenu(std::shared_ptr<ofTrueTypeFont>_font)
: Menu(_font, "Press Space to Start")
{
}

StartMenu::~StartMenu()
{
    
}

// go to level 1 when you press space
void StartMenu::keyPressed(int key)
{
    if(key == ' '){
        GameState::setGameState(1);
    }
}