#ifndef Player_h
#define Player_h

#include "ofMain.h"
#include "GameObject.h"
class Game;

// TODO add speed settings
#define MAX_SPEED 100

class Player : public GameObject{
    
    ofLight faro;
    float speed;
    bool bLight;
    glm::vec3 prevPos;
    int coins;
    
public:
    
    Player(Game *game);
    ~Player();
    
    void init();
    void update() override;
    void draw() override;
    void drawDebug() override;
    void checkCollisions() override;
    float getSpeed();

	float timeSliding;
	float timeSlideSide;
    int slideDirection;
   

    void steerLeft();
    void steerRight();
    void accelerate();
    void toggleLight();
    void shoot();
    void brake();
    void stop();
    void addCoins(int n = 1);
    int getCoins();
    void removeAllCoins();

	void slow();
	void overOil();
	void teletransport();
    void turbo(float speed);
	
};

#endif 
