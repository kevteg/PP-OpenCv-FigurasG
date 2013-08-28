#include "Figura.h"


Figura::Figura(void)
{
	modificado[0] = false;
	modificado[1] = false;
	modificado[2] = false;
}


Figura::~Figura(void)
{
}

void Figura::dibujaFiguras(Mat img, Point centro, bool imgActive[4]){
	//Point Points[1][3];
	//int NPT[] = {3};

	if(!modificado[0])
		this->centro[0] = centro;
	if(!modificado[1])
		this->centro[1] = centro;
	if(!modificado[2])
		this->centro[2] = centro;

	int circleRadious = 100;
	if(imgActive[0]){
		//line(img, Point(0, 50), Point(400,50), Scalar(255,255,255), 5, 8); 
		//ellipse(img,Point(200,250),Size(100,200),90,0,360,Scalar(0,255,0),-1,8);
		if(imgActive[1])
		    circle(img,Point(this->centro[0].x - circleRadious*2 - 16, this->centro[0].y),circleRadious,Scalar(255,0,0),8,8);
		if(imgActive[2])
			rectangle(img,Point(this->centro[1].x - 100, this->centro[1].y - 100),Point(this->centro[1].x + 100, this->centro[1].y + 100),Scalar(0,255,0), 8,8);
		//Triangulo vacio
		if(imgActive[3]){
			line(img, Point(this->centro[2].x + 100 + 16, this->centro[2].y + 100), Point(this->centro[2].x + 300 + 16, this->centro[2].y + 100), Scalar(0,0,255), 5, 8); 
			line(img, Point(this->centro[2].x + 100 + 16, this->centro[2].y + 100), Point(this->centro[2].x + 100 + 100 + 16, this->centro[2].y - 100), Scalar(0,0,255), 5, 8); 
			line(img, Point(this->centro[2].x + 300 + 16, this->centro[2].y + 100), Point(this->centro[2].x + 100 + 100 + 16, this->centro[2].y - 100), Scalar(0,0,255), 5, 8); 
		}
	}

	/*Triangulo relleno
	Points[0][0] = Point(centro.x + 100 + 16, centro.y + 100);
	Points[0][1] = Point(centro.x + 300 + 16, centro.y + 100);
	Points[0][2] = Point(centro.x + 200, centro.y - 100);


	const Point* ppt[] = {Points[0]};

	fillPoly(img,ppt,NPT,1,Scalar(0,255,255),8);*/
}
void Figura::modificaCirculo(Point centro){
	modificado[0] = true;
	this->centro[0] = centro;
}
void Figura::modificaRectangulo(Point centro){
	modificado[1] = true;
	this->centro[1] = centro;
}
void Figura::modificaTriangulo(Point centro){
	modificado[2] = true;
	this->centro[2] = centro;
}

void Figura::reiniciar(){
	modificado[0] = false;
	modificado[1] = false;
	modificado[2] = false;
}
