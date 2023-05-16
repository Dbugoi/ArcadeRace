#pragma once
#include "GameObject.h"

class Oil : public GameObject {

public:
	Oil(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Oil();

	void draw() override;
	void receiveCarCollision(Player *car) override;

	ofImage img;
	ofTexture texture;
	ofPlanePrimitive plane;

};

