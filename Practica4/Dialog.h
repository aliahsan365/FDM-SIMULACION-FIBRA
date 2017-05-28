#pragma once

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include "Experiment.h"



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void createLine();
    void setBasicScene();
    void setFiberScene();
    void startExperiment();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QLineF topLine, leftLine, rightLine, bottomLine;
    QPen eRed, eGray, eBlack, eYellow, eGreen;
    Experiment experiment;

    double x;
    double y;
    double n1, n2;
    const double size = 40.0;

    bool type; //false = fiber, true = basic)
    int regions;

    void setBox();
    void handleBasic();
    void handleFiber();
    void delay();
};


