#include "Wall.h"
#include "Player.h"
#include "Pedestrian.h"

Wall::Wall(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
    material.setEmissiveColor(ofColor::darkorange);
}
Wall::~Wall(){}

void Wall::draw(){
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}



void  Wall::receiveCarCollision(Player *car){
    car->stop();
}

void  Wall::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
};

void Wall::receivePedestrianCollision(Pedestrian *pedestrian){
   pedestrian->turn();
}
