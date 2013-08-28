// OpenCV_Practice02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Figura.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Figura prueba;
	Mat imgCamara;
	Mat img = Mat::ones(480, 680, CV_8UC3);
	bool imgActive[4] = {0,1,1,1};
	int opcionM;
	int xT, yT;
	char l;
	//prueba.prueba(img);
	//cvNamedWindow("Ventana_1", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Ventana", CV_WINDOW_AUTOSIZE);
	//cvShowImage("Ventana",img); <- SOLO SE PUEDE USAR PARA IPLIMG
	//imread para cargar una imagen
	//imshow("Ventana_1", img);


	VideoCapture cap = VideoCapture(0);
	cout << "-\tPara salir del programa presione esc sobre la imagen\n-\tPara activar o desactivar figuras presione (A)ctivar\n-\tSi desea cambiar manualmente la posicion de alguna figura presione F1 y regrese a la consola" << endl;
	if(!cap.isOpened())
		cout << "\tHa habido un error en la lectura de la imagen" << endl;
	else{
		while(true){
			cap >> imgCamara;
			l = cvWaitKey(30);
			if(imgCamara.empty() || (char)l == 27)
				break;
			else if((char)l == 'a'){
				imgActive[0] = imgActive[0]==true?false:true;
				cout << "\tFiguras geometricas basicas puestas en imagen.\n\t-Para eliminar o volver a poner alguna presione (C)irculo, (R)ectangulo, (T)riangulo sobre la imagen" << endl;
				l = ' ';
			}else if(imgActive[0] &&  (char)(tolower(l)) == 'c')
				imgActive[1] = imgActive[1]==true?false:true;
			else if(imgActive[0] &&  (char)(tolower(l)) == 'r')
				imgActive[2] = imgActive[2]==true?false:true;
			else if(imgActive[0] &&  (char)(tolower(l)) == 't')
				imgActive[3] = imgActive[3]==true?false:true;
			else if((char)l == ' ' ){ //Presionar F1 //TODO: HACERLO EN LA MISMA IMAGEN JEJE <3
				
				
				do{
					do{
						cout << "\n-\tMientras modifica la posición se congelara la imagen" << endl
								<< "-\tPosición a modificar: " << endl
								<< "-1\tCirculo" << endl
								<< "-2\tRectangulo" << endl
								<< "-3\tTriangulo" << endl
								<< "-4\tReiniciar" << endl
								<< "-5\tregresar" << endl
								<< "\n\tOpcion: ";
						cin >> opcionM;
					}while(!(opcionM>0&&opcionM<6));
					if(opcionM != 4 && opcionM != 5){
						cout << "\n\n-\tIndique x en pixeles: ";
						cin >> xT;
						cout << "\n-\tIndique y en pixeles: ";
						cin >> yT;
					}
					
					switch(opcionM){
					case 1: prueba.modificaCirculo(Point(xT,yT));
							break;
					case 2: prueba.modificaRectangulo(Point(xT,yT));
							break;
					case 3: prueba.modificaTriangulo(Point(xT,yT));
							break;
					case 4: prueba.reiniciar();
							break;
					}
					
					cout << "\n\n-\tGuardando cambios..." << endl;
				}while(opcionM!=5);
				opcionM = -1;

			}else{
				prueba.dibujaFiguras(imgCamara, Point(imgCamara.cols/2,imgCamara.rows/2), imgActive);
				imshow("Ventana",imgCamara);
			}
		
		}	
	}   
	

	/*PARA GRABAR CAPTURAS EN VIDEO
		int fps     = 20;  // or 30
	int frameW  = 640; 
	int frameH  = 480; 

 
	// opens the file and initializes the video writer.
    	// 	filename - the output file name.
    	// 	fourcc - the codec
    	// 	fps - the number of frames per second
    	// 	frameSize - the video frame size
    	// 	isColor - specifies whether the video stream is color or grayscale (true)
 
	VideoWriter ov = VideoWriter( "video.avi", 
                                      CV_FOURCC('M','P','E','G'), 
                                      fps, 
                                      Size(frameW,frameH));
	*/


	return 0;
}

