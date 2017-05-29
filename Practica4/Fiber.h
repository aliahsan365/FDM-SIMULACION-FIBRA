#pragma once

#include<QVector>

#define PI 3.14159265

class Fiber
{
public:
    Fiber();
    Fiber(int N, double angleinicial, double a);
    ~Fiber();

    std::vector<double> index;
    QVector<double> desp;
private:

    int randZeroToN( int N );
    double calcular_puntos(double angulo,double puntoinicial);
    double calcular_distancia(double angulo);
    double ley_snell(double indiceuno,double indicedos,double anguloi);
    double calcular_triangle(double n1, double n2) ;
    double calcular_formula_tocha(double n1, double tr, double r, double a);
};
