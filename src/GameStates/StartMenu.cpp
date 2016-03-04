//
//  StartMenu.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "StartMenu.hpp"
#include "ofApp.h"

StartMenu::StartMenu(ofApp *_app, std::shared_ptr<ofTrueTypeFont>_font)
: Menu(_app, _font, "Press Space to Start")
{
}

StartMenu::~StartMenu()
{
    
}

void StartMenu::keyPressed(int key)
{
    if(key == ' '){
        app->setGameState(1);
    }
}