//
//  GameStateException.hpp
//  ShooterInhertiance
//
//  Created by Marco Gillies on 15/03/2016.
//
//

#ifndef GameStateException_hpp
#define GameStateException_hpp

#include <stdio.h>
#include <string>

class GameStateException
{
    std::string message;
public:
    GameStateException(std::string m);
    
    std::string getMessage() const {
        return message;
    }
};

#endif /* GameStateException_hpp */
