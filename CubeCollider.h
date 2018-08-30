/////////////////////////////////////////////////////////////////////////////////////////////        
/// @class CubeCollider
///
/// @brief This is a cube collider. It is a 3D version of a box collider.
/// This implementation is axis alined and does not change in any way based on the oreintation of the object.
/// @note This means for example for the boat that collisions from the side may be detected too early.
/// 
/// @author Maurice Hendrix
///////////////////////////////////////////////////////////////////////////////////////////// 
#pragma once
#include "Collider.h"
/* OPENGL_INCLUDES */
#ifndef OPENGL_INCLUDES
#define OPENGL_INCLUDES
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif 

class CubeCollider : public Collider {
private:
public:
	float length = 0.0, width = 0.0, height = 0.0;
	CubeCollider(glm::vec3 * centre, float cubeWidth, float cubeHeight, float cubeLength);
	~CubeCollider(); ///<Default destructor.

	float minX();
	float maxX();
	float minY();
	float maxY();
	float minZ();
	float maxZ();
	bool collidesWith(Collider * other);  ///< Implementation of fuction deciding if this collider collides with the other one.
	void Draw();
};