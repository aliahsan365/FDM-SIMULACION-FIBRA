#include <iostream>
#include <algorithm>
#include <cmath>
#include <time.h> 
#include <stdlib.h>
#include <vector>

using namespace std;

#define PI 3.14159265





class snell {
	
	private:
	
	
	struct region{
	 double puntoinicial;
	 double puntofinal;
	 double angulo;
	 double indice; // 1 -> aire ; 1.5->aigua
	};
	
	vector<region> vregiones;
	
	
	int randZeroToN(int N) {
		srand (time(NULL));
		return rand() % N-2 + 2;
		}

	double calcular_puntos(double angulo,double puntoinicial) {
	
		double calcsin = sin((angulo*(M_PI/180)));
		double calccos = cos((angulo*(M_PI/180)));
		double calcfinal = calcsin/calccos + puntoinicial;
	    return calcfinal;
	}
	
	
	
    double ley_snell(double indiceuno,double indicedos,double anguloi) {
		double param = (indiceuno*sin(anguloi*M_PI/180))/indicedos;
		double res = asin(param)* (180.0 / M_PI);
		cout << "angulo resultado de snrell " << res << endl;
		return res;
    }
	
	public: 
	
	snell(double puntoinicial,double angulo,double indiceuno,double indicedos, int regiones) {
	
	
	  vregiones = vector<region> (regiones);


     //inicializamos el primero elemento del vector regiones
     
     vregiones[0].puntoinicial = puntoinicial;
    
     
     vregiones[0].angulo = angulo;
     
     

     vregiones[0].indice = indiceuno;
     

     
     vregiones[0].puntofinal = calcular_puntos(vregiones[0].angulo,vregiones[0].puntoinicial);

           


	
	
	
    int nrand = randZeroToN(regiones);
    
    cout << "se va a cambiar de regio en la " << nrand << endl;
    
	
    bool cambio_region = false;

	
	//algoritmo;
	for (int step = 1 ; step < regiones-1 ; ++step) {
		vregiones[step].puntoinicial = vregiones[step-1].puntofinal;
		
		
		// no ha cambiado de medio
		if (step < nrand) {
		
		vregiones[step].angulo = vregiones[step-1].angulo;
		vregiones[step].indice = vregiones[step-1].indice;
		
		}
	    
	    //ha cambiado de medio
	    else  {
			//ley de snell para calcuilar el segundo angulo
			if (not cambio_region) {
				vregiones[step].angulo = ley_snell(indiceuno,vregiones[step-1].indice,vregiones[step-1].angulo); 
				vregiones[step].indice = indicedos;
				cambio_region = true;
				}
			else  {		
				vregiones[step].angulo = vregiones[step-1].angulo;
				vregiones[step].indice = vregiones[step-1].indice;
				}
            }
        
        //hacemos que el punto final sera el incial
        vregiones[step].puntofinal = calcular_puntos(vregiones[step].angulo,vregiones[step].puntoinicial); 
       }
       
         
     vregiones[regiones-1].puntoinicial = vregiones[regiones-2].puntoinicial;
     vregiones[regiones-1].angulo = vregiones[regiones-2].angulo;
     vregiones[regiones-1].indice = vregiones[regiones-2].indice;
     vregiones[regiones-1].puntofinal = calcular_puntos(vregiones[regiones-2].angulo,vregiones[regiones-2].puntoinicial);
	print_vector_region(vregiones);
		
		
		
		
		}
    
    
    
    void print_vector_region(vector<region> v) {
		for (int i = 0; i < int(v.size()); ++i) {
			cout << "region numero " << i << ":" << endl;
			cout << "puntoincial " << v[i].puntoinicial << endl;
			cout << "puntofinal " <<  v[i].puntofinal << endl;
			cout << "angulo " << v[i].angulo << endl;
			cout << "indice " << v[i].indice << endl;
		}
	
	}

    
    
	
	};
	
	
int main() {
	 
	snell s(0.5,45,1,1.5,10);
	
	}

