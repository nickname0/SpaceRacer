/////////////////////////////////////////////////////////////////////////////////////////////        
/// GameEngine.cpp
///
/// Implementation for a simple example game engine.
///
/// @author Maurice Hendrix
///////////////////////////////////////////////////////////////////////////////////////////// 
#include "GameEngine.h"
#include "SpaceShip.h"
#include <iostream>
#include "GameObject.h"
#include "getbmp.h"
#include "Asteroid.h";


bool GameEngine::debugMode;
std::vector<GameObject*> GameEngine::gameobjects; //The definition of static variables needs to be repeated in the cpp file.
GameObject* GameEngine::cameraFollow;
int GameEngine::oldTimeSinceStart;
int GameEngine::newTimeSinceStart;
std::map <int, bool> GameObject::specialKeys;
std::map <char, bool> GameObject::keys;
unsigned int GameEngine::base; // Generate display list base. 
static long font = (long)GLUT_BITMAP_8_BY_13;

static unsigned int texture[12];

int camera = 0;


static int isAnimate = 1;
static int animationPeriod = 30;
int angle = 0.0;

void increaseAngle(void)
{
	angle += 1;
}

void animate(int value)
{
	if (isAnimate == 1)
	{
		increaseAngle();
		glutPostRedisplay();
		glutTimerFunc(animationPeriod, animate, 1);
	}
}

