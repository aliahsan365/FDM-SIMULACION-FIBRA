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
    QPen eRed, eBlue, eBlack;
    Experiment experiment;

    double x;
    double y;
    bool type; //false = fiber, true = basic)

    void setBox();
    void handleBasic();
    void handleFiber();
};


