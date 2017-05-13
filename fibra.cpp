#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define PI 3.14159265


//numero de regiones 
int N;

//punto inincial 
pair<int,int> INI;

//punto final
pair<int,int> FIN;



const double mediouno = 1.0; 
const double mediodos = 1.5;


double anguloi;
double angulor;

//velocidad de la luz fijada.
const int velocidad_luz = 1;

//facotor para la fibra
const double fact = (mediouno-mediodos)/mediouno;

double radio;


// funciona para calcular la velocidad del medio

double velocidad_medio(double velocidad_medio) {
	return velocidad_luz/velocidad_medio;
	}



//funcion para obtener la r cada vez de la fibra
double centro_fibra(double r) {
	//radio es la "a".
	return mediouno*sqrt(1-(2*fact*(r/radio)));
	}



//funciona para calcular la ley de snell
double ley_snell(double mediouno, double mediodos, double anguloi, double angulor, int cal) {
	
	// calculamos el valor del medio1
	if (cal == 0) {
		return mediodos*sin(angulor*PI/180)/sin(anguloi*PI/180);
		}
	// calculamos el valor del medio 2
	else if (cal == 1) {
		return mediouno*sin(anguloi*PI/180)/sin(angulor*PI/180);
		
		}
		
	// calculamos el valor del anguloi	
	else if (cal == 2) {
		 double param = (sin(angulor*PI/180)*mediodos)/mediouno;
		 return asin(param)* 180.0 / PI;
		
		}
		
	//calculamos el valor del angulor	
	else {
		double param = (mediouno*sin(anguloi*PI/180))/mediodos;
		 return asin(param)* 180.0 / PI;
		} 
	}



int main() {

	//---prueba de la funcion de snell---//
	cout << "calculo de la ley de snell" << endl;
	double u = 1;
	double d = 	1.5;
	double i = 45;
	int cal = 3;
	cout << "el valor es " << ley_snell(u,d,i,1,cal)  << endl;
	//----------------------------------//
	
	
	//numero de regiones
	cout << "introduce el numero de regiones " << endl;
	cin >> N; 
	
	//punto inicial oficial
	
	cout << "introduce el numero las posicion inicial " << endl;
	cin >> INI.first >> INI.second;
	cout  << INI.first << " " <<  INI.second <<  endl;
	
	//punto final oficial
	
	cout << "introduce el numero las posicion final " << endl;
	cin >> FIN.first >> FIN.second;
	cout  << FIN.first << " " <<  FIN.second <<  endl;	
	
	
	//introducimos los valores que van a ser constantes.
	
	cout << "mete el mediouno" << endl;
	//cin >> mediouno;
	cout << "mete el mediodos" << endl;
	//cin >> mediodos;
	
	//por pensar...
	cout << "mete el angulo de incidencia" << endl;
	cout << "mete el angulo refractado" << endl;
	
	//--------------valores para la fibra----------------
	
	cout << "mete el radio de la fibra" << endl;
	
	
	
}
