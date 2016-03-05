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

class Menu: public GameState
{
    std::shared_ptr<ofTrueTypeFont> font;
    std::string text;
public:
    Menu(ofApp *_app, std::shared_ptr<ofTrueTypeFont>_font, std::string _text);
    virtual ~Menu();
    
    virtual void start();
    virtual void end();
    virtual void draw();
};

#endif /* Menu_hpp */
