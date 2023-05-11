#ifndef MenuState_h
#define MenuState_h

#include "State.h"
#include "Game.h"

class MenuState: public State{
public:
    MenuState(Game *game): State(game, "Menu State"){
    };
    
    ~MenuState(){};
    
    void update();
    void draw();
    void next();
        
};
#endif 
