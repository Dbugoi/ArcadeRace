#include "ofApp.h"
#include "MenuState.h"
#include "PlayState.h"
#include "Player.h"

//--------------------------------------------------------------
void ofApp::setup(){
    game = new Game();
    //game->setState(new PlayState(game));
    game->setState(new MenuState(game));
    ofSetFrameRate(60);

    music.load("neon.mp3");
    music.setVolume(0.1);
    music.setLoop(true);
    music.play();
}

ofApp::~ofApp(){
    delete game;
}

//--------------------------------------------------------------
void ofApp::update(){
    game->currentState()->update();
    
    if(game->isFinished()){
        game->currentState()->next();
        game->setFinished(false);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    game->currentState()->draw();
}


void ofApp::keyPressed(int key){
    if(key == ']')
        game->currentState()->next();
    
    game->currentState()->keyPressed(key);
}


void ofApp::keyReleased(int key){
    game->currentState()->keyReleased(key);
}
