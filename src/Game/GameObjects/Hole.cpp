#include "Hole.h"
#include "Player.h"
#include "Game.h"


Hole::Hole(Game *game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::green);
}
Hole::~Hole() {
}


void Hole::update() {
	model.update();
}

void Hole::draw() {

	material.begin();
	{
		collider->draw();
	}
	material.end();
}

void Hole::receiveCarCollision(Player *car) {
	car->init();
}

