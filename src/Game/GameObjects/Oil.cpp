#include "Oil.h"
#include "Player.h"
#include "Game.h"


Oil::Oil(Game *game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	//material.setDiffuseColor(ofColor::pink);
	plane.set(dim.x, dim.z);
	plane.rotateDeg(-90, 1, 0, 0);
	plane.rotateDeg(180, 0, 1, 0);
	plane.move(pos.x, pos.y + 0.1, pos.z);



	ofEnableNormalizedTexCoords();
	ofDisableArbTex();
	img.load("oil.jpg");

	texture = img.getTexture();
	texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
	//texture.generateMipmap();
	//texture.setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_NEAREST);



	}
Oil::~Oil() {
}


void Oil::draw() {

	material.begin();
	{
		texture.bind();
		//plane.mapTexCoords(0, 0, 1, 1);
		plane.draw();
		texture.unbind();
		collider->draw();
	}
	material.end();


}

void Oil::receiveCarCollision(Player *car) {
	car->overOil();
}

