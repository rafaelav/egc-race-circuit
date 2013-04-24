// EGC
// Laborator 7
//-------------------------------------------------

#include "camera.h"
#include "math.h"


// constructor
Camera::Camera()
{
	//initializare cu valorile standard OpenGL
	Position = Vector3D (0.0, 0.0,	12);
	ForwardVector = Vector3D( 0.0, 0.0, -1.0);
	RightVector = Vector3D (1.0, 0.0, 0.0);
	UpVector = Vector3D (0.0, 1.0, 0.0);
}

void Camera::RotateX (GLfloat Angle)
{
	Vector3D FwdNew = ForwardVector * cos(Angle) + UpVector * sin(Angle);
	Vector3D UpNew = UpVector * cos(Angle) - ForwardVector * sin(Angle);
	//UpNew =  -FwdNew.CrossProduct(RightVector);

	ForwardVector=FwdNew;
	UpVector=UpNew;
}

void Camera::RotateY (GLfloat Angle)
{
	Vector3D FwdNew = ForwardVector * cos(Angle) + RightVector * sin(Angle);
	Vector3D RightNew = RightVector * cos(Angle) - ForwardVector * sin(Angle);
	//RightNew = - FwdNew.CrossProduct(UpVector);

	ForwardVector=FwdNew;
	RightVector=RightNew;
}

void Camera::RotateZ (GLfloat Angle)
{
	Vector3D RightNew = RightVector * cos(Angle) + UpVector * sin(Angle);
	Vector3D UpNew = UpVector * cos(Angle) - RightVector * sin(Angle);
	//UpNew = -ForwardVector.CrossProduct(RightNew);

	RightVector=RightNew;
	UpVector=UpNew;
}

// rotire fata de centru, la o distanta generica 5
void Camera::RotateXCenter (GLfloat Angle)
{
	float distance = 10;
	MoveForward(distance);
	RotateX(Angle);
	MoveBackward(distance);
}

// rotire fata de centru, la o distanta generica 5
void Camera::RotateYCenter (GLfloat Angle)
{
	float distance = 10;
	MoveForward(distance);
	RotateY(Angle);
	MoveBackward(distance);
}

// rotire fata de centru, la o distanta generica 5
void Camera::RotateZCenter (GLfloat Angle)
{
	float distance = 10;
	MoveForward(distance);
	RotateZ(Angle);
	//UpVector=-UpVector;
	MoveBackward(distance);
}

// plasare observator in scena
void Camera::Render( void )
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// punctul catre care se uita camera
	Vector3D ViewPoint = Position + ForwardVector;

	// stim vectorul UpVector, folosim LookAt
	gluLookAt(	Position.x,Position.y,Position.z,
				ViewPoint.x,ViewPoint.y,ViewPoint.z,
				UpVector.x,UpVector.y,UpVector.z);
}

// miscari simple, pe toate axele

void Camera::MoveForward( GLfloat Distance )
{
	Vector3D addition(0,0,-Distance);

	Position=Position+ForwardVector*Distance;
}

void Camera::MoveBackward( GLfloat Distance )
{
	Vector3D addition(0,0,Distance);

	Position=Position-ForwardVector*Distance;

	//RightVector = ForwardVector.CrossProduct(UpVector);
}

void Camera::MoveRight ( GLfloat Distance )
{
	//printf("right\n");
	Vector3D addition(Distance,0,0);

	Position=Position+RightVector*Distance;
	//ForwardVector=ViewPoint+addition;
}

void Camera::MoveLeft ( GLfloat Distance )
{
	Vector3D addition(-Distance,0,0);

	Position=Position-RightVector*Distance;
}

void Camera::MoveUpward( GLfloat Distance )
{	
	Vector3D addition(0,Distance,0);

	Position=Position+UpVector*Distance;
}

void Camera::MoveDownward( GLfloat Distance )
{
	Vector3D addition(0,-Distance,0);

	Position=Position-UpVector*Distance;
}

/*void Camera::SetUpVector(Vector3D u)
{
	UpVector=u;
}

void Camera::SetRightVector(Vector3D r)
{
	RightVector=r;
}

void Camera::SetForwardVector(Vector3D f)
{
	ForwardVector=f;
}*/

