#ifndef ResultState_h
#define ResultState_h

#include "State.h"
class Game;

class ResultState : public State {
    ofImage background;
    ofTrueTypeFont verdana;
    ofTrueTypeFont verdana2;
    string time;
    string coins;

public:
    ResultState(Game* game);

    ~ResultState();


    void update();
    void draw();
    void next();
    void keyPressed(int key);
};

#endif /* ResultState_h */