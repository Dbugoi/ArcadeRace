#include "Barrier.h"
#include "Player.h"
#include "Game.h"


Barrier::Barrier(Game *game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::blueSteel);

	speed = CONSTANT_SPEED;
	timeToMove = 0;
	maxHeight = dim.y + 100;
	minHeight = dim.y / 2 - 50;

}
Barrier::~Barrier() {
}


void Barrier::update() {
	int posY = transform.getGlobalPosition().y;
	if (ofGetElapsedTimef() > timeToMove) {
		if (posY > maxHeight) {
			timeToMove = ofGetElapsedTimef() + 2;
			speed = -CONSTANT_SPEED;
		}
		else if (posY < minHeight) {
			timeToMove = ofGetElapsedTimef() + 2;
			speed = CONSTANT_SPEED;
		}
		transform.move(transform.getYAxis() * speed);
	}
	
	
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
