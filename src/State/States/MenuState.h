#ifndef MenuState_h
#define MenuState_h

#include "State.h"
#include "Game.h"

class MenuState : public State {
    ofImage background;
    ofTrueTypeFont verdana;
    ofTrueTypeFont verdana2;

public:
    MenuState(Game* game) : State(game, "Menu State") {
        background.load("background.jpg");

        verdana.load("verdana.ttf", 100, true, true);
        verdana.setLineHeight(18.0f);
        verdana.setLetterSpacing(1.037);

        verdana2.load("verdana.ttf", 20, true, true);
        verdana2.setLineHeight(18.0f);
        verdana2.setLetterSpacing(1.037);
    };

    ~MenuState() {};



    void update();
    void draw();
    void next();
    void keyPressed(int key);

};
#endif 