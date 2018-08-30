/////////////////////////////////////////////////////////////////////////////////////////////        
/// @class GameObject
/// @brief This class is the base class for all objects in the scene. It is a pure virtual class and you cannot directly instantiate it but you can create classes that extend it and those can all be added to the scene.
///
/// @author Maurice Hendrix
///////////////////////////////////////////////////////////////////////////////////////////// 
#pragma once
/* OPENGL_INCLUDES */
#ifndef OPENGL_INCLUDES
#define OPENGL_INCLUDES
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif 

#include <map>
#include <iostream>
#include "Collider.h" //gameobjects can have a collider

class GameObject {
protected:
	unsigned int base;  ///<Base index for display lists.
public:
	static std::map <int, bool> specialKeys;
	static std::map <char, bool> keys;
	static bool debugMode;
	bool active = true;
	Collider* collider = NULL;  ///<Pointer to a collider for the game object. Initially NULL to indicate that we do not want to calculate collisions.
								//glm::vec3 colour = glm::vec3(0.0, 0.0, 0.0);	//Colour of the gameobject
	glm::vec3 position = glm::vec3(0.0, 0.0, 0.0);  ///<Position of the gameobject.
	glm::vec3 heading = glm::vec3(0.0, 0.0, -1.0);  ///<Heading (direction) the gameobject is facing.


	GameObject(glm::vec3 pos);
	~GameObject(); ///<Standard destructor.


	virtual unsigned int setupDrawing(unsigned int listBase) = 0;
	virtual void drawScene(); ///<Function to perform this object's part of the redraw work. Can override in inherited classes.

							  /* Every GameObject must implement the following pure virtual function or otherwise cause a compile error.*/
	virtual void start() = 0; ///<Pure virtual start function, run once when the engine starts.  Must override in inherited classes.
	virtual void update(int deltaTime) = 0; ///<Pure virtual update function, run periodicly to update the game state.  Must override in inherited classes.

	virtual void collides(Collider* other); ///<Virtual function to notify this game object that a collision has happened can be overridden (optional).
};
