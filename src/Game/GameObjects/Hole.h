#pragma once
#include "GameObject.h"
#include "Road.h"

class Hole : public GameObject {

public:
	Hole(Game *game, glm::vec3 pos, glm::vec3 dim, Road* road_atr);
	~Hole();

	void draw() override;
	void receiveCarCollision(Player *car) override;

	Road *road;

};

