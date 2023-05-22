#include "PauseState.h"
#include "PlayState.h"



void PauseState::update() {
};

void PauseState::draw() {
    //ofBackground(0);
    //ofDrawBitmapString(name, 10, 20);
    background.draw(0, 0, ofGetWidth(), ofGetHeight());
    //ofSetColor(ofColor::grey);
    verdana.drawString("Pausa", ofGetWidth() / 2 - verdana.getStringBoundingBox("Pausa", 0, 0).getWidth() / 2, ofGetHeight() / 2 + verdana.getStringBoundingBox("Pausa", 0, 0).getHeight() / 2);
    verdana2.drawString("Pulse la tecla Espacio para volver", ofGetWidth() / 2 - verdana2.getStringBoundingBox("Pulse la tecla Espacio para volver", 0, 0).getWidth() / 2, ofGetHeight() / 2 + 200 + verdana2.getStringBoundingBox("Pulse la tecla Espacio para volver", 0, 0).getHeight() / 2);


};

void PauseState::next() {
    game->setState(new PlayState(game, 1));
};

void PauseState::keyPressed(int key) {
    if (key == ' ')
        next();
}