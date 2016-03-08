//
//  Menu.cpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#include "Menu.hpp"
#include "Level.hpp"


Menu::Menu(std::shared_ptr<ofTrueTypeFont>_font, std::string _text)
: GameState(), font(_font), text(_text)
{

}

Menu::~Menu()
{
    
}

// just sets the background colour
void Menu::start()
{
    ofBackground(100, 0, 0);
}

// don't need any clean up code
void Menu::end()
{
    
}

// draws the text to screen
void Menu::draw()
{
    font->drawString(text, 200, ofGetHeight()/2);
}