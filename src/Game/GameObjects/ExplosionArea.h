#pragma once
#include "GameObject.h"

class ExplosionArea : public GameObject {

public:
	ExplosionArea(Game* game, glm::vec3 pos, glm::vec3 dim);
	~ExplosionArea();

	void update() override;
	void draw() override;
	void receiveBombCollision(Bomb* bomb) override;
	void receiveCarCollision(Player* car) override;

	bool isExploding;
	float explosionTime;
};

