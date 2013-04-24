#include "Car.h"

#define PI 3.1415926535897932384626433832795028841971693993751058209749

// constructor mostenit din Object3D
// tipul este Custom, pentru a apela customDraw()
Car::Car() : Object3D(Custom)
{

	numberOfParts=16;
	step=0.3;

	Angle=0.1;
	AngleDegrees=(Angle*180+0.0)/PI;

	car=new Object3D*[numberOfParts];

	//in ce directie este fata masinii la start
	crtFwdVector=Vector3D(1,0,0);
	//in ce directie este dreapta masinii la start
	crtRightVector=Vector3D(0,0,1);

	//acoperis
	car[0]=new RectanglePrism();
	car[0]->SetScale(new Vector3D(0.6,0.1,2));
	car[0]->SetPosition(new Vector3D(0,1,0));
	car[0]->SetColor(new Vector3D(0.7,0.3,0.5));
	car[0]->SetDiffuseColor(Vector4D(0.5,0.1,0.2,1));
	//podea
	car[1]=new RectanglePrism();
	car[1]->SetScale(new Vector3D(1.6,0.1,2));
	car[1]->SetPosition(new Vector3D(0,-1,0));
	car[1]->SetColor(new Vector3D(0.7,0.3,0.5));
	car[1]->SetDiffuseColor(Vector4D(0.5,0.1,0.2,1));
	//capota
	car[2]=new RectanglePrism();
	car[2]->SetScale(new Vector3D(0.5,0.1,2));
	car[2]->SetPosition(new Vector3D(1.1,0,0));
	car[2]->SetColor(new Vector3D(0.7,0.3,0.5));
	car[2]->SetDiffuseColor(Vector4D(0.5,0.1,0.2,1));
	//portbagaj
	car[3]=new RectanglePrism();
	car[3]->SetScale(new Vector3D(0.5,0.1,2));
	car[3]->SetPosition(new Vector3D(-1.1,0,0));
	car[3]->SetColor(new Vector3D(0.7,0.3,0.5));
	car[3]->SetDiffuseColor(Vector4D(0.5,0.1,0.2,1));
	//parte dorsala
	car[4]=new RectanglePrism();
	car[4]->SetScale(new Vector3D(0.5,0.1,2));
	car[4]->SetRotation(new Vector3D(0,0,90));
	car[4]->SetPosition(new Vector3D(-1.6,-0.5,0));
	car[4]->SetColor(new Vector3D(0.7,0.3,0.5));
	car[4]->SetDiffuseColor(Vector4D(0.5,0.1,0.2,1));
	//parte frontala
	car[5]=new RectanglePrism();
	car[5]->SetScale(new Vector3D(0.5,0.1,2));
	car[5]->SetRotation(new Vector3D(0,0,90));
	car[5]->SetPosition(new Vector3D(1.6,-0.5,0));
	car[5]->SetColor(new Vector3D(0.7,0.3,0.5));
	car[5]->SetDiffuseColor(Vector4D(0.5,0.1,0.2,1));
	//parbriz dorsal
	car[6]=new RectanglePrism();
	car[6]->SetScale(new Vector3D(0.5,0.1,2));
	car[6]->SetRotation(new Vector3D(0,0,90));
	car[6]->SetPosition(new Vector3D(-0.6,0.5,0));
	car[6]->SetDiffuseColor(Vector4D(0.1,0.1,0.3,0.5));
	//parbriz frontal
	car[7]=new RectanglePrism();
	car[7]->SetScale(new Vector3D(0.5,0.1,2));
	car[7]->SetRotation(new Vector3D(0,0,90));
	car[7]->SetPosition(new Vector3D(0.6,0.5,0));	
	car[7]->SetDiffuseColor(Vector4D(0.1,0.1,0.3,0.5));
	//parte laterala dreapta
	car[8]=new RectanglePrism();
	car[8]->SetScale(new Vector3D(1.6,0.1,2));
	car[8]->SetRotation(new Vector3D(90,0,0));
	car[8]->SetPosition(new Vector3D(0,-0.5,0.5));
	car[8]->SetColor(new Vector3D(0.7,0.3,0.5));
	car[8]->SetDiffuseColor(Vector4D(0.5,0.1,0.2,1));
	//partea laterala stanga
	car[9]=new RectanglePrism();
	car[9]->SetScale(new Vector3D(1.6,0.1,2));
	car[9]->SetRotation(new Vector3D(90,0,0));
	car[9]->SetPosition(new Vector3D(0,-0.5,-0.5));
	car[9]->SetColor(new Vector3D(0.7,0.3,0.5));
	car[9]->SetDiffuseColor(Vector4D(0.5,0.1,0.2,1));
	//geam lateral dreapta
	car[10]=new RectanglePrism();
	car[10]->SetScale(new Vector3D(0.6,0.1,2));
	car[10]->SetRotation(new Vector3D(90,0,0));
	car[10]->SetPosition(new Vector3D(0,0.5,0.5));
	car[10]->SetDiffuseColor(Vector4D(0.1,0.1,0.3,0.5));
	//geam lateral stanga
	car[11]=new RectanglePrism();
	car[11]->SetScale(new Vector3D(0.6,0.1,2));
	car[11]->SetRotation(new Vector3D(90,0,0));
	car[11]->SetPosition(new Vector3D(0,0.5,-0.5));
	car[11]->SetDiffuseColor(Vector4D(0.1,0.1,0.3,0.5));
	//roata dreapta fata
	car[12]=new Object3D(Tor);
	car[12]->SetScale(new Vector3D(0.4,0.4,0.4));
	car[12]->SetRotation(new Vector3D(0,0,0));
	car[12]->SetPosition(new Vector3D(1,-1,0.5));
	car[12]->SetColor(new Vector3D(0,0,0));
	car[12]->SetDiffuseColor(Vector4D(0,0,0,1));
	//roata stanga fata
	car[13]=new Object3D(Tor);
	car[13]->SetScale(new Vector3D(0.4,0.4,0.4));
	car[13]->SetRotation(new Vector3D(0,0,0));
	car[13]->SetPosition(new Vector3D(1,-1,-0.5));
	car[13]->SetColor(new Vector3D(0,0,0));
	car[13]->SetDiffuseColor(Vector4D(0,0,0,1));
	//roata dreapta spate
	car[14]=new Object3D(Tor);
	car[14]->SetScale(new Vector3D(0.4,0.4,0.4));
	car[14]->SetRotation(new Vector3D(0,0,0));
	car[14]->SetPosition(new Vector3D(-1,-1,0.5));
	car[14]->SetColor(new Vector3D(0,0,0));
	car[14]->SetDiffuseColor(Vector4D(0,0,0,1));
	//roata stanga spate
	car[15]=new Object3D(Tor);
	car[15]->SetScale(new Vector3D(0.4,0.4,0.4));
	car[15]->SetRotation(new Vector3D(0,0,0));
	car[15]->SetPosition(new Vector3D(-1,-1,-0.5));
	car[15]->SetColor(new Vector3D(0,0,0));
	car[15]->SetDiffuseColor(Vector4D(0,0,0,1));

	//faruri
	faruri=new Light*[4];
	//dreapta fata
	faruri[0]=new Light(Spot);
	faruri[0]->SetScale(new Vector3D(0.15,0.15,0.15));
	faruri[0]->SetPosition(new Vector3D(1.5,-0.7,0.3));
	//faruri[0]->SetLightColor(Vector4D(0.4,0.4,0.4,1));
	faruri[0]->SetLightDirection(Vector3D(1,-0.6,0));
	faruri[0]->SetDiffuseLight(Vector4D(6,6,6,1));
	//stanga fata
	faruri[1]=new Light(Spot);
	faruri[1]->SetScale(new Vector3D(0.15,0.15,0.15));
	faruri[1]->SetPosition(new Vector3D(1.5,-0.7,-0.3));
	//faruri[1]->SetLightColor(Vector4D(0.4,0.4,0.4,1));
	faruri[1]->SetLightDirection(Vector3D(1,-0.6,0));
	faruri[1]->SetDiffuseLight(Vector4D(6,6,6,1));
	//dreapta spate
	faruri[2]=new Light(Spot);
	faruri[2]->SetScale(new Vector3D(0.15,0.15,0.15));
	faruri[2]->SetPosition(new Vector3D(-1.5,-0.7,0.3));
	faruri[2]->SetColor(new Vector3D(1,0,0));
	faruri[2]->SetLightDirection(Vector3D(-1,-0.6,0));
	faruri[2]->SetDiffuseLight(Vector4D(6,6,6,1));
	faruri[2]->SetDiffuseColor(Vector4D(1,0,0,1));
	//stanga spate
	faruri[3]=new Light(Spot);
	faruri[3]->SetScale(new Vector3D(0.15,0.15,0.15));
	faruri[3]->SetPosition(new Vector3D(-1.5,-0.7,-0.3));
	faruri[3]->SetColor(new Vector3D(1,0,0));
	faruri[3]->SetLightDirection(Vector3D(-1,-0.6,0));
	faruri[3]->SetDiffuseLight(Vector4D(6,6,6,1));
	faruri[3]->SetDiffuseColor(Vector4D(1,0,0,1));
}

