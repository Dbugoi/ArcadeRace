#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"

 
ResultState::ResultState(Game *game): State(game, "Result State"){
};

ResultState::~ResultState(){};

void ResultState::update(){
};

void ResultState::draw(){
    ofBackground(127);
    ofDrawBitmapString(name, 10, 20);
};

void ResultState::next(){
    game->setState(new MenuState(game));
};
