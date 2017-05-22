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
double randomizevalue(double min, double max);

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
const int c = 1;

//facotor para la fibra
const double fact = (mediouno-mediodos)/mediouno; // delta de la fibra 

const double radio = 0.01; // la "a " de la fibra

int main(void) {
   
    while (1) {cout << randomizevalue(1.58, 2.0) << endl;}
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
		else if (accion == 3) lanza_algoritmo();
		else if (accion == 4) {cout << "saliendo el programa" << endl;exit(0);}
		else {cout << "el valor ha de estar entre 1 y 3, adios " << endl; exit(1);}
		}
	}


void lanza_algoritmo() {
	

	cout << "el valor de y(0)" << INI.second << endl;
	
	
	int change = randZeroToN();
	
	double timeregionuno = 0.0;
	double timeregiondos = 0.0;
	double timetotal = 0.0;
	
	cout << "timepo = ditancia/velocidad" << endl;
	cout << "disstancia es siempre 1" << endl;
	cout << "velocidad depende del medio : v = v_luz/indice_medio" << endl;
	cout << "velocidad para el medio 1 " << c/mediouno << endl;
	cout << "velocidad para el medio 2 " << c/mediodos << endl;

	cout << "va a empezar a cambiar de medio despues de " << change << " regiones" << endl;
	pair<double,double > auxini = INI;

	
	for (int i = 0; i < N; ++i) {
		
		double minrand =  randomizevalue(0.0,auxini.second);
		double maxrand =  randomizevalue(auxini.second,1.0);
		double d1,d2;
		
		if (i < change) {
			//tiempo = distancia_region(1) / velocidad_medio1.
			
			d1 = sqrt( pow(minrand,2) + pow(1,2));
			cout << "d1 "  << d1 << endl;
			d2 = sqrt( pow(maxrand,2) + pow(1,2));
			cout << "d2 " << d2 << endl;
			auxini.second = min(d1*c/mediouno,d2*c/mediouno);
			timeregionuno = timeregionuno + 1/(c/mediouno);
			}
		else if (i == change) {
			//calculamos el angulo de incidencia;
			double aux = auxini.second;
			d1 = sqrt( pow(minrand,2) + pow(1,2));
			cout << "d1 "  << d1 << endl;
			d2 = sqrt( pow(maxrand,2) + pow(1,2));
			cout << "d2 "  << d2 << endl;
			auxini.second = min(d1*c/mediouno,d2*c/mediouno);
			timeregionuno = timeregionuno + 1/(c/mediouno);
			double anguloincidencia = atan(abs(auxini.second-aux))* 180.0 / PI;
			cout << "angulo de incidencia de la region de cambio de medio" << anguloincidencia <<  endl;
			
			}
		else {
			//tiempo = distancia_region(1) / velocidad_medio2.
		    d1 = sqrt( pow(minrand,2) + pow(1,2));
		    cout << "d1 "  << d1 << endl;
			d2 = sqrt( pow(maxrand,2) + pow(1,2));
			cout << "d2 "  << d2 << endl;
			auxini.second = min(d1*c/mediodos,d2*c/mediodos);
			timeregiondos = timeregiondos + 1/(c/mediodos);
			}
		}
	timetotal = timeregionuno+timeregiondos;
	cout << "timeregionuno " << timeregionuno << " timeregiondos "  << timeregiondos << endl;
	cout << "tiempo total " << timetotal << endl;
	main();
	}

	
	
	

// funciona para calcular la velocidad del medio
double velocidad_medio(double indice_medio) {
	return c/indice_medio;
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
	return rand() % N-1 + 0;
	}


double randZeroToOne()
{
	srand (time(NULL));
	return  rand() / (RAND_MAX + 1.);
}

double randomizevalue(double min, double max) {
	srand (time(NULL));
	double res =   rand() / (min + max);
	cout << "resultado de randomizar " << res << endl; 
	return res;
	}
