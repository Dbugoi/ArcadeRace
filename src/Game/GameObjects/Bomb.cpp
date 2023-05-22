
#include "Bomb.h"
#include "Game.h"
#include "Player.h"

Bomb::Bomb(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    model.loadModel("littleboybomb.obj");

    initialY = pos.y;

    //collider->move(0, dim.y / 2 - 25, 0);
    collider->move(0, -20, 0);


    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -25, 0);
    model.setScale(0.2, 0.2, 0.2);

    transform.rotateDeg(-90, 0, 0, 1);


    speed = 8;
    isDrawn = false;
}
Bomb::~Bomb() {

}

void Bomb::initPosition() {
   
    auto pos = transform.getPosition();
    pos.y = initialY;
    transform.setPosition(pos);
    
    //transform.setPosition(0, initialY, 0);
    isDrawn = false;
    game->doExplotion();
}

void Bomb::update() {
    model.update();
    /*auto pos = collider->getGlobalPosition();
    if (pos.x >= 6000 || pos.x <= -6000)
        turn();
    transform.move(transform.getZAxis() * -speed);
    bTurned = false;
    */
    if (isDrawn)
        transform.move(transform.getXAxis() * speed);

};
void Bomb::draw() {
    transform.transformGL();
    
    if(isDrawn)
        model.drawFaces();

    transform.restoreTransformGL();
};

void Bomb::checkCollisions() {
    vector<GameObject*> collisions = game->getCollisions(this);
    for (auto c : collisions) {
        c->receiveBombCollision(this);
    }
}

void Bomb::receiveCarCollision(Player* car) {
	car->initPosition();
    initPosition();
}

void Bomb::throwBomb() {
    isDrawn = true;
}
