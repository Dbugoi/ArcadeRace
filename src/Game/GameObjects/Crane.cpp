#include "Crane.h"
#include "Player.h"
#include "Game.h"


Crane::Crane(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	material.setEmissiveColor(ofColor::yellow);
	hasBeenPassed = false;
	craneHeight = dim.y;
	cranePosY = pos.y;
	W = game->ROAD_WIDTH;
	CONSTANT_SPEED = 3;
	verticalSpeed = -CONSTANT_SPEED;
	horizontalSpeed = 0.01;
	horizontalY = craneHeight / 2;
	radius = W / 2 ;
	angle = 0;
	//auto position = collider->getGlobalPosition();
	//position.x -= 250;
	//position.z -= 250;

	//collider->setGlobalPosition(position);

}
Crane::~Crane() {}

void Crane::update() {
	auto position = collider->getGlobalPosition();
	if (position.y > cranePosY) {
		verticalSpeed = -CONSTANT_SPEED;
	}
	else if (position.y < craneHeight / 2 - 50) {
		verticalSpeed = CONSTANT_SPEED;
	}
	position.y += verticalSpeed;
	horizontalY += verticalSpeed;

	position.x = radius * cos(angle) - radius;
	position.z = radius * sin(angle) + 250;

	//horizontalX = radius * cos(angle);
	//horizontalZ = radius * sin(angle);

	angle += horizontalSpeed;

	
	collider->setGlobalPosition(position);

	/*
	auto orientation = collider->getGlobalOrientation();
	orientation.y = angle;
	collider->setGlobalOrientation(orientation);
	*/


	
}

void Crane::draw() {
	//transform.rotateRad(-angle, 0, 1, 0);

	material.begin();
	{
		collider->draw();
		transform.transformGL();
		//ofTranslate(W / 2, 0, 0);
		//ofRotateDeg(90, 0, 1, 0);
		//transform.rotateDeg(2, 0, 1, 0);

		ofTranslate(-W / 2, 0, 0);
		//transform.rotateDeg(2, 0, 1, 0);
		ofRotateRad(-angle, 0, 1, 0);
		ofTranslate(W / 2, 0, 0);


		


		ofDrawBox(-W / 2, -(craneHeight / 2), 0, 50, craneHeight * 2 +50, 50);


		ofDrawBox(-W / 4, horizontalY, 0, radius+50, 50, 50);
		//ofTranslate(-W / 2, 0, 0);

		transform.restoreTransformGL();


	}
	material.end();

}

void Crane::drawDebug() {
	collider->drawDebug();
}

void  Crane::receiveCarCollision(Player* car) {
	car->removeAllCoins();
}

/*void Crane::moveXandYinCircle() {
		//float x = 0;
	//float y = 0;
	//float z = 0;
	//float radius = 100;
	//float angle = 0;
	//float speed = 0.1;
	//float x = radius * cos(angle);
	//float y = radius * sin(angle);
	//float z = 0;
	//angle += speed;
	//collider->setGlobalPosition(glm::vec3(x, y, z));
}
*/