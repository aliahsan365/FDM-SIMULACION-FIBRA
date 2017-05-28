#pragma once

#include<QVector>

class Fiber
{
public:
    Fiber();

    struct region{
        double puntoinicial;
        double puntofinal;
        double angulo;
        double indice; // 1 -> aire ; 1.5->aigua
        double distanciacalculada;
    };

    std::vector<region> vregiones;
    std::vector<region> vregiones2;

    int randZeroToN( int N );
    double calcular_puntos(double angulo,double puntoinicial);


};
