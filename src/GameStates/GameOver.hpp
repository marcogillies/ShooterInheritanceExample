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

class GameOver: public Menu
{
public:
    GameOver(ofApp *_app, std::shared_ptr<ofTrueTypeFont>_font);
    virtual ~GameOver();
    
    virtual void keyPressed(int key);
};


#endif /* GameOver_hpp */
