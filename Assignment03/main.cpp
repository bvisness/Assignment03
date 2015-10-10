//
//  OpenGL 3.2 Template for Mac
//  Ben Visness
//

// Suppress GLUT deprecated warnings on Mac
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include "Angel.h"
#include "VisnessGL.h"
#include "Boat.h"
#include "FanBlade.h"
#include "Rudder.h"
#include "Water.h"
#include "Empty.h"
#include "Scene.h"
#include "Camera.h"
#include <math.h>
#pragma comment(lib, "glew32.lib")

#include <stdio.h>

//store window width and height
int ww = 1000, wh = 700;

//our modelview and perspective matrices
mat4 mv, p;

const int numBlades = 4;
const Vector4 bladeColors[4] = {
    Vector4(1.0, 1.0, 0.5, 1.0),
    Vector4(0.5, 1.0, 1.0, 1.0),
    Vector4(1.0, 0.5, 0.5, 1.0),
    Vector4(1.0, 0.5, 1.0, 1.0)
};

const int numRudders = 3;
const GLfloat rudderSpacing = 0.7;
const Vector4 rudderColors[3] = {
    Vector4(1.0, 0.8, 0.8, 1.0),
    Vector4(0.8, 1.0, 0.8, 1.0),
    Vector4(0.8, 0.8, 1.0, 1.0)
};

Scene* scene;

Boat* boat;
Empty* fanAnchor;
FanBlade* blades[numBlades];
Rudder* rudders[numRudders];
Water* water;

Camera* lookCam;
Camera* chaseCam;

const GLfloat waterScale = 10;
const GLfloat boatSpeed = 0.1;
const GLfloat boatRotateSpeed = 2;
const GLfloat fanSpeed = 10;
const GLfloat rudderAngle = 35;

bool keyUpArrow;
bool keyDownArrow;
bool keyLeftArrow;
bool keyRightArrow;

void display(void)
{
    /*clear all pixels*/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
#ifdef __APPLE__
		printf("%s\n", gluErrorString(error));
#else
        printf("%s\n", glewErrorString(error));
#endif
	}

    scene->draw();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	/*exit when the escape key is pressed*/
    if (key == 27) {
		exit(0);
    } else if (key == 'r') {
        lookCam->setFOV(lookCam->getFOV() - 3);
    } else if (key == 'f') {
        lookCam->setFOV(lookCam->getFOV() + 3);
    }
}

void special(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        keyUpArrow = true;
    } else if (key == GLUT_KEY_DOWN) {
        keyDownArrow = true;
    } else if (key == GLUT_KEY_LEFT) {
        keyLeftArrow = true;
    } else if (key == GLUT_KEY_RIGHT) {
        keyRightArrow = true;
    }
}

void specialUp(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        keyUpArrow = false;
    } else if (key == GLUT_KEY_DOWN) {
        keyDownArrow = false;
    } else if (key == GLUT_KEY_LEFT) {
        keyLeftArrow = false;
    } else if (key == GLUT_KEY_RIGHT) {
        keyRightArrow = false;
    }
}

void createObjects() {
    boat = new Boat();
    
    fanAnchor = new Empty();
    fanAnchor->position.y = 1;
    fanAnchor->position.z = -1.25;
    boat->addChild(fanAnchor);
    
    for (int i = 0; i < numBlades; i++) {
        blades[i] = new FanBlade(bladeColors[i]);
        
        blades[i]->rotation.x = 30;
        blades[i]->rotation.z = (360.0 / numBlades) * i;
        
        fanAnchor->addChild(blades[i]);
    }
    
    for (int i = 0; i < numRudders; i++) {
        rudders[i] = new Rudder(rudderColors[i]);
        
        rudders[i]->position.x = -rudderSpacing + (rudderSpacing * i);
        rudders[i]->position.z = -1.5;
        
        boat->addChild(rudders[i]);
    }
    
    water = new Water();
    water->scale = 10;
    
    lookCam = new Camera();
    lookCam->position = Vector3(0, 10, 20);
    lookCam->setTarget(boat);
    
    chaseCam = new Camera();
    chaseCam->position = Vector3(0, 5, -5);
    chaseCam->rotation = Vector3(30, 0, 0);
    
    boat->addChild(chaseCam);
    
    scene = new Scene();
    scene->addGameObject(boat);
    scene->addGameObject(water);
    scene->addGameObject(lookCam);
    scene->setActiveCamera(lookCam);
    scene->init();
}

void init() {
    /*select clearing (background) color*/
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    createObjects();
    
    //Only draw the things in the front layer
	glEnable(GL_DEPTH_TEST);
}

//reshape will be called at least once when the window is created,
//so we can handle projection matrix work here
void reshape(int width, int height){
	ww= width;
	wh = height;
	//field of view angle, aspect ratio, closest distance from camera to object, largest distance from camera to object
    
    //send over projection matrix to vertex shader
    scene->setAspectRatio((float)width, (float)height);
	
	glViewport(0, 0, width, height);
}

void timer(GLint v) {
    if (keyUpArrow) {
        boat->position.x += sin(boat->rotation.y * DEG_TO_RAD) * boatSpeed;
        boat->position.z += cos(boat->rotation.y * DEG_TO_RAD) * boatSpeed;
        fanAnchor->rotation.z += fanSpeed;
    } else if (keyDownArrow) {
        boat->position.x -= sin(boat->rotation.y * DEG_TO_RAD) * boatSpeed;
        boat->position.z -= cos(boat->rotation.y * DEG_TO_RAD) * boatSpeed;
        fanAnchor->rotation.z -= fanSpeed;
    }
    
    boat->position.x = clamp(boat->position.x, -waterScale + 1, waterScale - 1);
    boat->position.z = clamp(boat->position.z, -waterScale + 1, waterScale - 1);
    
    if (keyLeftArrow) {
        boat->rotation.y += boatRotateSpeed;
        for (int i = 0; i < numRudders; i++) {
            rudders[i]->rotation.y = -rudderAngle;
        }
    } else if (keyRightArrow) {
        boat->rotation.y -= boatRotateSpeed;
        for (int i = 0; i < numRudders; i++) {
            rudders[i]->rotation.y = rudderAngle;
        }
    } else {
        for (int i = 0; i < numRudders; i++) {
            rudders[i]->rotation.y = 0;
        }
    }
    
	glutPostRedisplay();
	glutTimerFunc(1000 / v, timer, v);
}

int main(int argc, char **argv)
{
    /*set up window for display*/
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0); 
    glutInitWindowSize(ww, wh);
#ifdef __APPLE__
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_3_2_CORE_PROFILE);
#else
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
#endif
    glutCreateWindow("OpenGL 3.2");

#ifndef __APPLE__
    glewExperimental = GL_TRUE;
    glewInit();
#endif
    
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
//    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(special);
    glutSpecialUpFunc(specialUp);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 60);

    glutMainLoop();
    return 0;
}
