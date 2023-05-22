#pragma once

#include "GameObject.h"

#include "ofxAssimpModelLoader.h"

class Bomb : public GameObject {
    float speed = -5;
    bool isDrawn;
public:
    Bomb(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Bomb();

    void initPosition();
    void update() override;
    void draw() override;

    void checkCollisions() override;
    void receiveCarCollision(Player *car) override;

    void throwBomb();

    int initialY;
    ofxAssimpModelLoader model;
};