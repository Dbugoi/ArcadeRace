#pragma once
#include "GameObject.h"

class Turbo : public GameObject {

public:
	Turbo(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Turbo();

	void draw() override;
	void receiveCarCollision(Player* car) override;

};