void loadExternalTexture()
{
	BitMapFile *image[12];

	image[0] = getbmp("Texture/bottom.bmp");
	image[1] = getbmp("Texture/front.bmp");
	image[2] = getbmp("Texture/left.bmp");
	image[3] = getbmp("Texture/top.bmp");
	image[4] = getbmp("Texture/back.bmp");
	image[5] = getbmp("Texture/right.bmp");
	image[6] = getbmp("Texture/Sun.bmp");
	image[7] = getbmp("Texture/Saturn.bmp");
	image[8] = getbmp("Texture/SaturnRing.bmp");
	image[9] = getbmp("Texture/Titan.bmp");
	image[10] = getbmp("Texture/RHEA.bmp");
	image[11] = getbmp("Texture/Phobos.bmp");

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

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[2]->sizeX, image[2]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[2]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[3]->sizeX, image[3]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[3]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[4]->sizeX, image[4]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[4]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[5]->sizeX, image[5]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[5]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[6]->sizeX, image[6]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[6]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[7]->sizeX, image[7]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[7]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[8]->sizeX, image[8]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[8]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[9]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[9]->sizeX, image[9]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[9]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[10]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[10]->sizeX, image[10]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[10]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[11]->sizeX, image[11]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[11]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void writeBitmapString(void *font, char *string)
{
	const char*c;
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void print(float x, float y, float z, char* string)
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glRasterPos3f(x, y, z);
	writeBitmapString((void*)font, string);
	glPopMatrix();
}
void GameEngine::initEngine(int argc, char **argv, const char* windowTitle, bool debug, int width, int height) {
	GameEngine::debugMode = debug;
	GameObject::debugMode = GameEngine::debugMode;
	//Init glut.
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(windowTitle);

	glewExperimental = GL_TRUE;
	glewInit();


	//Lambda function defined inside the glutDisplayFunc call to call all relevant drawscenes.
	glutDisplayFunc(displayFunc);

	//Lambda function defined inside glutReshapeFunc to do resize logic.
	glutReshapeFunc(reshapeFunc);

	//Lambda functions to link our code to glut's keydown andkeyup. Our function deals with both regular and special keys in one.
	glutKeyboardFunc([](unsigned char key, int x, int y) {
		GameObject::keys[key] = true;
		//if we press escape, exit the game
		if (key == 27) {
			cleanup();
			exit(0);
		}

		if (GameObject::keys['0'])
		{
			camera = 0;
		}
		if (GameObject::keys['1'])
		{
			camera = 1;
		}
		if (GameObject::keys['2'])
		{
			camera = 2;
		}
		if (GameObject::keys['3'])
		{
			camera = 3;
		}
		if (GameObject::keys['4'])
		{
			camera=4;
		}
		if (GameObject::keys['5'])
		{
			camera = 5;
		}
		if (GameObject::keys[' '])
		{
			animate(1);
		}


	});

	glutKeyboardUpFunc([](unsigned char key, int x, int y) {
		GameObject::keys[key] = false;
	
	});

	glutSpecialFunc([](int key, int x, int y) {
		GameObject::specialKeys[key] = true;
	});

	glutSpecialUpFunc([](int key, int x, int y) {
		GameObject::specialKeys[key] = false;
	});

	glGenTextures(12, texture);
	loadExternalTexture();
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutIdleFunc(updateGame);
}

void GameEngine::displayFunc() {
	//Prepare for drawing all objects.

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float lightPos0[] = { -450, 500, -400,1.0 };// position
	float lightAmb[] = { 1,1,1,0 }; // Ambient light
	float lightSpec[] = { 1,1,1,1.0 }; // Specular light
	float lightDif[] = { 1.0,1.0,1.0,1.0 }; // Diffuse light

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0); // Position of my light
	

	//glClearColor(0.0, 0.0, 0.0, 0.0);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	char text[9];
	char speedtext[10];

	sprintf_s(text, "%s", "Speed = ");
	sprintf_s(speedtext, "%f", moveStep);

	char c[19];

	strcpy_s(c, text);
	strcat_s(c, speedtext);
	print(-0.2, 1, -2, c);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPopMatrix();
	//If we have no object to follow just put the cam in a static position.
	if (camera == 0) //third person
	{

		if (cameraFollow != NULL)
		{
			//Hardcoded camera variables for the distance bewteen camera and object and y axis distance between camera and object.

			float distance = 6;
			float yAm = 2;

			gluLookAt(cameraFollow->position.x - (cameraFollow->heading.x * distance),
				cameraFollow->position.y - (cameraFollow->heading.y *distance) + yAm,
				cameraFollow->position.z - (cameraFollow->heading.z * distance),
				cameraFollow->position.x, cameraFollow->position.y, cameraFollow->position.z,
				0.0, 1.0, 0.0);

		}

	}
	else if (camera == 1) //first person
	{
		gluLookAt(cameraFollow->position.x, cameraFollow->position.y, (cameraFollow->position.z),
			cameraFollow->position.x - (cameraFollow->heading.x * -10),
			cameraFollow->position.y - (cameraFollow->heading.y * -10),
			cameraFollow->position.z - (cameraFollow->heading.z * -10), 0, 1, 0);
	}
	else if (camera == 2) //Camera 1
	{
		gluLookAt(-12,10,10, cameraFollow->position.x, cameraFollow->position.y, cameraFollow->position.z, 0, 1, 0);
	}
	else if (camera == 3)
	{
		gluLookAt(85, 10, -85, cameraFollow->position.x, cameraFollow->position.y, cameraFollow->position.z, 0, 1, 0);
	}
	else if (camera == 4)
	{
		gluLookAt(182, 10, 10, cameraFollow->position.x, cameraFollow->position.y, cameraFollow->position.z, 0, 1, 0);
	}
	else if (camera == 5)
	{
		gluLookAt(85, 1500, 20, 85, 0, 20, 0, 0, -1);
	}
	else
	{
		gluLookAt(50, 10, 50, 50, 0, 50, 0, 0, -1);
		//gluLookAt(50, 200, 0, 100, 0, 20, 0, 0, -1);
		//gluLookAt(0, 10, 0, 50, 0, 50, 0, 0, -1);
	}

	//Call drawscene for all gameobjects.
	for (std::vector<GameObject*>::size_type i = 0; i != gameobjects.size(); i++) {
		gameobjects[i]->drawScene();
	}

	//SkyBoxex
	
	glPushMatrix();
	glScalef(3, 3, 3);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texture[0]);//bottom
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-200.0, -200.0, 200.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(200.0, -200.0, 200.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(200.0, -200.0, -200.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-200.0, -200.0, -200.0);
	glEnd();
	

	
	glBindTexture(GL_TEXTURE_2D, texture[1]);//front
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-200.0, -200.0, -200.0); //change z value to move further away
	glTexCoord2f(1.0, 0.0); glVertex3f(200.0, -200.0, -200.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(200.0, 200.0, -200.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-200.0, 200.0, -200.0);
	glEnd();
	

	
	glBindTexture(GL_TEXTURE_2D, texture[2]);//left
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-200.0, -200.0, 200.0); //change z value to move further away
	glTexCoord2f(1.0, 0.0); glVertex3f(-200.0, -200.0, -200.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(-200.0, 200.0, -200.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-200.0, 200.0, 200.0);
	glEnd();
	

	
	glBindTexture(GL_TEXTURE_2D, texture[3]);//top
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-200.0, 200.0, -200.0); //change z value to move further away
	glTexCoord2f(1.0, 0.0); glVertex3f(200.0, 200.0, -200.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(200.0, 200.0, 200.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-200.0, 200.0, 200.0);
	glEnd();


	
	glBindTexture(GL_TEXTURE_2D, texture[4]);//back
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(200.0, -200.0, 200.0); //change z value to move further away
	glTexCoord2f(1.0, 0.0); glVertex3f(-200.0, -200.0, 200.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(-200.0, 200.0, 200.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(200.0, 200.0, 200.0);
	glEnd();


	
	glBindTexture(GL_TEXTURE_2D, texture[5]);//right
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(200.0, 200.0, 200.0); //change z value to move further away
	glTexCoord2f(0.0, 1.0); glVertex3f(200.0, 200.0, -200.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(200.0, -200.0, -200.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(200.0, -200.0, 200.0);
	glEnd();
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glPopMatrix();

	
	glPushMatrix();
	GLUquadricObj *pQuadric = gluNewQuadric();
	gluQuadricDrawStyle(pQuadric, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	gluQuadricTexture(pQuadric, true);
	gluQuadricNormals(pQuadric, GLU_SMOOTH);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glEnable(GL_TEXTURE_2D);
	glTranslatef(-450, 500, -400);
	gluSphere(pQuadric, 150, 200, 200);
	//glDisable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glFlush();
	glPopMatrix();




	//Sun FIXING THE TEXTURE
	/*glPushMatrix();
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTranslatef(-500, 500, -300);
	//glColor3f(0.98, 0.8, 0.1);
	glutSolidSphere(100, 200, 200);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
	*/
	/*/Sun ANdrew
	glPushMatrix();
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTranslatef(0, 0, -300);		//THIS IS WHERE I CAN ADD THINGS
	glutSolidSphere(100, 200, 200);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
	*/
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glFlush();
	glPopMatrix();
	
	//Saturn
	glPushMatrix();
	gluQuadricDrawStyle(pQuadric, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	gluQuadricTexture(pQuadric, true);
	gluQuadricNormals(pQuadric, GLU_SMOOTH);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
	glTranslatef(85, 0, 20);
	glRotatef(90, 1, 0, 0);
	gluSphere(pQuadric,60, 200, 200);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glFlush();
	glPopMatrix();

	//Saturn Ring
	glPushMatrix();
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTranslatef(85, 0, 20);
	glRotatef(90, 1, 0,0);
	glScalef(1, 1, 0.1);
	glutSolidTorus(10,100,200,200);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

	//Add Texture TITAN
	glPushMatrix();
	gluQuadricDrawStyle(pQuadric, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texture[9]);
	gluQuadricTexture(pQuadric, true);
	gluQuadricNormals(pQuadric, GLU_SMOOTH);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
	glTranslatef(85, 0, 20);
	glRotatef(angle*1.5, 0, 1, 1);
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(180, 0, 20);
	gluSphere(pQuadric,15, 200, 200);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glFlush();
	glPopMatrix();
	glPopMatrix();

	// Add Texture Rhea
	glPushMatrix();
	gluQuadricDrawStyle(pQuadric, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texture[10]);
	gluQuadricTexture(pQuadric, true);
	gluQuadricNormals(pQuadric, GLU_SMOOTH);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
	glTranslatef(85, 0, 20);
	glRotatef(angle, 0, 1 , 0);
	glPushMatrix();
	//glRotatef(-90, 1, 0, 0);
	glTranslatef(120, 0, 10);
	gluSphere(pQuadric,5, 200, 200);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glFlush();
	glPopMatrix();
	glPopMatrix();
	
	//Phobos

	glPushMatrix();
	gluQuadricDrawStyle(pQuadric, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	gluQuadricTexture(pQuadric, true);
	gluQuadricNormals(pQuadric, GLU_SMOOTH);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
	glTranslatef(85, 0, 20);
	glRotatef(angle*0.5, 0, 1, 0);
	glPushMatrix();
	glTranslatef(210, 0, 10);
	gluSphere(pQuadric,5, 200, 200);
	
	glFlush();
	glPopMatrix();
	glPopMatrix();



	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glFlush();
	glutSwapBuffers(); //Finish Draw Scene.
}

void GameEngine::reshapeFunc(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)w / (float)h, 1.0, 4000.0);
	glMatrixMode(GL_MODELVIEW);
};

void GameEngine::startEngine() {
	//Explain main interaction with scene.
	std::cout << "Keybinds:" << endl;
	std::cout << "Left/Right arrows to rotate the ship." << std::endl;
	std::cout << "Up/Down arrows to move the ship" << std:: endl;
	std::cout << "Space to start animation for the natural satellite, if you keep pressing it the animation will speed up." << std::endl;
	std::cout << "Keys 1,2,3,4,5,0 are for different kind of cameras." << std::endl;
	std::cout << "Press escape to exit." << std::endl;

	//Start game loop.
	glutMainLoop();
}

//Add a new gameobject to the scene.
void GameEngine::addGameObject(GameObject* gameobject, bool camFollow) {
	gameobjects.push_back(gameobject);
	if (camFollow) {
		cameraFollow = gameobject;
	}

	base = glGenLists(1);
	base = gameobject->setupDrawing(base);
	gameobject->start();
}

//Update the game state.
void GameEngine::updateGame() {
	//Calculate delta time (in mili seconds).
	oldTimeSinceStart = newTimeSinceStart;
	newTimeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = newTimeSinceStart - oldTimeSinceStart;
	/*if (specialKeys[GLUT_KEY_ALT_L]) 
	{

	}*/
	//If the last frame was rendered less than 1 ms ago, the detalaTime will be 0 ms. This causes problems in calculations, so sleep for 1ms to adjust.
	if (deltaTime == 0) {
		Sleep(1);
		newTimeSinceStart = glutGet(GLUT_ELAPSED_TIME);
		deltaTime = newTimeSinceStart - oldTimeSinceStart;
	}

	//Remove any inactive objects first.
	for (std::vector<GameObject*>::size_type i = 0; i != gameobjects.size(); i++) {
		if (!gameobjects[i]->active) {
			delete gameobjects[i];
			gameobjects.erase(gameobjects.begin() + i);
		}
	}

	//Run update for all game objects.
	for (std::vector<GameObject*>::size_type i = 0; i != gameobjects.size(); i++) {
		gameobjects[i]->update(deltaTime);
	}

	//Test collisions in a naive way for every pair of gameobjects
	for (std::vector<GameObject*>::size_type i = 0; i != gameobjects.size(); i++) {
		for (std::vector<GameObject*>::size_type j = i + 1; j != gameobjects.size(); j++) {
			if (gameobjects[i]->collider != NULL) {
				if (gameobjects[i]->collider->collidesWith(gameobjects[j]->collider)) {
					gameobjects[i]->collides(gameobjects[j]->collider);
					gameobjects[j]->collides(gameobjects[i]->collider);

					std::cout << "Collusion";
				}
			}
		}
	}

	//Done so indicate that it's time to redraw.
	glutPostRedisplay();
}

//Here we delete pointer objects for when we exit, to prevent memory leaks.
void GameEngine::cleanup() {
	for (auto it = gameobjects.begin(); it != gameobjects.end(); ++it) {
		delete *it;
	}
	gameobjects.clear();
}