//-------------------------------------------------
// EGC
// Laborator 7
//-------------------------------------------------
// W S    - miscare camera fata/spate
// A D    - miscare camera stanga/dreapta (strafe)
// Q E    - rotatie camera stanga/dreapta
//
// [ ]    - selectie obiect stanga/dreapta
// < >    - modificare nivel de detaliu teren
// Sageti - miscare obiecte selectat
//
// ESC    - iesire din program
//-------------------------------------------------


#include <stdlib.h>
#include <glut.h>
#include <stdio.h>
#include <stdarg.h>
#include <Windows.h>

#include "Camera.h"
#include "Object3D.h"
#include "Plane.h"
#include "Light.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "RectanglePrism.h"
#include "Car.h"
#include "Lamp.h"
#include "Obstacle.h"

//unghiuri de rotire
#define ANGLE1 10
#define ANGLE2 15

// tasta escape
#define ESC	27

//tip de camere
#define FREE 1
#define NOSE 2
#define SATELITE 3
#define OVERHEAD 4

float *Vector3D::arr;
float *Vector4D::arr;
// VARIABILE
//-------------------------------------------------
// numarul de obiecte
int objectCount;
// obiectul selectat
int selectedIndex = -1;

// camera
Camera *cameraFree,*cameraNose,*cameraSatelite,*cameraOverhead;
// vector de obiecte 3D
//Object3D *objects;
// planul de baza
Plane *ground;
// o lumina
Light *light;

//bordurile circuitului
RectanglePrism **walls;

//masina
Car *car;
//lampi
Lamp **lamps;
//obstacole
Obstacle **obst;

//numar de borduri folosite
int numberOfWalls;

//numar de parti ale masinii
int numberOfParts;
//nr lampi
int numberOfLamps;
//nr obstacole
int numberOfObstacles;
//tip camera
int cameraType;
// FUNCTII
//-------------------------------------------------

