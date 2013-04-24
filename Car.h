#ifndef CAR_H
#define CAR_H

#include <glut.h>
#include "Object3D.h"
#include "RectanglePrism.h"
#include "Light.h"
#include "Obstacle.h"
#include "Camera.h"

/*
	Clasa Car
	deseneaza o masina
*/

// derivata din Object3D
class Car : public Object3D
{

// VARIABILE
//-------------------------------------------------
public:
	//numarul elementelor ce intra in componenta masinii
	int numberOfParts;
	//masina
	Object3D **car;
	Light **faruri;
	Vector3D prevPosition;
	Vector3D prevRotation;
	Vector3D prevFwdVector;
	Vector3D prevRightVector;
	Vector3D prevCamPosition;
	Vector3D prevCamFwd;
	Vector3D prevCamRight;
	Vector3D prevCamUp;
	Vector3D crtFwdVector;
	Vector3D crtRightVector;
	float step;	//pas de deplasare
	float Angle;	//unghi de intoarcere (radiani)
	float AngleDegrees;	//unghi de intoarcere in grade 
	RectanglePrism **walls;
	Obstacle **obstacles;
	Camera *cam;
	int camType;
// FUNCTII
//-------------------------------------------------
public:
	// constructor fara parametri
	Car();
	// functia custmDraw care va fi apelata de Object3D pentru a desena planul
	void customDraw();
	void RenderLights();
	void MoveCar(int);
	void UpdateBox();
	void UpdateCam();
};

#endif