#pragma once
#include "GameObject.h"


struct Colou {
	float r, g, b;
};

class SpeedBall : public GameObject
{
public:

	SpeedBall(glm::vec3 pos, Colou col = { 0.0,1,0 });
	~SpeedBall();///<Default destructor.

	Colou colou;///<Current colour of the object.

				/* Overridden from the GameObject class.*/
	unsigned int setupDrawing(unsigned int listBase);///<Overridden setup drawing method.
	void start();  ///Overridden start method.
	void update(int deltaTime);  ///<Overridden update method.
	void collides(Collider * other);///<Overridden collides method.
};