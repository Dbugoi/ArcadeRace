#ifndef Crane_h
#define Crane_h
#include "GameObject.h"

class Crane : public GameObject {

public:
	Crane(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Crane();

	void update() override;
	void draw() override;
	void drawDebug() override;
	void receiveCarCollision(Player* car) override;

	bool hasBeenPassed;
	int craneHeight;
	int W;
	int cranePosY;
	
};

#endif

