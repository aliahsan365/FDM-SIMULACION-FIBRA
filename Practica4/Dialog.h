#pragma once

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>

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

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QTimer *timer;

    double startX;
    double startY;
};