// functie de initializare
void init(void)
{
	int i;
	numberOfWalls=12;
	numberOfParts=16;
	numberOfLamps=3;
	numberOfObstacles=8;
	cameraType=FREE;	//default camera este de tip free-cam

	// initialize vector arrays
	Vector3D::arr = new float[3];
	Vector4D::arr = new float[4];

	// initializam un plan de latura 5.0f
	ground = new Plane(15.0f);
	// culoare
	ground->SetColor(new Vector3D(0.2,0,0.0));
	// setam o grila de 5
	ground->SetLevelOfDetail(5);
	// sub nivelul obiectelor
	ground->SetPosition(new Vector3D(0,-2,0));//0,-2,0
	// si wireframe
	ground->Wireframe = false;

	// bordurile ce formeazza circuitul
	walls = new RectanglePrism*[numberOfWalls];

	//cream circuitul
	//perete 0 (ext)
	walls[0]=new RectanglePrism();
	walls[0]->SetScale(new Vector3D(14,2,1));
	walls[0]->SetPosition(new Vector3D(0,-3.5,14));
	walls[0]->SetBox(-0.25,0.25,-14,14);

	//perete 1	(ext)
	walls[1]=new RectanglePrism();
	walls[1]->SetScale(new Vector3D(14,2,1));
	walls[1]->SetRotation(new Vector3D(0,90,0));
	walls[1]->SetPosition(new Vector3D(-13.75,-3.5,-0.2));
	walls[1]->SetBox(-14,14,-0.25,0.25);

	//perete 2 (ext)
	walls[2]=new RectanglePrism();
	walls[2]->SetScale(new Vector3D(7,2,1));
	walls[2]->SetPosition(new Vector3D(-7,-3.5,-14));
	walls[2]->SetBox(-0.25,0.25,-7,7);
	//perete 3	(ext)
	walls[3]=new RectanglePrism();
	walls[3]->SetScale(new Vector3D(7,2,1));
	walls[3]->SetRotation(new Vector3D(0,90,0));
	walls[3]->SetPosition(new Vector3D(0.25,-3.5,-7.25));
	walls[3]->SetBox(-7,7,-0.25,0.25);
	//perete 4 (ext)
	walls[4]=new RectanglePrism();
	walls[4]->SetScale(new Vector3D(7,2,1));
	walls[4]->SetPosition(new Vector3D(7,-3.5,0));
	walls[4]->SetBox(-0.25,0.25,-7,7);
	//perete 5	(ext)
	walls[5]=new RectanglePrism();
	walls[5]->SetScale(new Vector3D(7,2,1));
	walls[5]->SetRotation(new Vector3D(0,90,0));
	walls[5]->SetPosition(new Vector3D(13.75,-3.5,7));
	walls[5]->SetBox(-7,7,-0.25,0.25);
	//perete 6 (int)
	walls[6]=new RectanglePrism();
	walls[6]->SetScale(new Vector3D(8,2,1));
	walls[6]->SetPosition(new Vector3D(0,-3.5,8.7));
	walls[6]->SetBox(-0.25,0.25,-8,8);
	//perete 7	(int)
	walls[7]=new RectanglePrism();
	walls[7]->SetScale(new Vector3D(8,2,1));
	walls[7]->SetRotation(new Vector3D(0,90,0));
	walls[7]->SetPosition(new Vector3D(-7.75,-3.5,0.45));
	walls[7]->SetBox(-8,8,-0.25,0.25);
	//perete 8 (int)
	walls[8]=new RectanglePrism();
	walls[8]->SetScale(new Vector3D(1.2,2,1));
	walls[8]->SetPosition(new Vector3D(-6.80,-3.5,-7.8));
	walls[8]->SetBox(-0.25,0.25,-1.2,1.2);
	//perete 9	(int)
	walls[9]=new RectanglePrism();
	walls[9]->SetScale(new Vector3D(7,2,1));
	walls[9]->SetRotation(new Vector3D(0,90,0));
	walls[9]->SetPosition(new Vector3D(-5.85,-3.5,-0.55));
	walls[9]->SetBox(-7,7,-0.25,0.25);
	//perete 10 (int)
	walls[10]=new RectanglePrism();
	walls[10]->SetScale(new Vector3D(6.6,2,1));
	walls[10]->SetPosition(new Vector3D(0.9,-3.5,6.2));
	walls[10]->SetBox(-0.25,0.25,-6.6,6.6);
	//perete 11	(int)
	walls[11]=new RectanglePrism();
	walls[11]->SetScale(new Vector3D(1.25,2,1));
	walls[11]->SetRotation(new Vector3D(0,90,0));
	walls[11]->SetPosition(new Vector3D(7.75,-3.5,7.2));
	walls[11]->SetBox(-1.25,1.25,-0.25,0.25);

	for(i=0;i<numberOfWalls;i++)
	{
		walls[i]->SetColor(new Vector3D(0.1,0.2,0.3));
		walls[i]->SetDiffuseColor(Vector4D(0.1,0.2,0.3,1));
	}

	//masina
	car=new Car();
	car->SetScale(new Vector3D(0.6,0.6,0.6));
	car->SetPosition(new Vector3D(0,-3.05,1.5));
	car->SetBox(-0.3,0.3,-0.3*3,0.3*3);	//bounding box initial pt masina (are pe x lungimea totala 3 iar pe z latimea totala 1 => 0.6*3/2 respectiv 1*0,6/2)	

	//lampi
	lamps=new Lamp*[numberOfLamps];
	lamps[0]=new Lamp();
	lamps[0]->SetPosition(new Vector3D(2,2,0));	
	lamps[0]->lampLight->SetPosition(new Vector3D(2,2,0));
	lamps[0]->stalp->SetPosition(new Vector3D(2,0,0));
	
	lamps[1]=new Lamp();
	lamps[1]->SetPosition(new Vector3D(3,2,8.7));
	lamps[1]->lampLight->SetPosition(new Vector3D(3,2,8.7));
	lamps[1]->stalp->SetPosition(new Vector3D(3,0,8.7));	

	lamps[2]=new Lamp();
	lamps[2]->SetPosition(new Vector3D(-7.7,2,-7.7));
	lamps[2]->lampLight->SetPosition(new Vector3D(-7.7,2,-7.7));
	lamps[2]->stalp->SetPosition(new Vector3D(-7.7,0,-7.7));

	//obstacole
	obst=new Obstacle*[numberOfObstacles];
	//1 - cub - translatie (pe z)
	obst[0]=new Obstacle(Cube);
	obst[0]->SetPosition(new Vector3D(3,-3.5,3));
	obst[0]->SetBox(-0.45,0.45,-0.45,0.45);
	//2 - sfera
	obst[1]=new Obstacle(Sphere);
	obst[1]->SetPosition(new Vector3D(3,-3,12.5));
	obst[1]->SetBox(-0.8,0.8,-0.8,0.8);
	//3 - tetraedru - translatie (pe y)
	obst[2]=new Obstacle(Piramida);
	obst[2]->SetDiffuseColor(Vector4D(0.1,0.3,0.1,1));
	obst[2]->SetPosition(new Vector3D(10,-3.5,7));
	obst[2]->SetBox(-0.68,0.68,-0.68,0.68);
	//4 - Cub - transparent
	obst[3]=new Obstacle(Cube);
	obst[3]->SetDiffuseColor(Vector4D(0.1,0.3,0.1,1));
	obst[3]->SetPosition(new Vector3D(-10,-3.5,10));
	obst[3]->SetBox(-0.45,0.45,-0.45,0.45);
	//5 - sfera - transparenta
	obst[4]=new Obstacle(Sphere);
	obst[4]->SetDiffuseColor(Vector4D(0.6,0.1,0.1,0.7));
	obst[4]->SetPosition(new Vector3D(-12,-3,3));
	obst[4]->SetBox(-0.8,0.8,-0.8,0.8);
	//6 - tetraedru
	obst[5]=new Obstacle(Piramida);
	obst[5]->SetPosition(new Vector3D(-10,-3.5,-2));
	obst[5]->SetBox(-0.68,0.68,-0.68,0.68);
	//7 - Cub
	obst[6]=new Obstacle(Cube);
	obst[6]->SetDiffuseColor(Vector4D(0.1,0.3,0.1,1));
	obst[6]->SetPosition(new Vector3D(-7,-3.5,-12));
	obst[6]->SetBox(-0.45,0.45,-0.45,0.45);
	//8 - sfera
	obst[7]=new Obstacle(Sphere);
	obst[7]->SetDiffuseColor(Vector4D(0.6,0.1,0.1,0.7));
	obst[7]->SetPosition(new Vector3D(-1,-3,-2));
	obst[7]->SetBox(-0.8,0.8,-0.8,0.8);
	
	//retinem in Car referintele pt obstacole si pentru pereti
	car->walls=walls;
	car->obstacles=obst;

	// initializam camere
	//free
	cameraFree = new Camera();
	cameraFree->ForwardVector=Vector3D(0,-1,0);
	cameraFree->RightVector=Vector3D(1,0,0);
	cameraFree->UpVector=Vector3D(0,0,-1);
	cameraFree->Position=Vector3D(0,28,0);
	//satelite (sus)
	cameraSatelite=new Camera();
	cameraSatelite->Position=Vector3D(0,30,0);
	cameraSatelite->ForwardVector=Vector3D(0,-1,0);
	cameraSatelite->RightVector=car->crtRightVector;
	cameraSatelite->UpVector=car->crtFwdVector;
	//nose (fata masinii)
	cameraNose=new Camera();
	cameraNose->Position=car->GetPosition()+Vector3D(1*car->crtFwdVector.x,1*car->crtFwdVector.y,1*car->crtFwdVector.z)+Vector3D(0,-0.3,0);
	cameraNose->ForwardVector=car->crtFwdVector;
	cameraNose->RightVector=car->crtRightVector;
	cameraNose->UpVector=cameraNose->RightVector.CrossProduct(cameraNose->ForwardVector);
	//overhead (spate masinii)
	cameraOverhead=new Camera();
	cameraOverhead->Position=car->GetPosition()+Vector3D(-3.8*car->crtFwdVector.x,-3.8*car->crtFwdVector.y,-3.8*car->crtFwdVector.z)+Vector3D(0,2,0);
	cameraOverhead->ForwardVector=car->crtFwdVector+Vector3D(0,-0.3,0);
	cameraOverhead->RightVector=car->crtRightVector;
	cameraOverhead->UpVector=cameraOverhead->RightVector.CrossProduct(cameraOverhead->ForwardVector);

	//la initializare camera este FREE
	car->camType=FREE;
	car->cam=cameraFree;

	// initializam o noua lumina
	light = new Light(Ideal);
	// setam pozitia
	light->SetPosition(new Vector3D(-2,31, 3));

	// pregatim o scena noua in opengl
	glClearColor(0.0, 0.0, 0.0, 0.0);	// stergem tot
	glEnable(GL_DEPTH_TEST);			// activam verificarea distantei fata de camera (a adancimii)
	glShadeModel(GL_SMOOTH);			// mod de desenare SMOOTH
	glEnable(GL_LIGHTING);				// activam iluminarea
	GLfloat lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);	//lumina ambientala
	glEnable(GL_NORMALIZE);				// activam normalizarea normalelor
	glEnable(GL_ALPHA_TEST);
}


