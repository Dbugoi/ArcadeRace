#include "Barrier.h"
#include "Player.h"
#include "Game.h"


Barrier::Barrier(Game *game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::blueSteel);

	speed = CONSTANT_SPEED;

}
Barrier::~Barrier() {
}


void Barrier::update() {
	model.update();
	int posY = transform.getGlobalPosition().y;
	if ( posY > 1000) {
		speed = -CONSTANT_SPEED;
	}
	else if (posY <= 0) {
		speed = CONSTANT_SPEED;
	}
	transform.move(transform.getYAxis() * speed);
}

void Barrier::draw() {
	material.begin();
	{
		collider->draw();
	}
	material.end();
}

void Barrier::receiveCarCollision(Player *car) {
	car->stop();
}

void Barrier::receiveBulletCollision(GameObject *bullet) {
	bullet->kill();
	kill();
}
