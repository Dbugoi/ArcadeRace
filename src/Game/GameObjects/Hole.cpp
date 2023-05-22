#include "Hole.h"
#include "Player.h"
#include "Game.h"


Hole::Hole(Game *game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::black);
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
}