// functie care plaseaza efectivl umina in scena
void Car::RenderLights()
{
	// daca nu este vizibil, nu-l desenam
	if(!Visible)
	return;

	glPushMatrix();

	// translatie
	glTranslatef( translation.x , translation.y , translation.z );

	// rotatie
	glRotatef( rotation.x , 1.0 , 0.0 , 0.0 );
	glRotatef( rotation.y , 0.0 , 1.0 , 0.0 );
	glRotatef( rotation.z , 0.0 , 0.0 , 1.0 );

	// scalare
	glScalef( scale.x , scale.y , scale.z);

	int i;
	for(i=0;i<4;i++)
		faruri[i]->Render();

	glPopMatrix();
}

void Car::customDraw()
{
	int i;
	//desenare masina
	for(i=0;i<numberOfParts;i++)
		car[i]->Draw();
	for(i=0;i<4;i++)
		faruri[i]->Draw();
}

void Car::MoveCar(int key)
{

	//aflam pozitia curenta a masinii
	Vector3D crtPosition=this->GetPosition();
	//aflam rotatia curenta a masinii
	prevRotation=this->GetRotation();
	//retinem pozitia curenta pentru a putea ulterior reveni daca se intampla sa apara ciocniri
	prevPosition=crtPosition;
	//retinem cum este vectorul de Forward la momentul acesta
	prevFwdVector=crtFwdVector;
	//retinem cum este vectorul de Right la momentul acesta
	prevRightVector=crtRightVector;
	//retinem cum e orientata camera
	prevCamPosition=cam->Position;
	prevCamFwd=cam->ForwardVector;
	prevCamRight=cam->RightVector;
	prevCamUp=cam->UpVector;

	//verificam tipul de mutare si in functie de tasta deplasam ceainicul
	switch(key)
	{
		case GLUT_KEY_UP :			
		{
			//merge cu fata
			//nu se roteste
			//orientarea vectorilor front/right ramane aceeasi
			crtFwdVector=prevFwdVector;
			crtRightVector=prevRightVector;

			//se deplaseaza pe x cu step
			this->SetPosition(new Vector3D(crtPosition.x+step*crtFwdVector.x,crtPosition.y+step*crtFwdVector.y,crtPosition.z+step*crtFwdVector.z));

			//reorientare camera
			UpdateCam();

			UpdateBox();
			break;
		}
		case GLUT_KEY_DOWN : 
		{
			//merge cu spatele;nu se roteste			
			//orientarea vectorilor front/right ramane aceeasi
			crtFwdVector=prevFwdVector;
			crtRightVector=prevRightVector;

			//se deplaseaza pe x cu -step
			this->SetPosition(new Vector3D(crtPosition.x-step*crtFwdVector.x,crtPosition.y-step*crtFwdVector.y,crtPosition.z-step*crtFwdVector.z));

			//reorientare camera
			UpdateCam();

			UpdateBox();
			break;
		}
		case GLUT_KEY_RIGHT : 
		{
		
			//orieentarea vectorior Fwd si Right se schimba in functie de unghiul de rotire
			Vector3D FwdNew = crtFwdVector * cos(Angle) + crtRightVector * sin(Angle);
			Vector3D RightNew = crtRightVector * cos(Angle) - crtFwdVector * sin(Angle);
			crtFwdVector=FwdNew;
			crtRightVector=RightNew;

			//se roteste spre dreapta
			this->SetRotation(new Vector3D(this->GetRotation().x,this->GetRotation().y-AngleDegrees,GetRotation().z));			
			this->SetPosition(new Vector3D(crtPosition.x,crtPosition.y,crtPosition.z));

			//reorientare camera
			UpdateCam();

			//se modifica bounding box-u
			UpdateBox();
			break;
		}
		case GLUT_KEY_LEFT : 
		{
			//orieentarea vectorior Fwd si Right se schimba in functie de unghiul de rotire
			Vector3D FwdNew = crtFwdVector * cos(-Angle) + crtRightVector * sin(-Angle);
			Vector3D RightNew = crtRightVector * cos(-Angle) - crtFwdVector * sin(-Angle);
			crtFwdVector=FwdNew;
			crtRightVector=RightNew;

			//se roteste spre stanga
			this->SetRotation(new Vector3D(GetRotation().x,GetRotation().y+AngleDegrees,GetRotation().z));
			this->SetPosition(new Vector3D(crtPosition.x,crtPosition.y,crtPosition.z));

			//reorientare camera
			UpdateCam();

			//se modifica bounding box-ul
			UpdateBox();

			break;
		}	
	}

	//verificare coliziune cu peretii
	int i;
	for(i=0;i<12;i++)
		if(this->Colision(this->walls[i])==true)
		{
			printf("Coliziune cu peretele %d\n",i);
			crtFwdVector=prevFwdVector;
			crtRightVector=prevRightVector;
			
			this->SetPosition(new Vector3D(prevPosition.x,prevPosition.y,prevPosition.z));
			this->SetRotation(new Vector3D(prevRotation.x,prevRotation.y,prevRotation.z));

			cam->Position=prevCamPosition;
			cam->UpVector=prevCamUp;
			cam->RightVector=prevCamRight;
			cam->ForwardVector=prevCamFwd;

			//update box
			UpdateBox();

			return;
		}

	//verificare coliziune cu obstacole
	for(i=0;i<8;i++)
		if(this->Colision(this->obstacles[i])==true)
		{
			//printf("Coliziune cu peretele %d\n",i);
			crtFwdVector=prevFwdVector;
			crtRightVector=prevRightVector;
			
			this->SetPosition(new Vector3D(prevPosition.x,prevPosition.y,prevPosition.z));
			this->SetRotation(new Vector3D(prevRotation.x,prevRotation.y,prevRotation.z));

			cam->Position=prevCamPosition;
			cam->UpVector=prevCamUp;
			cam->RightVector=prevCamRight;
			cam->ForwardVector=prevCamFwd;

			//update box
			UpdateBox();

			return;
		}
}

