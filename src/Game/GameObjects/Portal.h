#pragma once
#include "GameObject.h"

class Portal : public GameObject {

public:
	Portal(Game* game, glm::vec3 pos1, glm::vec3 pos2, glm::vec3 dim);
	~Portal();

	void draw() override;
	void receiveCarCollision(Player* car) override;

	glm::vec3 teleportPos;

	ofImage img;
	ofTexture texture;
	ofPlanePrimitive plane;

};