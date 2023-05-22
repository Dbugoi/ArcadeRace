
#include "Plane.h"
#include "Bomb.h"
#include "Game.h"

Plane::Plane(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    model.loadModel("3ds file.3DS");
    
    collider->move(0, dim.y / 2 - 25, 0);
    
    
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -25, 0);
    //model.setScale(0.25, 0.25, 0.25);

    transform.rotateDeg(-90, 0, 1, 0);

    
    speed = 30;
    bTurned = false;
}
Plane::~Plane() {

}

void Plane::update() {
    model.update();
    auto pos = collider->getGlobalPosition();
    if (pos.x >= 6000 || pos.x <= -6000)
        turn();
    transform.move(transform.getZAxis() * -speed);
    bTurned = false;

};
void Plane::draw() {
    transform.transformGL();

    model.drawFaces();

    transform.restoreTransformGL();

    //collider->drawWireframe();

};

void Plane::turn() {
    if (!bTurned) {
        transform.rotateDeg(180, 0, 1, 0);
        transform.move(transform.getZAxis() * -speed);
        bTurned = true;
    }
}


void Plane::receiveBombCollision(Bomb* bomb) {
    bomb->throwBomb();
}
