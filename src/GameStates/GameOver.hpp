//
//  GameOver.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 04/03/2016.
//
//

#ifndef GameOver_hpp
#define GameOver_hpp

#include <stdio.h>
#include "Menu.hpp"

/*
 *  Game Over Screen
 *  a standard menu that has no interaction 
 */
class GameOver: public Menu
{
public:
    // parameter: the font to use to draw
    GameOver(std::shared_ptr<ofTrueTypeFont>_font);
    virtual ~GameOver();
    
    // doesn't actually do anything
    virtual void keyPressed(int key);
};


#endif /* GameOver_hpp */
