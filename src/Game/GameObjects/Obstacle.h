#pragma once
#include "GameObject.h"

class Obstacle : public GameObject {

public:
    Obstacle(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Obstacle();

    void draw() override;
    void receiveCarCollision(Player* car) override;
    void receiveBulletCollision(GameObject* bullet) override;
};
