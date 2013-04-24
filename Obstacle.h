#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <glut.h>
#include "Object3D.h"
#include "Light.h"
#include "RectanglePrism.h"

#define PASI 10

/*
	Clasa Obstacle:
		defineste un obstacol
*/

// derivata din Object3D
class Obstacle : public Object3D
{

// VARIABILE
//-------------------------------------------------
public:
	ObjectType obstType;	//tip obstacol
	int angle;	//unghiul la care e rotit
	float pas;
	int pasCrt;

//Setteri
//-------------------------------------------------
public:


// FUNCTII
//-------------------------------------------------
public:
	// constructor vid
	Obstacle(ObjectType);
	// functie de animatie
	void MoveRotate(int,int);
	//void MoveTranslate();
};

#endif