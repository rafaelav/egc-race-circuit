#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <glut.h>
#include "Object3D.h"
#include "RectanglePrism.h"

/*
	Clasa Circuit
	deseneaza circuitul
*/

// derivata din Object3D
class Circuit : public Object3D
{

// VARIABILE
//-------------------------------------------------
public:
	//numarul elementelor ce intra in componenta masinii
	//int numberOfParts;
	//masina
	Object3D **car;

// FUNCTII
//-------------------------------------------------
public:
	// constructor fara parametri
	//Car();
	// functia custmDraw care va fi apelata de Object3D pentru a desena planul
	void customDraw();
};

#endif