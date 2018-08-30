#include "Asteroid.h"
#include "SpaceShip.h"
#include "CubeCollider.h"
#include "getbmp.h"
#include "GameEngine.h"

static float xVal = 0, zVal = 0;

Asteroid::Asteroid(glm::vec3 pos, Colour col) : GameObject(pos) {
	this->colour = col;
	Asteroid::collider = new CubeCollider(&this->position, 2, 2, 2);
}

Asteroid::~Asteroid() {
	delete Asteroid::collider;
	Asteroid::collider = NULL;
}

unsigned int  Asteroid::setupDrawing(unsigned int listBase) {
	
	image[0] = getbmp("Texture/Asteroid.bmp");

	glGenTextures(1, texture);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->sizeX, image[0]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	this->base = listBase;
	glNewList(this->base, GL_COMPILE);
	glPushMatrix();
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_GEN_S, texture[0]);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTranslatef(0, 0, 0);
	glutSolidSphere(1.0, 40, 40);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glPopMatrix();

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glEndList();

	return this->base + 1;
}

void Asteroid::start() {
}

void Asteroid::update(int deltaTime) {
}

void Asteroid::collides(Collider* other) {
	if (debugMode) {
		std::cout << "Asteroid collides, asteroid will be removed!" << std::endl;
	}
	//this->active = false;
	moveStep = -moveStep;
}