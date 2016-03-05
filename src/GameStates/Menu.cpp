//
//  Menu.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "Menu.hpp"
#include "Level.hpp"


Menu::Menu(ofApp *_app, std::shared_ptr<ofTrueTypeFont>_font, std::string _text)
: GameState(_app), font(_font), text(_text)
{

}

Menu::~Menu()
{
    
}

void Menu::start()
{
    ofBackground(100, 0, 0);
}


void Menu::end()
{
    
}

void Menu::draw()
{
    font->drawString(text, 200, ofGetHeight()/2);
}