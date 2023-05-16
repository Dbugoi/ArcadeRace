#pragma once
#include "GameObject.h"

class Dirt : public GameObject {

public:
	Dirt(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Dirt();

	void draw() override;
	void receiveCarCollision(Player *car) override;
	
	ofImage img;
	ofTexture texture;
	ofPlanePrimitive plane;

};

