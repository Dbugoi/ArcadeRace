#pragma once
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Hole : public GameObject {

public:
	Hole(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Hole();

	void update() override;
	void draw() override;
	void receiveCarCollision(Player *car) override;

	ofxAssimpModelLoader model;


};

