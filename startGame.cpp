/////////////////////////////////////////////////////////////////////////////////////////////        
/// StartGame.cpp
///
/// @brief This is the "main" which initialises the engine and starts the game.
///
/// @author Maurice Hendrix
///////////////////////////////////////////////////////////////////////////////////////////// 
/* OPENGL_INCLUDES */
#ifndef OPENGL_INCLUDES
#define OPENGL_INCLUDES
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif 

#include <vector>
#include "SlowBall.h"
#include "speedBall.h"
#include "Asteroid.h";
//#include "Wall.h"
#include "SpaceShip.h";
#include <cmath>;
#define PI 3.14159265
#include "GameEngine.h"

int main(int argc, char **argv)
{
	GameEngine::initEngine(argc, argv);

	int count = 0;
	int count1 = 63;
	//GameEngine::addGameObject(new SpeedBall(glm::vec3(5, 0, 5)));
	GameEngine::addGameObject(new SpeedBall(glm::vec3(7, 0, 35)));
	GameEngine::addGameObject(new SlowBall(glm::vec3(3, 0, 35), { 1,0,0 }));

	/*for (int i = 0; i < 21; i++)//1st straight lane yellow
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(0, 0, count), { 0.47,0.47,0.47 }));
		count += 3;
	}/*
	count = 0;
	for (int i = 0; i < 18; i++)//1st inner straight lane yellow
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(10, 0, count), { 0.47,0.47,0.47 }));
		count += 3;
	}
	count = 0;
	for (int i = 0; i < 21; i++)// 1st turn red
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count, 0, count1), { 0.47,0.47,0.47 }));
		count += 3;
		count1 += 3;
	}
	count = 0;
	count1 = 54;
	for (int i = 0; i < 20; i++)//1st inner turn red
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count + 10, 0, count1), { 0.47,0.47,0.47 }));
		count += 3;
		count1 += 3;
	}
	count = 69;

	for (int i = 0; i < 17; i++)// 1st horizontal inner lane blue
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count, 0, 114), { 0.47,0.47,0.47 }));
		count += 3;
	}
	count = 63;
	for (int i = 0; i < 21; i++)// 1st horizontal lane blue
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count, 0, 126), { 0.47,0.47,0.47 }));
		count += 3;

	}

	count1 = 126;
	count = 126;
	for (int i = 0; i <21; i++)// 2nd turn green
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count1, 0, count), { 0.47,0.47,0.47 }));
		count -= 3;
		count1 += 3;
	}
	count1 = 120;
	count = 112;
	for (int i = 0; i < 18; i++)// 2nd turn inner green
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count1, 0, count), { 0.47,0.47,0.47 }));
		count -= 3;
		count1 += 3;
	}
	count = 58;
	for (int i = 0; i < 18; i++)//1st straight inner lane pink
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(174, 0, count), { 0.47,0.47,0.47 }));
		count -= 3;
	}
	count = 61;
	for (int i = 0; i < 21; i++)//1st straight lane pink
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(187, 0, count), { 0.47,0.47,0.47 }));
		count -= 3;
	}
	count = 184;
	count1 = -3;
	for (int i = 0; i < 23; i++)// 3rd turn light green
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count, 0, count1), { 0.47,0.47,0.47 }));
		count -= 3;
		count1 -= 3;
	}
	count = 181;
	count1 = 5;
	for (int i = 0; i < 20; i++)//3rd inner turn light green
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count - 10, 0, count1), { 0.47,0.47,0.47 }));
		count -= 3;
		count1 -= 3;
	}
	count = 111;

	for (int i = 0; i < 17; i++)// 2nd horizontal inner lane white
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count, 0, -55), { 0.47,0.47,0.47 }));
		count -= 3;
	}
	count = 114;
	for (int i = 0; i < 17; i++)// 2nd horizontal lane white
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count, 0, -70), { 0.47,0.47,0.47 }));
		count -= 3;

	}
	count = -50;
	count1 = 58;
	for (int i = 0; i <16; i++)// 4th turn inner
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count1, 0, count), { 0.47,0.47,0.47 }));
		count += 3;
		count1 -= 3;
	}
	count = -67;
	count1 = 64;
	for (int i = 0; i <22; i++)// 4th turn 
	{
		GameEngine::addGameObject(new Asteroid(glm::vec3(count1, 0, count), { 0.47,0.47,0.47 }));
		count += 3;
		count1 -= 3;
	}*/
	/*GameEngine::addGameObject(new Asteroid(glm::vec3(-50, 0, 0), { 1.0,1.0,0.0 }));
	count1 = count1 + 5;
	GameEngine::addGameObject(new Asteroid(glm::vec3(count2 - 200, 0, 400), { 1.0,1.0,0.0 }));
	count2 = count2 + 5;
	GameEngine::addGameObject(new Asteroid(glm::vec3(count3 - 200, 0, 400 - count), { 1.0,1.0,0.0 }));
	count3 = count3 + 5;*/
	//count2 = count2 + 5;
	//count1 = count1 + 5;
	//count = count + 5;
	//}


	GameEngine::addGameObject(new SpaceShip(glm::vec3(-15, 2, 10)), true);
	GameEngine::startEngine();

	return 0;
}