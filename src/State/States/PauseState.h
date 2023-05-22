#pragma once

#include "State.h"
#include "Game.h"

class PauseState : public State {

    ofImage background;
    ofTrueTypeFont verdana;
    ofTrueTypeFont verdana2;

public:
    PauseState(Game* game) : State(game, "Pause State") {
        background.load("pausa.gif");

        verdana.load("verdana.ttf", 100, true, true);
        verdana.setLineHeight(18.0f);
        verdana.setLetterSpacing(1.037);

        verdana2.load("verdana.ttf", 20, true, true);
        verdana2.setLineHeight(18.0f);
        verdana2.setLetterSpacing(1.037);
    };

    ~PauseState() {};


    void update();
    void draw();
    void next();
    void keyPressed(int key);
};