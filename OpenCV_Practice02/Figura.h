#pragma once
#include <opencv/cvaux.h>
#include <opencv/highgui.h> // Permite abrir las ventanas
#include <opencv/cxcore.h>
#include <iostream>
using namespace std;
using namespace cv;
#if !defined _FIGURA_H 
#define _FIGURA_H
class Figura
{
private:
	bool modificado[3];
	Point centro[3]; // 0 circulo, 1 rectangulo, 2 triangulo
public:
	Figura(void);

	void dibujaFiguras(Mat img, Point centro, bool imgActive[4]);
	void modificaCirculo(Point centro);
	void modificaRectangulo(Point centro);
	void modificaTriangulo(Point centro);
	void reiniciar();

	~Figura(void);
};
#endif

