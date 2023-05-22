#include "PauseState.h"
#include "PlayState.h"



void PauseState::update() {
};

void PauseState::draw() {
    ofBackground(0);
    ofDrawBitmapString(name, 10, 20);
};

void PauseState::next() {
    game->setState(new PlayState(game, 1));
};

void PauseState::keyPressed(int key) {
    if (key == 'p' || key == 'P')
        next();
}
