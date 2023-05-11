#include "PlayState.h"
#include "MenuState.h"

void MenuState::update(){
};
    
void MenuState::draw(){
    ofBackground(0);
    ofDrawBitmapString(name, 10, 20);
};

void MenuState::next(){
    game->setState(new PlayState(game));
};
