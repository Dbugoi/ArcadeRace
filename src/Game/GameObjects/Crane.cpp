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
	verticalSpeed = -CONSTANT_SPEED;
	horizontalSpeed = 0.01;
	horizontalY = craneHeight / 2;
	radius = W / 2 + 50;
	angle = 0;

	/*auto globPos = transform.getGlobalPosition();

	globPos.x -= W/2;

	transform.setGlobalPosition(globPos);
	*/
}
Crane::~Crane() {}

void Crane::update() {
	auto position=collider->getGlobalPosition();
	if (position.y > cranePosY) {
		verticalSpeed = -CONSTANT_SPEED;
	}
	else if (position.y < craneHeight/2 -50 ) {
		verticalSpeed = CONSTANT_SPEED;
	}
	position.y += verticalSpeed;
	horizontalY += verticalSpeed;

	position.x = radius * cos(angle) - radius;
	position.z = radius * sin(angle);

	//horizontalX = radius * cos(angle);
	//horizontalZ = radius * sin(angle);
	
	angle += horizontalSpeed;

	collider->setGlobalPosition(position);
}

void Crane::draw() {

	material.begin();
	{
		collider->draw();
		transform.transformGL();

		//vertical
		//ofDrawBox(-W/2, -100, 0, 50, craneHeight*2, 50);

		

		ofTranslate(-W / 2, 0, 0);

		ofRotateDeg(-angle, 0, 1, 0);

		ofTranslate(W / 2, 0, 0);

		ofDrawBox(-W/2,  -(craneHeight / 2), 0, 50, craneHeight*2, 50);


		//horizontal
		ofDrawBox(-W / 4, horizontalY, 0, radius, 50, 50);

	
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

