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

class StartMenu: public Menu
{
public:
    StartMenu(ofApp *_app, std::shared_ptr<ofTrueTypeFont>_font);
    virtual ~StartMenu();
    
    virtual void keyPressed(int key);
};

#endif /* StartMenu_hpp */
