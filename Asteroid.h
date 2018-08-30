
#pragma once
#include "GameObject.h"
#include "getbmp.h"

struct Colour {
	double r, g, b;
};

class Asteroid : public GameObject
{
public:

	Asteroid(glm::vec3 pos, Colour col = { 1,1,1 });
	~Asteroid();///<Default destructor.

	Colour colour;///<Current colour of the object.
	unsigned int texture[1];
	BitMapFile*image[1];

				  /* Overridden from the GameObject class.*/
	unsigned int setupDrawing(unsigned int listBase);///<Overridden setup drawing method.
	void start();  ///Overridden start method.
	void update(int deltaTime);  ///<Overridden update method.
	void collides(Collider * other);///<Overridden collides method.
};