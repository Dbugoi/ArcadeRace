#include "Player.h"
#include "Game.h"
#include "Bullet.h"

Player::Player(Game *game):GameObject(game, glm::vec3(100)){
    
    material.setDiffuseColor(ofColor::blue);
    
    faro.setParent(transform);
    faro.setDiffuseColor(ofColor::yellow);
    faro.setSpotlight();
    faro.move(0, 0, 50);
    faro.rotateDeg(-200, 1, 0, 0);
    timeSliding = 0;
}

Player::~Player(){}

void Player::init(){
    transform.setPosition(0, 0, 0);
    speed = 0;
    bLight = false;
    
    coins = 0;
}

void Player::update(){
    prevPos = transform.getPosition();
    transform.move(transform.getZAxis() * speed);

	auto currentTime = ofGetElapsedTimef();
	if (currentTime < timeSliding) {
        if(currentTime >= timeSlideSide){
		    if ((rand() % 100) < 50) {
                slideDirection = 1;
			    transform.rotateDeg(slideDirection, 0, 2, 0);
		    }
		    else {
                slideDirection = -1;
			    transform.rotateDeg(slideDirection, 0, 2, 0);
		    }
		    timeSlideSide += 0.25;
        }
        else
            transform.rotateDeg(slideDirection, 0, 2, 0);
	}
    
    if(speed > MAX_SPEED) speed = MAX_SPEED;
    if(speed < 0) speed = 0;
}

void Player::draw(){
    
    faro.draw();
    if(bLight)
        faro.enable();
    else
        faro.disable();
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Player::drawDebug(){
    collider->drawDebug();
    
    transform.transformGL();
    ofDrawAxis(100);
    transform.restoreTransformGL();
}

void Player::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveCarCollision(this);
    }
}

void Player::steerLeft(){
    transform.rotateDeg(1, 0, 2, 0);
}
void Player::steerRight(){
    transform.rotateDeg(-1, 0, 2, 0);
}
void Player::accelerate(){
    speed += 0.1;
}
void Player::brake(){
    speed -= 0.1;
}

void Player::stop(){
    speed = 0;
    transform.setPosition(prevPos);
}

void Player::toggleLight(){
    bLight = !bLight;
}

float Player::getSpeed(){
    return speed;
}

void Player::addCoins(int n){
    coins += n;
}

int Player::getCoins(){
    return coins;
}
void Player::shoot(){
    if (coins > 0) {
        game->addGameObject(new Bullet(game, transform));
        coins--;
    }
    
}

void Player::slow() {
	if (speed > 3) {
		speed *= 0.9;
	}
	
}

void Player::overOil() {
    float currentTimef = ofGetElapsedTimef();
    if (timeSliding < currentTimef) {
        timeSliding = currentTimef + 3;
        timeSlideSide = currentTimef;
    }
}

void Player::removeAllCoins() {
	coins = 0;
}

void Player::turbo(float s) {
    speed *= 1.1;
      
}

void Player::teletransport() {
    transform.setPosition(0, 0, 0);
}

void Player::initPosition() {
    transform.setPosition(0, 0, 0);
    speed = 0;
}

void Player::explosionNear() {
    transform.rotateDeg(180, 0, 1, 0);
}