void Car::UpdateBox()
{
	//lungimea+latime masinii (dupa setari si scalari)
	float lungimeM=3.2*0.6;
	float latimeM=1.0*0.6;

	//punctele masinii
	Vector3D fataS,spateS,fataD,spateD;

	fataS=crtFwdVector*(lungimeM/2)-crtRightVector*(latimeM/2);
	fataD=crtFwdVector*(lungimeM/2)+crtRightVector*(latimeM/2);
	spateS=-crtFwdVector*(lungimeM/2)-crtRightVector*(latimeM/2);
	spateD=-crtFwdVector*(lungimeM/2)+crtRightVector*(latimeM/2);

	//recalculare bounding box pt masina
	float minx=1000,maxx=-1000,minz=1000,maxz=-1000;

	//aflam punctele extreme pe x si z
	if(fataS.x>maxx)
		maxx=fataS.x;
	if(fataS.z>maxz)
		maxz=fataS.z;
	if(fataS.x<minx)
		minx=fataS.x;
	if(fataS.z<minz)
		minz=fataS.z;

	if(fataD.x>maxx)
		maxx=fataD.x;
	if(fataD.z>maxz)
		maxz=fataD.z;
	if(fataD.x<minx)
		minx=fataD.x;
	if(fataD.z<minz)
		minz=fataD.z;

	if(spateS.x>maxx)
		maxx=spateS.x;
	if(spateS.z>maxz)
		maxz=spateS.z;
	if(spateS.x<minx)
		minx=spateS.x;
	if(spateS.z<minz)
		minz=spateS.z;

	if(spateD.x>maxx)
		maxx=spateD.x;
	if(spateD.z>maxz)
		maxz=spateD.z;
	if(spateD.x<minx)
		minx=spateD.x;
	if(spateD.z<minz)
		minz=spateD.z;

	//printf("Scalarea masinii: %f,%f,%f\nBox pt masina: s-%f j-%f st-%f dr-%f\n\n",this->GetScale().x,this->GetScale().y,this->GetScale().z,maxz,minx,maxx);
	this->SetBox(minz,maxz,minx,maxx);
}