// functie de desenare a scenei 3D
void drawScene(void)
{
	int i;
	// stergere ecran
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// plasare observator
	switch(cameraType)
	{
	case FREE: cameraFree->Render(); break;
	case NOSE: cameraNose->Render(); break;
	case SATELITE: cameraSatelite->Render(); break;
	case OVERHEAD: cameraOverhead->Render(); break;
	}

	
	// activare lumina

	light->Render();

	car->RenderLights();

	for(i=0;i<numberOfLamps;i++)
		lamps[i]->lampLight->Render();

	//desenare borduri
	for(i=0;i<numberOfWalls;i++)
		walls[i]->Draw();

	//desenare masina
	car->Draw();

	//desenare lampi
	for(i=0;i<numberOfLamps;i++)
	{
		lamps[i]->Draw();
		lamps[i]->stalp->Draw();
	}

	//desenare obstacole
	for(i=0;i<numberOfObstacles;i++)
	{
		obst[i]->Draw();
	}

	// desenare plan
	ground->Draw();
	// desenare lumina (deseneaza o sfera acolo unde se afla lumina, nu face nimic altceva)
	light->Draw();

	// dezactivare lumina
	light->Disable();

	//dezactivare lampi
	for(i=0;i<numberOfLamps;i++)
		lamps[i]->lampLight->Disable();

	// double buffering
	//glutSwapBuffers();
	// redeseneaza scena
	//glutPostRedisplay();
}

