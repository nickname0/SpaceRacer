#include "SpaceShip.h"
#include "CubeCollider.h"
#include "GameEngine.h"
#include "GameObject.h"

SpaceShip::SpaceShip(glm::vec3 pos) :GameObject(pos) {
	SpaceShip::collider = new CubeCollider(&this->position, 1.5, 1.5, 1.5);
}

SpaceShip::~SpaceShip() {
	delete SpaceShip::collider;
	SpaceShip::collider = NULL;
}




unsigned int SpaceShip::setupDrawing(unsigned int listBase) {
	

	image[0] = getbmp("Texture/Spaceship.bmp");
	image[1] = getbmp("Texture/Fire.bmp");
	glGenTextures(2, texture);
	GLUquadricObj *pQuadric = gluNewQuadric();

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->sizeX, image[0]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[1]->sizeX, image[1]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[1]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	this->base = listBase;
	// Draw ship.
	glNewList(this->base, GL_COMPILE);
	
	glPushMatrix();
	gluQuadricDrawStyle(pQuadric, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	gluQuadricTexture(pQuadric, true);
	gluQuadricNormals(pQuadric, GLU_SMOOTH);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glEnable(GL_TEXTURE_2D);
	gluSphere(pQuadric, 0.5, 30, 30);
	glFlush();
	glPopMatrix();

	glPushMatrix();
	gluQuadricDrawStyle(pQuadric, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	gluQuadricTexture(pQuadric, true);
	gluQuadricNormals(pQuadric, GLU_SMOOTH);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glEnable(GL_TEXTURE_2D);
	gluCylinder(pQuadric, 0.5,0.5,1.5, 30, 30);
	glFlush();
	glPopMatrix();

	glPushMatrix();
	gluQuadricDrawStyle(pQuadric, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	gluQuadricTexture(pQuadric, true);
	gluQuadricNormals(pQuadric, GLU_SMOOTH);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glEnable(GL_TEXTURE_2D);
	glTranslatef(0, 0, 1.5);
	gluDisk(pQuadric, 0, 0.5, 100, 100);
	glFlush();
	glPopMatrix();

	
	

	/*glPushMatrix(); //BODY
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_GEN_S,texture[0]);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTranslatef(0, 0, 0);
	glutSolidCylinder(0.6, 1.5, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	
	glPopMatrix();*/

	/*glPushMatrix();
	glColor3f(0, 1, 1);
	glTranslated(0, 0, 0);
	glPopMatrix;*/

	/*glPushMatrix(); // Wing
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(-0.1, 0.3, 0.5);
	glVertex3f(-0.1, 0.3, 1.5);
	glVertex3f(-1.1, 1.3, 1.5);
	glEnd();
	glPopMatrix();
	
	//Wing
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(0.1, 0.3, 0.5);
	glVertex3f(0.1, 0.3, 1.5);
	glVertex3f(1.1,1.3, 1.5);
	glEnd();
	glPopMatrix();
	
	//Wing
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(0.1, 0.3, 0.5);
	glVertex3f(-0.1, 0.3, 1.5);
	glVertex3f(1.1, 1.3, 1.5);
	glEnd();
	glPopMatrix();*/

	/*//tailpipe
	glPushMatrix();
	glColor3f(1.0, 0, 0);
	glTranslatef(0, 0, 1.8);
	glRotatef(180, 0, 1, 0);
	glutSolidCone(0.4, 0.5, 30, 30);
	glPopMatrix();*/

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glEndList();
	glFlush();
	return this->base + 1;
}

void SpaceShip::drawScene() {
	glPushMatrix();
	glTranslatef(this->position.x, this->position.y, this->position.z);

	//rotate openGL object
	glRotatef(pitchAngle, 0.0, 0.0, 1.0);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);
	glCallList(this->base); // Draw SpaceShip.
	glPopMatrix(); // End draw SpaceShip.

				   //if we are in debug mode then:
	if (debugMode) {
		//display heading vector
		glPushMatrix();
		glBegin(GL_LINES);
		glColor3f(0, 1, 0);
		glVertex3f(position.x, position.y, position.z);
		glVertex3f(position.x + heading.x, position.y + heading.y, position.z + heading.z);
		glEnd();
		glPopMatrix();
		//display the collider bounding box
		this->collider->Draw();
	}
}

void SpaceShip::start() {
}
float moveStep = 0.001;
float maxSpeed = MAX_SPEED;
float minusSpeed = MINUS_SPEED;

void SpaceShip::update(int deltaTime) { //movement speed in units per second * deltaTime in sec = moveStep
	float turningSpeed = TURNING_SPEED *  (deltaTime / 1000.0); //turning speed (degrees/sec) * deltaTime in sec = turning speed over delta time
																/*if (specialKeys[GLUT_KEY_ALT_L])
																{
																gluLookAt(10, 5, 10, cameraFollow->position.x, cameraFollow->position.y, cameraFollow->position.z, 0.0, 1.0, 0.0);
																}*/
	if (specialKeys[GLUT_KEY_DOWN]) {
		moveStep -= 0.001 * deltaTime / 2;
		this->position -= this->heading * moveStep;
	}
	this->position += this->heading *moveStep;

	if (specialKeys[GLUT_KEY_PAGE_UP]) {
		this->pitchAngle += turningSpeed;
	}

	if (specialKeys[GLUT_KEY_PAGE_DOWN]) {
		this->pitchAngle -= turningSpeed;
	}

	if (specialKeys[GLUT_KEY_UP]) {
		moveStep += 0.001 * deltaTime / 2;
		this->position += this->heading * moveStep;
	}
	//std::cout << moveStep << std::endl;
	this->position += this->heading *moveStep;

	if (specialKeys[GLUT_KEY_RIGHT]) {
		this->rotationAngle -= turningSpeed; //in degrees not radians
	}
	if (specialKeys[GLUT_KEY_LEFT]) {
		this->rotationAngle += turningSpeed; //in degrees not radians
	}

	if (moveStep>0)
	{
		moveStep -= 0.001;
	}
	if (moveStep < 0)
	{
		moveStep += 0.001;
	}
	if (moveStep > maxSpeed)
	{
		moveStep = maxSpeed;
	}
	if (moveStep < minusSpeed) {
		moveStep = minusSpeed;
	}

	//rotate the heading
	//In the drawscene we will need to rotate by the full rotation since the start
	//Therfore we start heard from the original startingheading, so that we can use the same variables for the rotations
	this->heading = glm::rotate(this->startingHeading, glm::radians(rotationAngle), glm::vec3(0.0, 1.0, 0.0));
	this->heading = glm::rotate(this->heading, glm::radians(pitchAngle), glm::vec3(0.0, 0.0, 1.0));
}

void SpaceShip::collides(Collider* other) {
	if (debugMode) {
		std::cout << "SpaceShip collides!" << std::endl;
	}
}