#ifndef CrazyArch_h
#define CrazyArch_h
#include "GameObject.h"

class CrazyArch : public GameObject {

public:
    CrazyArch(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~CrazyArch();

    void update() override;
    void draw() override;
    void drawDebug() override;
    void receiveCarCollision(Player* car) override;

    bool hasBeenPassed;
    ofPlanePrimitive plane;
    ofFbo fbo;
    int archHeight;
    int timeChangeNum;
    int numCoins;
    ofTrueTypeFont verdana;
};

#endif