// functie de desenare (se apeleaza cat de repede poate placa video)
// se va folosi aceeasi functie de display pentru toate subferestrele ( se puteau folosi si functii distincte 
// pentru fiecare subfereastra )
void display(void)
{
	// stergere ecran
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glAlphaFunc(GL_GREATER,0.9f);

	// Render Pass - deseneaza scena
	drawScene();

	glEnable(GL_BLEND);
	//glDisable(GL_DEPTH_TEST);
	//afisare obiecte transparente
	glAlphaFunc(GL_LEQUAL,0.9f);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	drawScene();

	glDisable(GL_BLEND);
	//glEnable(GL_DEPTH_TEST);
	// double buffering
	glutSwapBuffers();

	// redeseneaza scena
	glutPostRedisplay();
		
}


// functie de update (se apeleaza constant, independent de Draw() )
void update(void)
{
	Sleep(2);
	obst[3]->MoveRotate(ANGLE1,1);
	obst[2]->MoveRotate(ANGLE2,0);
	// redeseneaza scena
	glutPostRedisplay();
}

// functie de proiectie
void reshape(int w, int h)
{
	// viewport de dimensiuni date
	glViewport(0,0, (GLsizei) w, (GLsizei) h);
	// calculare aspect ratio ( Width/ Height )
	GLfloat aspect = (GLfloat) w / (GLfloat) h;

	// intram in modul proiectie
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// incarcam matrice de perspectiva 
	gluPerspective(45, aspect, 1.0, 60);
}

