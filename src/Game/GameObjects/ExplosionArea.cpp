#include "ExplosionArea.h"
#include "Player.h"
#include "Bomb.h"
#include "Game.h"


ExplosionArea::ExplosionArea(Game* game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::darkGrey);
	isExploding = false;
	explosionTime = 0;
}
ExplosionArea::~ExplosionArea() {
}

void ExplosionArea::update() {
	if(ofGetElapsedTimef() > explosionTime)
		isExploding = false;
}

void ExplosionArea::draw() {

	material.begin();
	{
		collider->draw();
	}
	material.end();
}

void ExplosionArea::receiveBombCollision(Bomb* bomb) {
	bomb->initPosition();
	isExploding = true;
	explosionTime = ofGetElapsedTimef() + 0.1;
}

void ExplosionArea::receiveCarCollision(Player* car) {
	if(isExploding)
		car->explosionNear();
	isExploding = false;
}

