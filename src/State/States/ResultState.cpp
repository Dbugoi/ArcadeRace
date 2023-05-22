#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"
#include "Player.h"


ResultState::ResultState(Game* game) : State(game, "Result State") {
    background.load("final.webp");

    verdana.load("verdana.ttf", 100, true, true);
    verdana.setLineHeight(18.0f);
    verdana.setLetterSpacing(1.037);

    verdana2.load("verdana.ttf", 20, true, true);
    verdana2.setLineHeight(18.0f);
    verdana2.setLetterSpacing(1.037);

    time = "Tiempo: " + ofToString(game->getEllapsedTime());
    coins = "Monedas: " + ofToString(game->getPlayer()->getCoins());
};

ResultState::~ResultState() {};

void ResultState::update() {
};

void ResultState::draw() {
    //ofBackground(127);
    //ofDrawBitmapString(name, 10, 20);

    background.draw(0, 0, ofGetWidth(), ofGetHeight());

    //string recordTime = game->getRecordTime();
    //string recordCoins = game->getRecordCoins();
    //ofSetColor(ofColor::grey);
    verdana.drawString(time, ofGetWidth() / 2 - verdana.getStringBoundingBox(time, 0, 0).getWidth() / 2, ofGetHeight() / 2 - 150 + verdana.getStringBoundingBox(time, 0, 0).getHeight() / 2);
    //verdana2.drawString("Record Tiempo", ofGetWidth() / 2 - verdana2.getStringBoundingBox("Pulse la tecla Espacio para volver", 0, 0).getWidth() / 2, ofGetHeight() / 2 + 200 + verdana2.getStringBoundingBox("Pulse la tecla Espacio para volver", 0, 0).getHeight() / 2);
    verdana.drawString(coins, ofGetWidth() / 2 - verdana.getStringBoundingBox(coins, 0, 0).getWidth() / 2, ofGetHeight() / 2 + 50 + verdana.getStringBoundingBox(coins, 0, 0).getHeight() / 2);
    // verdana2.drawString("Record Monedas", ofGetWidth() / 2 - verdana2.getStringBoundingBox("Pulse la tecla Espacio para volver", 0, 0).getWidth() / 2, ofGetHeight() / 2 + 200 + verdana2.getStringBoundingBox("Pulse la tecla Espacio para volver", 0, 0).getHeight() / 2);
    verdana2.drawString("Pulse la tecla Espacio para volver al menu", ofGetWidth() / 2 - verdana2.getStringBoundingBox("Pulse la tecla Espacio para volver al menu", 0, 0).getWidth() / 2, ofGetHeight() / 2 + 200 + verdana2.getStringBoundingBox("Pulse la tecla Espacio para volver al menu", 0, 0).getHeight() / 2);

};

void ResultState::next() {
    game->setState(new MenuState(game));
};
void ResultState::keyPressed(int key) {
    if (key == ' ')
        next();
}