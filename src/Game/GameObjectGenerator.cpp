
#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Goal.h"
#include "Coin.h"
#include "Pedestrian.h"
#include "Barrier.h"
#include "Hole.h"
#include "Dirt.h"
#include "Oil.h"
#include "CrazyArch.h"
#include "Crane.h"
#include "Turbo.h"
#include "Plane.h"
#include "Bomb.h"
#include "ExplosionArea.h"
#include "Portal.h"
#include "LightArch.h"
#include "Obstacle.h"

#include <time.h>

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){

    srand(time(NULL));
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;
    
    glm::vec3 roadPos(0, -50.1, L/2);
    auto road = new Road(game, roadPos, glm::vec3(W, 0, L));
    
    game->addGameObject(road);
//
    int wallSize = 100;

    


//    for(int x = 0; x < w; x++){
//        for(int y = 0; y < h; y++){
//            if(circuito.getColor(x, y).a > 250){
//
//                auto wall = new Wall(game,
//                                glm::vec3(x*wallSize - 5000, roadPos.y, y*wallSize -2000),
//                                glm::vec3(wallSize*0.99));
//                game->addGameObject(wall);
//            }
//        }
//    }

    
//     WALL with parts
//    for(int l = 0; l < L; l += wallSize){
//        auto wall_r = new Wall(game,
//                        glm::vec3(-W/2, roadPos.y, l - 1000 + wallSize/2),
//                        glm::vec3(wallSize));
//
//        wall_r->isFixed = true;
//        game->addGameObject(wall_r);
//
//    }
    
    
    auto wall_r = new Wall(game,
                    glm::vec3(-W/2, roadPos.y, roadPos.z - L/2 + L/8),
                           glm::vec3(wallSize, wallSize, L/4));
    game->addGameObject(wall_r);

    /*wall_r = new Wall(game,
                    glm::vec3(-W/2, roadPos.y, roadPos.z - L/4 * 0.8),
                           glm::vec3(wallSize, wallSize, L/4));
    game->addGameObject(wall_r);
    */

    wall_r = new Wall(game,
            glm::vec3(-W / 2, roadPos.y, roadPos.z - L / 8),
                glm::vec3(wallSize, wallSize, L / 4));
    game->addGameObject(wall_r);

    wall_r = new Wall(game,
            glm::vec3(-W / 2, roadPos.y, roadPos.z + L / 8),
                glm::vec3(wallSize, wallSize, L / 4));
    game->addGameObject(wall_r);

    wall_r = new Wall(game,
            glm::vec3(-W / 2, roadPos.y, roadPos.z + L / 2 - L / 8),
                glm::vec3(wallSize, wallSize, L / 4));
    game->addGameObject(wall_r);

    
    

    auto wall_l = new Wall(game,
                    glm::vec3(W/2, roadPos.y, roadPos.z - L / 2 + L/8),
                           glm::vec3(wallSize, wallSize, L/4));
    game->addGameObject(wall_l);

    /*
    wall_l = new Wall(game,
                    glm::vec3(W/2, roadPos.y, roadPos.z - L/4 * 0.8),
                           glm::vec3(wallSize, wallSize, L/4));
    game->addGameObject(wall_l);
    */

    wall_l = new Wall(game,
            glm::vec3(W / 2, roadPos.y, roadPos.z - L / 8),
                glm::vec3(wallSize, wallSize, L / 4));
    game->addGameObject(wall_l);

    wall_l = new Wall(game,
            glm::vec3(W / 2, roadPos.y, roadPos.z + L / 8),
                glm::vec3(wallSize, wallSize, L / 4));
    game->addGameObject(wall_l);

    wall_l = new Wall(game,
            glm::vec3(W / 2, roadPos.y, roadPos.z + L / 2 - L / 8),
                glm::vec3(wallSize, wallSize, L / 4));
    game->addGameObject(wall_l);
//
    auto goal = new Goal(game,
                    glm::vec3(0, roadPos.y, roadPos.z + L/2),
                           glm::vec3(W, 100, 100));
    goal->isFixed = true;
    game->addGameObject(goal);
    

    

    for (int i = 0; i < 10; i++) {
        auto coin = new Coin(game,
            glm::vec3((rand() % (W - 200) + 100) - W/2, -25, rand() % (L - 2000) + 1000), glm::vec3(50));

        game->addGameObject(coin);
    }

    for (int i = 0; i < 10; i++) {
        auto obstacle = new Obstacle(game,
            glm::vec3((rand() % (W - 200) + 100) - W / 2, 25, rand() % (L - 2000) + 1000), glm::vec3(100));

        game->addGameObject(obstacle);
    }
    
    
    auto pedestrian = new Pedestrian(game,
        glm::vec3(W/2 - 100, -25, 3000), glm::vec3(50, 150, 50));

    game->addGameObject(pedestrian);

    pedestrian = new Pedestrian(game,
        glm::vec3(W / 2 - 100, -25, 10000), glm::vec3(50, 150, 50));

    game->addGameObject(pedestrian);

    pedestrian = new Pedestrian(game,
        glm::vec3(W / 2 - 100, -25, 26000), glm::vec3(50, 150, 50));

    game->addGameObject(pedestrian);





	auto barrier = new Barrier(game,
		glm::vec3(0, 600,8000), glm::vec3(W - wallSize , 500, 100));

	game->addGameObject(barrier);

    barrier = new Barrier(game,
        glm::vec3(0, 600, 16000), glm::vec3(W - wallSize, 500, 100));

    game->addGameObject(barrier);




    
	auto hole = new Hole(game,
		glm::vec3(0, -48, 6000), glm::vec3(500, 0.1, 500), road);

	game->addGameObject(hole);

    hole = new Hole(game,
        glm::vec3(200, -48, 16500), glm::vec3(600, 0.1, 600), road);

    game->addGameObject(hole);

    hole = new Hole(game,
        glm::vec3(-500, -48, 21500), glm::vec3(600, 0.1, 600), road);

    game->addGameObject(hole);

    hole = new Hole(game,
        glm::vec3(500, -48, 24300), glm::vec3(600, 0.1, 600), road);

    game->addGameObject(hole);

    hole = new Hole(game,
        glm::vec3(100, -48, 29500), glm::vec3(900, 0.1, 900), road);

    game->addGameObject(hole);

    hole = new Hole(game,
        glm::vec3(200, -48, 32800), glm::vec3(1200, 0.1, 1200), road);

    game->addGameObject(hole);




    auto dirt = new Dirt(game,
        glm::vec3(400, -50, 2700), glm::vec3(500, 0.1, 500));

    game->addGameObject(dirt);

	dirt = new Dirt(game,
		glm::vec3(-500, -50, 7350), glm::vec3(500, 0.1, 500));

	game->addGameObject(dirt);

    dirt = new Dirt(game,
        glm::vec3(500, -50, 7250), glm::vec3(600, 0.1, 600));

    game->addGameObject(dirt);

    dirt = new Dirt(game,
        glm::vec3(-300, -50, 9500), glm::vec3(400, 0.1, 400));

    game->addGameObject(dirt);

    dirt = new Dirt(game,
        glm::vec3(0, -50, 19400), glm::vec3(2000, 0.1, 300));

    game->addGameObject(dirt);

    dirt = new Dirt(game,
        glm::vec3(-400, -50, 23600), glm::vec3(600, 0.1, 600));

    game->addGameObject(dirt);

    dirt = new Dirt(game,
        glm::vec3(-300, -50, 37100), glm::vec3(500, 0.1, 300));

    game->addGameObject(dirt);





	auto oil = new Oil(game,
        glm::vec3(-500, -50, 3500), glm::vec3(300, 0.1, 300));

    game->addGameObject(oil);

    oil = new Oil(game,
        glm::vec3(400, -50, 10300), glm::vec3(700, 0.1, 700));

    game->addGameObject(oil);

    oil = new Oil(game,
        glm::vec3(-700, -50, 24520), glm::vec3(400, 0.1, 400));

    game->addGameObject(oil);

    oil = new Oil(game,
        glm::vec3(100, -50, 36030), glm::vec3(700, 0.1, 700));

    game->addGameObject(oil);





    auto crazyArch = new CrazyArch(game,
        glm::vec3(0, roadPos.y, 6000),
        glm::vec3(W, 100, 100));
    crazyArch->isFixed = true;
    game->addGameObject(crazyArch);

    crazyArch = new CrazyArch(game,
        glm::vec3(0, roadPos.y, 11200),
        glm::vec3(W, 100, 100));
    crazyArch->isFixed = true;
    game->addGameObject(crazyArch);

    crazyArch = new CrazyArch(game,
        glm::vec3(0, roadPos.y, 28000),
        glm::vec3(W, 100, 100));
    crazyArch->isFixed = true;
    game->addGameObject(crazyArch);





	auto crane = new Crane(game,
		glm::vec3(0, 300, 9000),glm::vec3(50, 200, 50));

	game->addGameObject(crane);

    crane = new Crane(game,
        glm::vec3(0, 300, 15000), glm::vec3(50, 200, 50));

    game->addGameObject(crane);

    crane = new Crane(game,
        glm::vec3(0, 300, 22000), glm::vec3(50, 200, 50));

    game->addGameObject(crane);

    crane = new Crane(game,
        glm::vec3(0, 300, 4000), glm::vec3(50, 200, 50));

    game->addGameObject(crane);





    auto turbo = new Turbo(game,
        glm::vec3(400, -48, 4700), glm::vec3(400, 0.1, 400));

    game->addGameObject(turbo);

    turbo = new Turbo(game,
        glm::vec3(200, -48, 15000), glm::vec3(400, 0.1, 400));

    game->addGameObject(turbo);

    turbo = new Turbo(game,
        glm::vec3(0, -48, 26800), glm::vec3(400, 0.1, 400));

    game->addGameObject(turbo);

    turbo = new Turbo(game,
        glm::vec3(-500, -48, 38600), glm::vec3(400, 0.1, 400));

    game->addGameObject(turbo);





    int planeY = 600, planeZ = 20700;

    auto plane = new Plane(game,
        glm::vec3(-W / 2 - 1000, planeY, planeZ), glm::vec3(50, 150, 50));
    game->addGameObject(plane);

    auto bomb = new Bomb(game,
        glm::vec3(0, planeY, planeZ), glm::vec3(150, 50, 50));
    game->addGameObject(bomb);

    auto explosionArea = new ExplosionArea(game,
        glm::vec3(0, -50, planeZ), glm::vec3(1600, 0.1, 1600));
    game->addGameObject(explosionArea);

    planeY = 600, planeZ = 13000;

    plane = new Plane(game,
        glm::vec3(-W / 2 - 1000, planeY, planeZ), glm::vec3(50, 150, 50));
    game->addGameObject(plane);

    bomb = new Bomb(game,
        glm::vec3(0, planeY, planeZ), glm::vec3(150, 50, 50));
    game->addGameObject(bomb);

    explosionArea = new ExplosionArea(game,
        glm::vec3(0, -50, planeZ), glm::vec3(1600, 0.1, 1600));
    game->addGameObject(explosionArea);





    auto portal = new Portal(game,
        glm::vec3(0, 100, 0), glm::vec3(0, 0, 1500), glm::vec3(2000, 0.1, 300));
    game->addGameObject(portal);

    portal = new Portal(game,
        glm::vec3(300, 100, 8630), glm::vec3(300, 0, 10500), glm::vec3(300, 0.1, 300));
    game->addGameObject(portal);

    portal = new Portal(game,
        glm::vec3(-500, 100, 16200), glm::vec3(0, 0, 1500), glm::vec3(300, 0.1, 300));
    game->addGameObject(portal);

    portal = new Portal(game,
        glm::vec3(500, 100, 27800), glm::vec3(0, 0, 30100), glm::vec3(300, 0.1, 300));
    game->addGameObject(portal);

    portal = new Portal(game,
        glm::vec3(500, 100, 38300), glm::vec3(0, 0, 1500), glm::vec3(300, 0.1, 300));
    game->addGameObject(portal);





    auto lightArch = new LightArch(game,
        glm::vec3(0, roadPos.y, 25000),
        glm::vec3(W, 100, 100), true, road);
    crazyArch->isFixed = true;
    game->addGameObject(lightArch);

    lightArch = new LightArch(game,
        glm::vec3(0, roadPos.y, 35000),
        glm::vec3(W, 100, 100), false, road);
    crazyArch->isFixed = true;
    game->addGameObject(lightArch);
}
