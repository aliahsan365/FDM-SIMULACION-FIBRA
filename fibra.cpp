#include <iostream>
#include <algorithm>
#include <cmath>
#include <time.h> 
#include <stdlib.h>

using namespace std;

#define PI 3.14159265






double velocidad_medio(double indice_medio);
double centro_fibra(double r);
double ley_snell(double mediouno, double mediodos, double anguloi, double angulor, int cal);
void lanza_snell();
void lanza_fibra_r();
void lanza_algoritmo();

//funciona para generar numero entre 0 y N
int randZeroToN();
//funciona para generar numero entre 0 y 1
double randZeroToOne();

	
//numero de regiones 
int N;




//punto inincial 
pair<double,double> INI;

//punto final
pair<double,double> FIN;



int accion;
bool first = true;

double mediouno = 1.0; 
double mediodos = 1.5;


double anguloi;
double angulor;

//velocidad de la luz fijada.
const int velocidad_luz = 1;

//facotor para la fibra
const double fact = (mediouno-mediodos)/mediouno;

const double radio = 0.01;

int main(void) {
   
   
     if(first) {
		cout << "INTRODUZE LOS DATOS:" << endl;
		//numero de regiones
		cout << "introduce el numero de regiones " << endl;
		cin >> N; 
		
		//punto inicial oficial
		cout << "introduce el numero las posicion inicial " << endl;
		cin >> INI.first;
		INI.second = randZeroToOne();
		cout  << INI.first << " " <<  INI.second <<  endl;
		
		//punto final oficial
		cout << "introduce el numero las posicion final " << endl;
		cin >> FIN.first >> FIN.second;
		cout  << FIN.first << " " <<  FIN.second <<  endl;
		
		cout << "introduce el indice del medio 1 " << endl;
		cin >> mediouno;
		
		cout << "introduce el indice del medio 2 " << endl;
		cin >> mediodos; 	
		
		first = false;
		}
	
	if (not first) {
		cout << "----------MENU-----------" << endl;
		cout << "MENU:" << endl;
		cout << "Pulsa 1: para calcular la ley de sneall" << endl;
		cout << "Pulsa 2: para calular la r en la fibra" << endl;
		cout << "Pulsa 3: para aplicar el algoritmo" << endl;
		cout << "Pulsa 4: para exit " << endl;
		
		cout << "------------------------" << endl;
		cin >> accion; 
		cout << "se a va realizar la accion numero: " << accion << endl;
		if (accion == 1) lanza_snell();
		else if (accion == 2) lanza_fibra_r();
		else if (accion == 4) {cout << "saliendo el programa" << endl;exit(0);}
		else {cout << "el valor ha de estar entre 1 y 3, adios " << endl; exit(1);}
		}
	}


void lanza_algoritmo() {
	

	cout << "el valor de y(0)" << INI.second << endl;
	cout << "pintar como avanza en linea recta " << endl;
	
	
	main();
	
	}

	
	
	

// funciona para calcular la velocidad del medio
double velocidad_medio(double indice_medio) {
	return velocidad_luz/indice_medio;
	}
	
	
void lanza_fibra_r() {
     cout << "calculando valor de la r en la fibra" << endl;
     double r;
     cout << "mete el valro de r" << endl;
     cin  >> r;
     cout << "el centro fibra es " << centro_fibra(r) << endl;
     main();
    }
    

//funcion para obtener la r cada vez de la fibra
double centro_fibra(double r) {
	//radio es la "a".
	return mediouno*sqrt(1-(2*fact*(r/radio)));
	}

void lanza_snell() {
			//---prueba de la funcion de snell---//

	double u = 1;
	double d = 	1.5;
	double i = 45;
	int cal = 3;
	
	cout << "calculo de la ley de snell" << endl;
	cout << "indice de medio 1 igual a " << u <<   " indice del medio dos "  << d << endl;
	cout << "con angulo de incidencia  " << i << endl; 
	
	cout << "el valor del angulo reflactado es : " << ley_snell(u,d,i,1,cal)  << endl;
	main();
	
	}

//funciona para calcular la ley de snell
double ley_snell(double mediouno, double mediodos, double anguloi, double angulor, int cal) {
	double res;
	// calculamos el valor del medio1
	if (cal == 0) {
		res =mediodos*sin(angulor*PI/180)/sin(anguloi*PI/180);
		}
	// calculamos el valor del medio 2
	else if (cal == 1) {
		res= mediouno*sin(anguloi*PI/180)/sin(angulor*PI/180);
		
		}
		
	// calculamos el valor del anguloi	
	else if (cal == 2) {
		 double param = (sin(angulor*PI/180)*mediodos)/mediouno;
		 res= asin(param)* 180.0 / PI;
		}
	//calculamos el valor del angulor	
	else {
		double param = (mediouno*sin(anguloi*PI/180))/mediodos;
		 res = asin(param)* 180.0 / PI;
		} 
	return res;
	
	}


int randZeroToN() {
	srand (time(NULL));
	return rand() % N + 0;
	}


double randZeroToOne()
{
	srand (time(NULL));
	return  rand() / (RAND_MAX + 1.);
}


