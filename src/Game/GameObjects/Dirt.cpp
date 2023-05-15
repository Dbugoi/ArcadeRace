#include "Dirt.h"
#include "Player.h"
#include "Game.h"


Dirt::Dirt(Game *game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	//material.setDiffuseColor(ofColor::pink);
	plane.set(200, 200);
	plane.rotateDeg(-90, 1, 0, 0);
	plane.move(0, -50.1, 0);

	

	ofEnableNormalizedTexCoords();
	ofDisableArbTex();
	img.load("cat.png");

	texture = img.getTexture();
	texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
	texture.generateMipmap();
	texture.setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_NEAREST);
	
	

}
Dirt::~Dirt() {
}


void Dirt::update() {
	model.update();
}

void Dirt::draw() {
	
	material.begin();
	{
		texture.bind();
			plane.mapTexCoords(0, 0, 1, 1);
			plane.draw();
		texture.unbind();
		collider->draw();
	}
	material.end();
	
	
}

void Dirt::receiveCarCollision(Player *car) {
	car->slow();
}