// handler pentru tastatura
void keyboard(unsigned char key , int x, int y)
{
	switch (key)
	{
	case ESC : exit(0);
		// cu < si > se modifica nivelul de detaliu al terenului
	//case ',' : ground->SetLevelOfDetail(ground->GetLevelOfDetail()*2); break;
	//case '.' : ground->SetLevelOfDetail(ground->GetLevelOfDetail()/2); break;
	case '[':
		cameraType=NOSE; car->camType=NOSE; car->cam=cameraNose; car->UpdateCam(); break;
	case ']':
		cameraType=OVERHEAD; car->camType=OVERHEAD; car->cam=cameraOverhead; car->UpdateCam(); break;
	case '\'':
		cameraType=SATELITE; car->camType=SATELITE; car->cam=cameraSatelite; car->UpdateCam(); break;
	case '\\':
		cameraType=FREE; car->camType=FREE; car->cam=cameraFree; car->UpdateCam(); break;
	//daca tipul camerei este FREE
	case 'w' : case 'W' : 
		if(cameraType==FREE)
		cameraFree->MoveForward(0.1); break;
	case 's' : case 'S' : 
		if(cameraType==FREE)
		cameraFree->MoveBackward(0.1); break;
	case 'a' : case 'A' : 
		if(cameraType==FREE)
		cameraFree->MoveLeft(0.1); break;
	case 'd' : case 'D' : 
		if(cameraType==FREE)
		cameraFree->MoveRight(0.1); break;
	case 'q' : case 'Q' :
		if(cameraType==FREE)
		cameraFree->RotateYCenter(-0.1); break;
	case 'e' : case 'E' :
		if(cameraType==FREE)
		cameraFree->RotateYCenter(0.1); break;
	case 'z' : case 'Z' :
		if(cameraType==FREE)
		cameraFree->RotateXCenter(-0.1); break;
	case 'c' : case 'C' :
		if(cameraType==FREE)
		cameraFree->RotateXCenter(0.1); break;
	case 'r' : case 'R' :
		if(cameraType==FREE)
		cameraFree->RotateZCenter(-0.1); break;
	case 'y' : case 'Y' :
		if(cameraType==FREE)
		cameraFree->RotateZCenter(0.1); break;
	case '8':
		if(cameraType==FREE)
		cameraFree->MoveUpward(0.1); break;
	case '2':
		if(cameraType==FREE)
		cameraFree->MoveDownward(0.1); break;
	case '9':
		if(cameraType==FREE)
		cameraFree->RotateY(-0.1); break;
	case '7':
		if(cameraType==FREE)
		cameraFree->RotateY(0.1); break;
	case '3':
		if(cameraType==FREE)
		cameraFree->RotateX(-0.1); break;
	case '1':
		if(cameraType==FREE)
		cameraFree->RotateX(0.1); break;
	case '4':
		if(cameraType==FREE)
		cameraFree->RotateZ(-0.1); break;
	case '6':
		if(cameraType==FREE)
		cameraFree->RotateZ(0.1); break;
	default: break;
	}
}

// handler taste speciale
void keyboard(int key , int x, int y)
{

	car->MoveCar(key);
}

void mouse(int buton, int stare, int x, int y)
{
	switch(buton)
	{
	case GLUT_LEFT_BUTTON:
		break;
	case GLUT_RIGHT_BUTTON:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("NFS");
	init();
	glutIdleFunc(update);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}