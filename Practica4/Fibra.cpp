#include <iostream>
#include <algorithm>
#include <cmath>
#include <time.h> 
#include <stdlib.h>
#include <vector>

using namespace std;

#define PI 3.14159265



class Fibra {
	
	private:
	
	
	struct region{
		double puntoinicial;
		double puntofinal;
		double angulo;
		double indice; // 1 -> aire ; 1.5->aigua
		double distanciacalculada;
		};
	
    vector<region> vregiones;
	vector<region> vregiones2;
	
int randZeroToN(int N) {
    srand (time(NULL));
    return rand() % N-2 + 2;
}


double calcular_puntos(double angulo,double puntoinicial) {
    double calcsin = sin((angulo*(M_PI/180)));
    double calccos = cos((angulo*(M_PI/180)));
        //para calcular el punto de ini
        double calcfinal = (calccos*100)/calcsin + puntoinicial;
        //double calcfinal = (calcsin*50)/calccos + puntoinicial;
        return calcfinal;
}

double calcular_distancia(double angulo) {
    double calcsin = sin((angulo*(M_PI/180)));
    double calccos = cos((angulo*(M_PI/180)));
    //para calcular el punto de ini
    double calcfinal = (calccos*100)/calcsin;
    //double calcfinal = (calcsin*50)/calccos + puntoinicial;

    return calcfinal;
}



	
double calcular_puntos2(double angulo,double puntoinicial) {
	   
    double calcsin = sin((angulo*(M_PI/180)));
    double calccos = cos((angulo*(M_PI/180)));
    //para calcular el punto de ini
    double calcfinal = (calccos)/calcsin + puntoinicial;
    //double calcfinal = (calcsin*50)/calccos + puntoinicial;

    return calcfinal;
}
	
	
    double ley_snell(double indiceuno,double indicedos,double anguloi) {
		
		//cout << "indice uno " << indiceuno << endl;
		//cout << "indice dos " << indicedos << endl;
		//cout << "angulo i  uno " << anguloi << endl;


		
		double param = indiceuno*sin(anguloi*M_PI/180)/indicedos;
		//cout << "valor de param " << param << endl;
		double res = asin(param)* (180.0 / M_PI);
		//cout << "angulo resultado de snrell " << res << endl;
		return res;
    }
	
	public: 
	
	
	
	
	
	Fibra(int N) {
		
		double angleincial = 20;
		double puntoini = 0;
		 				 // regions
		double radi = 3.0;			 // radi
		double a = 0.4;				 // radi del nucli
								 // 0 <= r < a
		
		double triangle = 0.01;
	
		vregiones = vector<region> (N);
		
		vregiones2 = vector<region> (N);
		
		vregiones[0].indice = 1.47;
		
		vregiones[0].angulo = angleincial;
		
		vregiones[0].puntoinicial = puntoini;
		
		vregiones[0].puntofinal = calcular_puntos(vregiones[0].angulo,vregiones[0].puntoinicial);
	
		vregiones[0].distanciacalculada = calcular_distancia(vregiones[0].angulo);
		
		
		for (int i = 1; i < N; ++i) {
			vregiones[i].indice = calcular_formula_tocha(vregiones[i-1].indice,triangle ,radi,a);
			//angulos i-1 , indice1-> i-1 , indice2 -> indice1
		
			vregiones[i].angulo = ley_snell(vregiones[i-1].indice,vregiones[i].indice,vregiones[i-1].angulo);
		
			vregiones[i].puntoinicial = vregiones[i-1].puntofinal;
		
			vregiones[i].puntofinal = calcular_puntos(vregiones[i].angulo,vregiones[i].puntoinicial);
			
			vregiones[i].distanciacalculada = calcular_distancia(vregiones[i].angulo);
			
			}
		
		for (int i = 0; i < int(vregiones.size()); ++i) {
			cout << "region numero " << i << ":" << " puntoincial " << vregiones[i].puntoinicial << " puntofinal " <<  vregiones[i].puntofinal  << " angulo " << vregiones[i].angulo <<  " indice " << vregiones[i].indice << " distancia calculada " << vregiones[i].distanciacalculada << endl;
			}
			
		// veregiones2 (bajada en la fibra)
		
		
		//testeado y ok. para lo indcies
		
		for (int i = 0; i < N; ++i) {
			vregiones2[i].indice = vregiones[N-1-i].indice;
			}
		
		//calculamos el primero elemento del vector de bajada .2
		
		
		vregiones2[0].angulo = vregiones[N-1].angulo;
		
		vregiones2[0].puntoinicial = vregiones[N-1].puntofinal ;
		
		vregiones2[0].puntofinal = vregiones[N-1].puntofinal;
	
		vregiones2[0].distanciacalculada = calcular_distancia(vregiones[0].angulo);
		
		
		//imprimendo el el de la pos0 del vector2
		//cout << "region numero " << 0 << ":" << " puntoincial " << vregiones2[0].puntoinicial << " puntofinal " <<  vregiones2[0].puntofinal  << " angulo " << vregiones2[0].angulo <<  " indice " << vregiones2[0].indice << " distancia calculada " << vregiones2[0].distanciacalculada << endl;
		
		
		cout << "+-------------------------------" << endl;	
		
		for (int i = 1; i < N; ++i) {
			//angulos i-1 , indice1-> i-1 , indice2 -> indice1
		
			vregiones2[i].angulo = ley_snell(vregiones2[i-1].indice,vregiones2[i].indice,vregiones2[i-1].angulo);
		
			vregiones2[i].puntoinicial = vregiones2[i-1].puntofinal;
		
			vregiones2[i].puntofinal = calcular_puntos(vregiones2[i].angulo,vregiones2[i].puntoinicial);
			
			
			vregiones2[i].distanciacalculada = calcular_distancia(vregiones2[i].angulo);
			
			}
			
		
		for (int i = 0; i < int(vregiones.size()); ++i) {
		    cout << "region numero " << N-i-1 << ":" << " puntoincial " << vregiones2[i].puntoinicial << " puntofinal " <<  vregiones2[i].puntofinal  << " angulo " << vregiones2[i].angulo <<  " indice " << vregiones2[i].indice << " distancia calculada " << vregiones2[i].distanciacalculada << endl;
		}
		
		//escalando el punto final del vector de bajada (vregiones2).
		//factor (2*i*escalado)
	}

	
double calcular_triangle(double n1, double n2) {
	return (n1-n2)/n1;
}


double calcular_formula_tocha(double n1, double tr, double r, double a) {
	return n1*(sqrt((1-2*tr*(pow((r/a),a)))));
}

	
};
	



