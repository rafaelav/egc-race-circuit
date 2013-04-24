// EGC
// Laborator 7
//-------------------------------------------------

#include "RectanglePrism.h"

// constructor care primeste ca parametru latura cubului
RectanglePrism::RectanglePrism() : Object3D(Custom)
{
	// valori default
	diffuse = Vector4D(1,1,1,1);
	ambient = Vector4D(0,0,0,0);
	specular = Vector4D(1,1,1,1);
	color = Vector3D(1,1,1);
	scale = Vector3D(1.0,1.0,1.0);
	
	// default , nu este wireframe
	Wireframe = false;

	lungime = 2.0;
	latime = 0.5;
	grosime = 0.5;

}

// functie care seteaza lungime paralelipiped
void RectanglePrism::SetLungime(GLfloat _lungime)
{
	lungime = _lungime;
}

// functie care seteaza latime paralelipiped
void RectanglePrism::SetLatime(GLfloat _latime)
{
	latime = _latime;
}

// functie care seteaza grosimea paralelipiped
void RectanglePrism::SetGrosime(GLfloat _grosime)
{
	grosime = _grosime;
}

// Seteaza culoare difuza ( atentie , la testul alfa se foloseste componenta A din culoarea difuza !!!_
void RectanglePrism::SetDiffuse(Vector4D *color)
{
	diffuse = *color;
}

// DRAW
// Suprascriem prin polimorfism functia de desenare a clasei parinte 
// pentru a avea propria functie de desenare
//-------------------------------------------------
void RectanglePrism::customDraw ()
{
	

	// daca este wireframe
	if( Wireframe )
	{
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	}
	// daca nu este wireframe
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	}

	// desenare quaduri care alcatuiesc cubul

	glBegin(GL_QUADS);

	// Back face
	glNormal3f(0.0,0.0,-1.0);
	glVertex3f( lungime/2,  latime/2, -grosime/2);

	glNormal3f(0.0,0.0,-1.0);
	glVertex3f( -lungime/2, latime/2, -grosime/2);

	glNormal3f(0.0,0.0,-1.0);
	glVertex3f( -lungime/2,  -latime/2, -grosime/2);

	glNormal3f(0.0,0.0,-1.0);
	glVertex3f( lungime/2,  -latime/2, -grosime/2);

	// Front face
	glNormal3f(0.0,0.0,1.0);
	glVertex3f( lungime/2,  latime/2, grosime/2);

	glNormal3f(0.0,0.0,1.0);
	glVertex3f( -lungime/2,  latime/2, grosime/2);

	glNormal3f(0.0,0.0,1.0);
	glVertex3f( -lungime/2,  -latime/2, grosime/2);

	glNormal3f(0.0,0.0,1.0);
	glVertex3f( lungime/2,  -latime/2, grosime/2);

	// left face
	glNormal3f(-1.0,0.0,0.0);
	glVertex3f( -lungime/2,  latime/2, -grosime/2);

	glNormal3f(-1.0,0.0,0.0);
	glVertex3f( -lungime/2,  latime/2, grosime/2);

	glNormal3f(-1.0,0.0,0.0);
	glVertex3f( -lungime/2,  -latime/2, grosime/2);

	glNormal3f(-1.0,0.0,0.0);
	glVertex3f( -lungime/2,  -latime/2, -grosime/2);

	// right face
	glNormal3f(1.0,0.0,0.0);
	glVertex3f( lungime/2,  latime/2, -grosime/2);

	glNormal3f(1.0,0.0,0.0);
	glVertex3f( lungime/2,  latime/2, grosime/2);

	glNormal3f(1.0,0.0,0.0);
	glVertex3f( lungime/2,  -latime/2, grosime/2);

	glNormal3f(1.0,0.0,0.0);
	glVertex3f( lungime/2,  -latime/2, -grosime/2);

	// top face
	glNormal3f(0.0,1.0,0.0);
	glVertex3f( lungime/2,  latime/2, -grosime/2);

	glNormal3f(0.0,1.0,0.0);
	glVertex3f( -lungime/2,  latime/2, -grosime/2);

	glNormal3f(0.0,1.0,0.0);
	glVertex3f( -lungime/2,  latime/2, grosime/2);

	glNormal3f(0.0,1.0,0.0);
	glVertex3f( lungime/2,  latime/2, grosime/2);

	// bottom face
	glNormal3f(0.0,-1.0,0.0);
	glVertex3f( lungime/2,  -latime/2, -grosime/2);

	glNormal3f(0.0,-1.0,0.0);
	glVertex3f( -lungime/2,  -latime/2, -grosime/2);

	glNormal3f(0.0,-1.0,0.0);
	glVertex3f( -lungime/2,  -latime/2, grosime/2);

	glNormal3f(0.0,-1.0,0.0);
	glVertex3f( lungime/2,  -latime/2, grosime/2);


	glEnd();

}