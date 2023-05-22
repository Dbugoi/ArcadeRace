#include "LightArch.h"
#include "Player.h"
#include "Game.h"
#include <string>

LightArch::LightArch(Game* game, glm::vec3 pos, glm::vec3 dim, bool lights, Road *road_atr) : GameObject(game, pos, dim) {
    material.setDiffuseColor(ofColor::purple);

    isEnabled = true;
    archHeight = 350;
    plane.set(200, 200);
    plane.move(pos.x, archHeight - 50, pos.z - 29);
    plane.rotateDeg(180, 0, 1, 0);

    ofEnableNormalizedTexCoords();
    ofDisableArbTex();
    road = road_atr;
    if(lights)
        img.load("LightsOn.png");
    else
        img.load("LightsOff.jpg");
    texture = img.getTexture();
    texture.setTextureWrap(GL_REPEAT, GL_REPEAT);

}
LightArch::~LightArch() {}

void LightArch::update() {
    
    //ofBackground(ofColor::papayaWhip);
    
    if (!isEnabled && ofGetElapsedTimef() > timeDisabled)
		isEnabled = true;
    

}

void LightArch::draw() {

    material.begin();
    {
        transform.transformGL();

        ofDrawBox(-collider->getWidth() / 2,
            archHeight / 2, 0, 50, archHeight, 50);

        ofDrawBox(collider->getWidth() / 2,
            archHeight / 2, 0, 50, archHeight, 50);

        ofDrawBox(0,
            archHeight, 0, collider->getWidth(), 50, 50);

        transform.restoreTransformGL();

    }
    material.end();

    texture.bind();
    plane.draw();
    texture.unbind();
}
    

void LightArch::drawDebug() {
    collider->drawDebug();
}

void  LightArch::receiveCarCollision(Player* car) {
    if (isEnabled) {
        road->swapLights();
        isEnabled = false;
        timeDisabled = ofGetElapsedTimef() + 3;
    }
}
