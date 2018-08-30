/////////////////////////////////////////////////////////////////////////////////////////////        
/// @class SpaceShip
/// @brief This class is the class that represents the SpaceShip.
///
/// @author Maurice Hendrix
///////////////////////////////////////////////////////////////////////////////////////////// 
#pragma once
#include "GameObject.h"
#include <cmath>
#include<glm/gtx/rotate_vector.hpp>
#include "getbmp.h"
#define TURNING_SPEED 90.0 //<turning speed in degrees per second
#define MOVE_SPEED 0.00001//<move speed in coordinate units per second
#define MAX_SPEED 0.35
#define MINUS_SPEED -0.2

extern float moveStep;
class SpaceShip : public GameObject {
private:
	glm::vec3 startingHeading = heading; ///<Starting facing direction of the spaceship.
	float rotationAngle, pitchAngle = 0.0; ///<Angle at which the ship is rotated.

public:
	unsigned int texture[2];
	BitMapFile*image[2];

	SpaceShip(glm::vec3 pos);
	~SpaceShip(); ///<default deconstructor

	unsigned int setupDrawing(unsigned int listBase); ///<Override setup method.
	void drawScene(); ///<Override drawscene method.
	void start();  ///<Override start method.
	void update(int deltaTime);  ///<Override update method.
	void collides(Collider * other); ///<Override method that reacts to a collision.
};

