#include "Obstacle.h"

// constructor mostenit din Object3D
Obstacle::Obstacle(ObjectType t) : Object3D(obstType)
{
	//lampLight->LightType=Spot;
	this->Type=t;	//tipul de obstacol
	this->SetScale(new Vector3D(0.9,0.9,0.9));	//scalarea sa
	this->SetDiffuseColor(Vector4D(0.3,0.1,0.4,1));	//culoarea

	this->angle=0;	//unghi initial e 0

	this->pas=0.05;	//pas de translatie
	this->pasCrt=0;	//pasul 0
}

void Obstacle::MoveRotate(int a,int axa)
{
	int unghi=angle+a;
	angle=unghi%360;	//retinem noul unghi la care va fi rotit
	if(axa==0)	//x
		this->SetRotation(new Vector3D(angle,0,0));	//rotim
	else
		if(axa==1)	//y
			this->SetRotation(new Vector3D(0,angle,0));	//rotim
}

/*void Obstacle::MoveTranslate()
{
	if(pasCrt<PASI)
	{
		pasCrt++;
		this->translation=Vector3D(0,pas,0);
	}
	else
	{
		pasCrt=0;
		pas=0-pas;	//merge inapoi
	}
}*/