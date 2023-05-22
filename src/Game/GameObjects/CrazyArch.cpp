#include "CrazyArch.h"
#include "Player.h"
#include "Game.h"
#include <string>

CrazyArch::CrazyArch(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    material.setDiffuseColor(ofColor::blue);
    hasBeenPassed = false;
    archHeight = 350;
    timeChangeNum = 0;
    numCoins = rand() % 100;
    plane.set(200, 200);
    plane.move(pos.x, archHeight - 50, pos.z - 29); 
    plane.rotateDeg(180, 0, 1, 0);

    ofEnableNormalizedTexCoords();
    ofDisableArbTex();

    fbo.allocate(200, 200);

    ofTrueTypeFont::setGlobalDpi(72);
    verdana.load("verdana.ttf", 100, true, true);
    verdana.setLineHeight(18.0f);
    verdana.setLetterSpacing(1.037);
}
CrazyArch::~CrazyArch() {}

void CrazyArch::update() {
    fbo.begin();
    {
        ofBackground(ofColor::papayaWhip);
        if (!hasBeenPassed && ofGetElapsedTimef() >= timeChangeNum) {
            numCoins = rand() % 100;
            timeChangeNum += 5;
        }
        
        ofSetColor(ofColor::grey);
        verdana.drawString(to_string(numCoins), plane.getWidth() / 2 - verdana.getStringBoundingBox(to_string(numCoins), 0, 0).getWidth() / 2, plane.getHeight() / 2 + verdana.getStringBoundingBox(to_string(numCoins), 0, 0).getHeight() / 2);
        //ofDrawBitmapString(numCoins, plane.getWidth()/2, plane.getHeight()/2);
        //verdana.drawString("HOLA", plane.getWidth() / 2, plane.getHeight() / 2);

    }
    fbo.end();
}

void CrazyArch::draw() {

    material.begin();
    {
        transform.transformGL();

        ofDrawBox(-collider->getWidth() / 2,
            archHeight/2, 0, 50, archHeight, 50);

        ofDrawBox(collider->getWidth() / 2,
            archHeight / 2, 0, 50, archHeight, 50);

        ofDrawBox(0,
            archHeight, 0, collider->getWidth(), 50, 50);

        transform.restoreTransformGL();

        
    }
    material.end();
    fbo.getTexture().bind();
    plane.draw();
    fbo.getTexture().unbind();
}

void CrazyArch::drawDebug() {
    collider->drawDebug();
}

void  CrazyArch::receiveCarCollision(Player* car) {
    if (!hasBeenPassed) {
        car->addCoins(numCoins);
        material.setEmissiveColor(ofColor::red);
        hasBeenPassed = true;
        numCoins = 0;
    }
}
