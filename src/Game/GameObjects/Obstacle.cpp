#include "Obstacle.h"
#include "Player.h"
#include "Game.h"


Obstacle::Obstacle(Game* game, glm::vec3 pos, glm::vec3 dim) :
    GameObject(game, pos, dim) {
    material.setDiffuseColor(ofColor::deepPink);



}
Obstacle::~Obstacle() {

}


void Obstacle::draw() {


    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Obstacle::receiveCarCollision(Player* car) {
    car->stop();
}

void Obstacle::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
    kill();
}
