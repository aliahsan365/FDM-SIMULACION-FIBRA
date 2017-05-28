#pragma once

#include <QVector>

#define PI 3.14159265

class Experiment
{
public:
    Experiment();
    ~Experiment();
    Experiment(double puntoinicial, double angulo, double indiceuno, double indicedos, int regiones , bool random);

    struct region{
     double puntoinicial;
     double puntofinal;
     double angulo;
     double indice; // 1 -> aire ; 1.5->aigua
    };

    std::vector<region> vregiones;

private:
    double snellLaw( double n1, double n2, double iAngle );
    double calculatePoints( double angle, double initPoint );
    int randZeroToN( int n );
};
