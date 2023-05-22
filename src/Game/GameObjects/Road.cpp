

#include "Road.h"
#include "Bomb.h"
#include "Game.h"

Road::Road(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos){
    material.setDiffuseColor(ofColor::darkGrey);
    
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
    
    light.setPosition(-500, 1000, -1000);
    light.setDiffuseColor(ofColor::white);

    lightsOn = true;
}
Road::~Road(){}

void Road::draw(){
    
    if (lightsOn)
        light.enable();
    else
        light.disable();
    material.begin();
    {
        plane.draw();
    }
    material.end();
}


void Road::drawDebug(){
    plane.drawWireframe();
}

void Road::receiveBombCollision(Bomb* bomb){
    bomb->kill();
}

void Road::swapLights() {
	lightsOn = !lightsOn;
}

void Road::setLights(bool value) {
    lightsOn = value;
}