void Car::UpdateCam()
{
			//reorientam camera
			switch(camType)	
			{
				//Nose
				case 2: 
					cam->Position=this->GetPosition()+Vector3D(1*this->crtFwdVector.x,1*this->crtFwdVector.y,1*this->crtFwdVector.z)+Vector3D(0,-0.3,0); 
					cam->ForwardVector=this->crtFwdVector;
					cam->RightVector=this->crtRightVector;
					cam->UpVector=cam->RightVector.CrossProduct(cam->ForwardVector);
					break;
				//Satelite
				case 3: 
					cam->Position=Vector3D(0,30,0);
					cam->ForwardVector=Vector3D(0,-1,0);
					cam->RightVector=this->crtRightVector;
					cam->UpVector=this->crtFwdVector;
					break;
				//Overhead
				case 4: 
					cam->Position=this->GetPosition()+Vector3D(-3.8*this->crtFwdVector.x,-3.8*this->crtFwdVector.y,-3.8*this->crtFwdVector.z)+Vector3D(0,2,0); 
					cam->ForwardVector=this->crtFwdVector+Vector3D(0,-0.3,0);
					cam->RightVector=this->crtRightVector;
					cam->UpVector=cam->RightVector.CrossProduct(cam->ForwardVector);
					break;
			}

}