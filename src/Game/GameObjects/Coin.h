#ifndef Coin_h
#define Coin_h
#include "GameObject.h"

class Coin : public GameObject{
    
public:
    Coin(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Coin();
    
    void draw() override;
    void receiveCarCollision(Player *car) override;
    void receiveBulletCollision(GameObject *bullet) override;
};

#endif /* Coin_h */
