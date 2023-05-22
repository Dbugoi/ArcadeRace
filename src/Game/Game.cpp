#include "Game.h"
#include "Player.h"

Game::Game(){
    // TODO create settings
    ROAD_WIDTH = 2000;
    ROAD_LENGTH = 40000;

    generator = new GameObjectGenerator(this);
    bDebug = false;
    scream.load("aaa.wav");
    explotion.load("explotion.wav");
    portal.load("portal.mp3");
    bPlayerFinish = false;
}

Game::~Game(){
    ofLogNotice() << "Deleting game";
    delete gameObjects;
    delete generator;
    delete currentState();
}

void Game::init(){
    
    if(gameObjects != nullptr)
        delete gameObjects;
    
    
    gameObjects = new GameObjectContainer();
    
    player = new Player(this);
    player->init();

    //cam.setPosition(0, 300, -600);
    cam.setPosition(0, 400, -1500);
    cam.setTarget(player->transform);
    cam.setParent(player->transform);
    //cam.disableMouseInput();
    cam.setFarClip(100000);
    
    gameObjects->add(player);
    generator->generateWorld();
    bPlayerFinish = false;
    initTime = ofGetElapsedTimef();
    pauseTime = 0;
}

void Game::update(){
    gameObjects->update();
}

void Game::draw(){
    //ofBackground(ofColor::mediumPurple);
    ofEnableLighting();
    ofEnableDepthTest();
    
    cam.begin();
    {
        if(bDebug) gameObjects->drawDebug();
        else gameObjects->draw();
    }
    cam.end();
    
    ofDisableLighting();
    ofDisableDepthTest();
}


Player * Game::getPlayer(){
    return player;
}

vector<GameObject *> Game::getCollisions(GameObject *gameObject){
    return gameObjects->getCollisions(gameObject);
}

void  Game::addGameObject(GameObject *gameobject){
    gameObjects->add(gameobject);
}

void Game::finishGame(){
    bPlayerFinish = true;
}

void Game::toggleDebug(){
    bDebug = !bDebug;
}

bool Game::isFinished(){
    return bPlayerFinish;
}

void Game::setFinished(bool v){
    bPlayerFinish = v;
}

float Game::getEllapsedTime(){
    return ofGetElapsedTimef() - initTime - pauseTime;
}

void Game::enterPause() {
    initPauseTime = ofGetElapsedTimef();
}

void Game::exitPause() {
    pauseTime += ofGetElapsedTimef() - initPauseTime;
}

void Game::doScream(){
    scream.play();
}

void Game::doExplotion() {
    explotion.play();
}

void Game::doPortal() {
    portal.play();
}


