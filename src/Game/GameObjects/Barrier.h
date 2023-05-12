#pragma once
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Barrier : public GameObject {

public:
	Barrier(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Barrier();

	void update() override;
	void draw() override;
	void receiveCarCollision(Player *car) override;
	void receiveBulletCollision(GameObject *bullet) override;

	ofxAssimpModelLoader model;
	int speed;

};

