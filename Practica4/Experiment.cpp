#include "Experiment.h"
#include <time.h>

Experiment::Experiment()
{

}

Experiment::~Experiment()
{

}

Experiment::Experiment(double puntoinicial, double angulo, double indiceuno, double indicedos, int regiones, bool random )
{
    vregiones = std::vector<region>(regiones);
    vregiones[0].puntoinicial = puntoinicial;
    vregiones[0].angulo = angulo;
    vregiones[0].indice = indiceuno;
    vregiones[0].puntofinal = calculatePoints(vregiones[0].angulo, vregiones[0].puntoinicial);

    int nrand = regiones/2;
    bool cambio_region = false;

    for (int step = 1 ; step < regiones-1 ; ++step) {
        vregiones[step].puntoinicial = vregiones[step-1].puntofinal;
        if( random ) {
            int change = qrand() % 2;
            if( change ){
              if( vregiones[step-1].indice == indiceuno ){
                  vregiones[step].angulo = snellLaw(indiceuno,indicedos,vregiones[step-1].angulo);
                  vregiones[step].indice = indicedos;
              }
              else {
                  vregiones[step].angulo = snellLaw(indicedos,indiceuno,vregiones[step-1].angulo);
                  vregiones[step].indice = indiceuno;
              }
            }
            else {
              vregiones[step].angulo = vregiones[step-1].angulo;
              vregiones[step].indice = vregiones[step-1].indice;

            }
            vregiones[step].puntofinal = calculatePoints(vregiones[step].angulo,vregiones[step].puntoinicial);
        }
        else{
            if (step < nrand) {

            vregiones[step].angulo = vregiones[step-1].angulo;
            vregiones[step].indice = vregiones[step-1].indice;

            }
            else  {
                if (not cambio_region) {
                    vregiones[step].angulo = snellLaw(indiceuno,indicedos,vregiones[step-1].angulo);
                    vregiones[step].indice = indicedos;
                    cambio_region = true;
                    }
                else  {
                    vregiones[step].angulo = vregiones[step-1].angulo;
                    vregiones[step].indice = vregiones[step-1].indice;
                    }
                }
            vregiones[step].puntofinal = calculatePoints(vregiones[step].angulo,vregiones[step].puntoinicial);
        }
    }

    vregiones[regiones-1].puntoinicial = vregiones[regiones-2].puntofinal;
    vregiones[regiones-1].angulo = vregiones[regiones-2].angulo;
    vregiones[regiones-1].indice = vregiones[regiones-2].indice;
    vregiones[regiones-1].puntofinal = calculatePoints(vregiones[regiones-1].angulo, vregiones[regiones-1].puntoinicial);
}

double Experiment::snellLaw(double n1, double n2, double iAngle)
{
    double param = n1*sin(iAngle*M_PI/180)/n2;
    double res = asin(param)* (180.0 / M_PI);
    return res;
}

double Experiment::calculatePoints(double angle, double initPoint)
{
    double calcsin = sin((angle*(M_PI/180))) * 40.0;
    double calccos = cos((angle*(M_PI/180)));
    double calcfinal = calcsin/calccos + initPoint;
    return calcfinal;
}

int Experiment::randZeroToN(int n)
{
    qsrand( time(NULL) );
    return qrand() % n - 2 + 2;
}

