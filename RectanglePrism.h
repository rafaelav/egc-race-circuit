#ifndef RECTANGLEPRISM_H
#define RECTANGLEPRISM_H

#include <glut.h>
#include "Object3D.h"
#include "Camera.h"

class RectanglePrism : public Object3D
{
public:

	// Construcot
	RectanglePrism();

	// Draw
	void customDraw();

public:
	// Functie pentru a seta lungime paralelipiped
	void SetLungime(GLfloat lungime);
	// Functie pentru a seta latime paralelipiped
	void SetLatime(GLfloat latime);
	// Functie pentru a seta grosime paralelipiped
	void SetGrosime(GLfloat grosime);
	// Seteaza culoare difuza
	void SetDiffuse(Vector4D *color);
	
public:
	// lungime paralelipiped
	GLfloat lungime;
	// latime paralelipiped
	GLfloat latime;
	// grosime paralelipiped
	GLfloat grosime;
	// culoare difuza
	Vector4D diffuse;
	// culoare ambientala
	Vector4D ambient;
	// culoare speculara
	Vector4D specular;
};


#endif
