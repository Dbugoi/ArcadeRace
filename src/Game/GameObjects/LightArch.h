#pragma once

#include "GameObject.h"
#include "Road.h"

class LightArch : public GameObject {

public:
    LightArch(Game* game, glm::vec3 pos, glm::vec3 dim, bool lights, Road *road_atr);
    ~LightArch();

    void update() override;
    void draw() override;
    void drawDebug() override;
    void receiveCarCollision(Player* car) override;

    bool isEnabled;
    ofPlanePrimitive plane;
    ofImage img;
    ofTexture texture;
    int archHeight;
    int timeDisabled;
    Road *road;
};
