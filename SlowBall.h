#pragma once
#include "GameObject.h"


struct Colourr {
	float r, g, b;
};

class SlowBall : public GameObject
{
public:

	SlowBall(glm::vec3 pos, Colourr colrr = { 1,0,1 });
	~SlowBall();///<Default destructor.

	Colourr colourr;///<Current colour of the object.

					/* Overridden from the GameObject class.*/
	unsigned int setupDrawing(unsigned int listBase);///<Overridden setup drawing method.
	void start();  ///Overridden start method.
	void update(int deltaTime);  ///<Overridden update method.
	void collides(Collider * other);///<Overridden collides method.
};