#pragma once
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Oil : public GameObject {

public:
	Oil(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Oil();

	void update() override;
	void draw() override;
	void receiveCarCollision(Player *car) override;

	ofxAssimpModelLoader model;

	ofImage img;
	ofTexture texture;
	ofPlanePrimitive plane;

};

