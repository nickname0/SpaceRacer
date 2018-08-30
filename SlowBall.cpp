#include "SlowBall.h"
#include "SpaceShip.h"
#include "CubeCollider.h"

SlowBall::SlowBall(glm::vec3 pos, Colourr colr) : GameObject(pos) {
	this->colourr = colr;
	SlowBall::collider = new CubeCollider(&this->position, 2, 2, 2);
}

SlowBall::~SlowBall() {
	delete SlowBall::collider;
	SlowBall::collider = NULL;
}

unsigned int  SlowBall::setupDrawing(unsigned int listBase) {
	this->base = listBase;
	glNewList(this->base, GL_COMPILE);
	glPushMatrix();
	glColor3f(colourr.r, colourr.g, colourr.b);
	glTranslatef(0, 0, 0);
	glutSolidSphere(1.0, 40, 40);
	glPopMatrix();
	glEndList();

	return this->base + 1;
}

void SlowBall::start() {
}

void SlowBall::update(int deltaTime) {
}

void SlowBall::collides(Collider* other) {
	if (debugMode) {
		std::cout << "Taking speed collides, boost will be removed!" << std::endl;
	}
	this->active = false;
	moveStep = 0.001;
}