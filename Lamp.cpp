#include "Lamp.h"

// constructor mostenit din Object3D
// tipul este Lamp
Lamp::Lamp() : Object3D(MyLamp)
{
	lampLight=new Light(Spot);

	lampLight->LightType=Spot;

	this->SetScale(new Vector3D(0.6,0.6,0.6));
	this->SetRotation(new Vector3D(-90,0,0));
	this->lampLight->SetDiffuseLight(Vector4D(1,1,1,1));
	this->lampLight->SetLightDirection(Vector3D(0,-1,0));
	this->SetDiffuseColor(Vector4D(0.1,0.2,0.1,1));
	//this->lampLight->SetLightColor(Vector4D(0.7,0.4,0.1,1));

	//stalp sustinere
	stalp=new RectanglePrism();
	stalp->SetScale(new Vector3D(3,0.2,0.2));
	stalp->SetRotation(new Vector3D(0,0,90));	
	stalp->SetDiffuseColor(Vector4D(0.1,0.2,0.1,1));

}
