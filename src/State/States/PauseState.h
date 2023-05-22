#pragma once

#include "State.h"
#include "Game.h"

class PauseState : public State {
public:
    PauseState(Game* game) : State(game, "Pause State") {
    };

    ~PauseState() {};

    void update();
    void draw();
    void next();
    void keyPressed(int key);
}; 
