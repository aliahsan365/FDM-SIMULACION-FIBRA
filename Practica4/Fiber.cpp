#include "Fiber.h"
#include <time.h>
#include <qDebug>

Fiber::Fiber()
{

}

Fiber::Fiber(int N, double angleinicial, double a)
{
    double radi = 1.0;			 // radi

    double triangle = 0.01;

    index = std::vector<double> (N);
    index[N/2] = 1.47;

    int c = N/2;
    int i = 0;
    while( i < N/2 && c+i+1 < N ){
        index[c+i+1] = calcular_formula_tocha(index[c+i], triangle, radi, a);
        index[c-i-1] = index[c+i+1];
        triangle = calcular_triangle(index[c+i], index[c+i+1]);
        ++i;
    }


    double anguloInc = angleinicial;
    desp.append( 0 );
    anguloInc = ley_snell(1, index[N/2], std::abs( 90.0 - anguloInc ) );
    desp.append( calcular_puntos( anguloInc, desp.last() ) );
    int count = 0;
    bool subir = true;
    i = N/2 + 2;
    while( i < N && i >= 0 && count < 1000 ){
        if( i == N - 1 ){
            anguloInc = ley_snell(index[i], index[i], anguloInc );
            desp.append( calcular_puntos( anguloInc, desp.last() ) );
            subir = false;
            --i;
        }
        else if( i == 0 ){
            anguloInc = ley_snell(index[i], index[i], anguloInc );
            desp.append( calcular_puntos( anguloInc, desp.last() ) );
            subir = true;
            ++i;
        }
        else if( subir ){
            anguloInc = ley_snell(index[i-1], index[i], anguloInc );
            desp.append( calcular_puntos( anguloInc, desp.last() ) );
            ++i;
        }
        else if( !subir ){
            anguloInc = ley_snell(index[i+1], index[i], anguloInc );
            desp.append( calcular_puntos( anguloInc, desp.last() ) );
            --i;
        }
        ++count;
    }
}

Fiber::~Fiber(){

}

int Fiber::randZeroToN(int N)
{
    srand (time(NULL));
    return rand() % N-2 + 2;
}

double Fiber::calcular_puntos(double angulo, double puntoinicial)
{
    double calcsin = sin(angulo*(M_PI/180));
    double calccos = cos(angulo*(M_PI/180));
    //para calcular el punto de ini
    double calcfinal = (calccos)/calcsin + puntoinicial;
    //double calcfinal = (calcsin*50)/calccos + puntoinicial;
    return calcfinal;
}

double Fiber::calcular_distancia(double angulo)
{
    double calcsin = sin(angulo*(M_PI/180));
    double calccos = cos(angulo*(M_PI/180));
    //para calcular el punto de ini
    double calcfinal = (calccos)/calcsin;
    //double calcfinal = (calcsin*50)/calccos + puntoinicial;

    return calcfinal;
}

double Fiber::ley_snell(double indiceuno, double indicedos, double anguloi)
{
    double param = ( indiceuno*sin( anguloi*M_PI/180.0) )/indicedos;
    //cout << "valor de param " << param << endl;
    double res = asin(param)* (180.0 / M_PI);
    //cout << "angulo resultado de snrell " << res << endl;
    return res;
}

double Fiber::calcular_triangle(double n1, double n2)
{
    return (n1-n2)/n1;
}

double Fiber::calcular_formula_tocha(double n1, double tr, double r, double a)
{
    return n1*(sqrt((1-(2*tr*(pow((r/a),a))))));
}
