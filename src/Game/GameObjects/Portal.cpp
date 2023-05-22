#include "Portal.h"
#include "Player.h"
#include "Game.h"


Portal::Portal(Game* game, glm::vec3 pos1, glm::vec3 pos2, glm::vec3 dim) :
	GameObject(game, pos1, dim) {
	
	teleportPos = pos2;

	plane.set(dim.x, dim.z);
	plane.rotateDeg(180, 0, 1, 0);
	plane.move(pos1.x, pos1.y, pos1.z + 1);

	transform.rotateDeg(-90, 1, 0, 0);

	img.load("portal.png");

	texture = img.getTexture();
	texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
}
Portal::~Portal() {
}

void Portal::draw() {

	material.begin();
	{
		texture.bind();
		plane.draw();
		texture.unbind();
		//collider->draw();
	}
	material.end();
}

void Portal::receiveCarCollision(Player* car) {
	car->teleport(teleportPos);
}

