#include <iostream>
#include <algorithm>
#include <cmath>
#include <time.h> 
#include <stdlib.h>
#include <vector>

using namespace std;

#define PI 3.14159265

struct region{
	 double puntoinicial;
	 double puntofinal;
	 double angulo;
	 double indice; // 1 -> aire ; 1.5->aigua
	};
	

 void print_vector_double(vector<double> v) {
		for (int i = 0; i < int(v.size()); ++i) {
			cout << v[i] << " ";
			}
			cout << endl;
		}


double calcular_triangle(double n1, double n2) {
	return (n1-n2)/n1;
}


double calcular_formula_tocha(double n1, double tr, double r, double a) {
	return n1*(sqrt((1-2*tr*(pow((r/a),a)))));
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


double calcular_puntos(double angulo,double puntoinicial) {
	
		double calcsin = sin((angulo*(M_PI/180)));
		double calccos = cos((angulo*(M_PI/180)));
		double calcfinal = calcsin/calccos + puntoinicial;
	    return calcfinal;
	}




int main() {
	
	
	double angleincial = 40;
	double puntoini = 1.1;
	int N = 50; 				 // regions
	double radi = 1.0;			 // radi
	double a = 0.4;				 // radi del nucli
								 // 0 <= r < a
	double n1 = 1.47;
	double n2 = 1;
	double triangle = 0.01;
	// calcular triangle, o n2, per la formula del pdf
	n2 =  calcular_formula_tocha(n1,triangle,radi,a);
	cout << "indice dos " << n2 << endl;
	
	vector<double> indices(N);
	vector<double> angulos(N);
	vector<double> puntoinicial(N);
	vector<double> puntofinal(N);
	
	
	indices[0] = 1.47;
	angulos[0] = angleincial;
    puntoinicial[0] = puntoini;
    puntofinal[0] = calcular_puntos(angulos[0], puntoinicial[0]);
	
	for (int i = 1; i < N; ++i) {
		indices[i] = calcular_formula_tocha(indices[i-1],triangle ,radi,a);
		angulos[i] = ley_snell(indices[i-1],indices[i],angulos[i-1]);
		puntoinicial[i] = puntofinal[i-1];
		puntofinal[i] = calcular_puntos(angulos[i],puntoinicial[i]);
	}
		
    cout << "-------------------INDICES---------" << endl;
	print_vector_double(indices);
	cout << "--------------ANGUILOS----------" << endl;
	print_vector_double(angulos);
	cout << "---------------PUNTOS INICIALES-------" << endl;
	print_vector_double(puntoinicial);
	cout << "----------------PUNTOS FINALES----" << endl;
	print_vector_double(puntofinal);
	
	
	
}
