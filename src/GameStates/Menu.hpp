//
//  Menu.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "ofMain.h"
#include "GameState.hpp"

/*
 *  A base class for game menus
 *  each of which will have a font and some text
 *
 *  This class is still abstract because it does not 
 *  implement keyPressed
 */
class Menu: public GameState
{
    // the font is stored as a shared pointer to a single program level font
    std::shared_ptr<ofTrueTypeFont> font;
    
    // the text to display
    std::string text;
public:
    
    /*
     * parameters : the font to use for text and the text to display
     */
    Menu(std::shared_ptr<ofTrueTypeFont>_font, std::string _text);
    virtual ~Menu();
    
    /*
     * implemented from the base class
     */
    
    // anything that needs to be done when a state starts
    virtual void start();
    // any clean up at the end
    virtual void end();
    
    // draw the game
    virtual void draw();
};

#endif /* Menu_hpp */
