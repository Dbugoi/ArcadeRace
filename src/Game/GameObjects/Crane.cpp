#include "Crane.h"
#include "Player.h"
#include "Game.h"


Crane::Crane(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	material.setEmissiveColor(ofColor::blue);
	hasBeenPassed = false;
	craneHeight = dim.y;
	cranePosY = pos.y;
	W = game->ROAD_WIDTH;
	CONSTANT_SPEED = 3;
	speed = -CONSTANT_SPEED;
}
Crane::~Crane() {}

void Crane::update() {
	auto py=collider->getGlobalPosition();
	if (py.y > cranePosY) {
		speed = -CONSTANT_SPEED; 
	}
	else if (py.y < craneHeight/2 -50 ) {
		speed = CONSTANT_SPEED;
	}
	py.y += speed;
	collider->setGlobalPosition(py) ;
}

void Crane::draw() {

	material.begin();
	{
		collider->draw();
		transform.transformGL();

		//vertical
		//ofDrawBox(-W/2, -100, 0, 50, craneHeight*2, 50);
		ofDrawBox(-W/2,  -(craneHeight / 2), 0, 50, craneHeight*2, 50);

		//horizontal
		ofDrawBox(-W / 4, craneHeight/2, 0, W/2+50, 50, 50);
	
		transform.restoreTransformGL();


	}
	material.end();
	
}

void Crane::drawDebug() {
	collider->drawDebug();
}

void  Crane::receiveCarCollision(Player* car) {

}

