#pragma once

#include "GameObject.h"

#include "ofxAssimpModelLoader.h"

class Plane : public GameObject {
    float speed = -5;
    bool bTurned;
public:
    Plane(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Plane();

    void update() override;
    void draw() override;

    void receiveBombCollision(Bomb *bomb) override;
    void turn();
    ofxAssimpModelLoader model;
};