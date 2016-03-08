//
//  StartMenu.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef StartMenu_hpp
#define StartMenu_hpp

#include <stdio.h>
#include "Menu.hpp"

/*
 *  The start menu
 *  just a standard menu that goes to level 1 when you press the space bar
 */
class StartMenu: public Menu
{
public:
    // parameter: the font to use to draw
    StartMenu(std::shared_ptr<ofTrueTypeFont>_font);
    virtual ~StartMenu();
    
    // implemented from the base class
    // goes to level 1 when you press space
    virtual void keyPressed(int key);
};

#endif /* StartMenu_hpp */
