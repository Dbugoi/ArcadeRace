#pragma once
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Dirt : public GameObject {

public:
	Dirt(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Dirt();

	void update() override;
	void draw() override;
	void receiveCarCollision(Player *car) override;

	ofxAssimpModelLoader model;
	
	ofImage img;
	ofTexture texture;
	ofPlanePrimitive plane;

};

