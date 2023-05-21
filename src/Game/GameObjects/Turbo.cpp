#include "Turbo.h"
#include "Player.h"
#include "Game.h"


Turbo::Turbo(Game* game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::lightGreen);
}
Turbo::~Turbo() {
}

void Turbo::draw() {

	material.begin();
	{
		collider->draw();
	}
	material.end();
}

void Turbo::receiveCarCollision(Player* car) {
	float speed=car->getSpeed();
	car->turbo(speed);
}

