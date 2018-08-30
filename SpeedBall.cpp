#include "speedBall.h"
#include "SpaceShip.h"
#include "CubeCollider.h"

SpeedBall::SpeedBall(glm::vec3 pos, Colou colr) : GameObject(pos) {
	this->colou = colr;
	SpeedBall::collider = new CubeCollider(&this->position, 2, 2, 2);
}

SpeedBall::~SpeedBall() {
	delete SpeedBall::collider;
	SpeedBall::collider = NULL;
}

unsigned int  SpeedBall::setupDrawing(unsigned int listBase) {
	this->base = listBase;
	glNewList(this->base, GL_COMPILE);
	glPushMatrix();
	glColor3f(colou.r, colou.g, colou.b);
	glTranslatef(0, 0, 0);
	glutSolidSphere(1.0, 40, 40);
	glPopMatrix();
	glEndList();

	return this->base + 1;
}

void SpeedBall::start() {
}

void SpeedBall::update(int deltaTime) {
}

void SpeedBall::collides(Collider* other) {
	if (debugMode) {
		std::cout << "Boost collides, asteroid will be removed!" << std::endl;
	}
	this->active = false;
	moveStep = moveStep + 0.4;
}