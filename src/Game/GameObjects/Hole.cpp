#include "Hole.h"
#include "Player.h"
#include "Game.h"


Hole::Hole(Game *game, glm::vec3 pos, glm::vec3 dim, Road* road_atr) :
	GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::black);
	road = road_atr;
}
Hole::~Hole() {
}

void Hole::draw() {

	material.begin();
	{
		collider->draw();
	}
	material.end();
}

void Hole::receiveCarCollision(Player *car) {
	car->initPosition();
	road->setLights(true);
}

