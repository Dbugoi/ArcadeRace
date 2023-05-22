#include "PlayState.h"
#include "MenuState.h"


void MenuState::update() {

};

void MenuState::draw() {
    background.draw(0, -100, ofGetWidth(), ofGetHeight() + 100);
    //ofBackground(0);
    //ofDrawBitmapString(name, 10, 20);
    //ofSetColor(ofColor::grey);
    verdana.drawString("ARCADE RACE", ofGetWidth() / 2 - verdana.getStringBoundingBox("ARCADE RACE", 0, 0).getWidth() / 2, ofGetHeight() / 2 + verdana.getStringBoundingBox("ARCADE RACE", 0, 0).getHeight() / 2);
    verdana2.drawString("Pulse la tecla Espacio para comenzar", ofGetWidth() / 2 - verdana2.getStringBoundingBox("Pulse la tecla Espacio para comenzar", 0, 0).getWidth() / 2, ofGetHeight() / 2 + 200 + verdana2.getStringBoundingBox("Pulse la tecla Espacio para comenzar", 0, 0).getHeight() / 2);


};

void MenuState::next() {
    game->setState(new PlayState(game));
};

void MenuState::keyPressed(int key) {
    if (key == ' ')
        next();
}
