#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene( this );
    ui->graphicsView->setScene( scene );
    ui->graphicsView->setRenderHint( QPainter::Antialiasing );

    connect( ui->basicButton, SIGNAL(released()), this, SLOT( setBasicScene() ) );
    connect( ui->fiberButton, SIGNAL(released()), this, SLOT( setFiberScene() ) );
    connect( ui->startButton, SIGNAL(released()), this, SLOT( startExperiment() ) );


    eRed = QPen( Qt::red, 3 );
    eBlue = QPen( Qt::blue, 1 );
    eBlack = QPen( Qt::black, 3);
    type = false;

    setBox();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::createLine()
{
    if( type ){
        handleBasic();
    }
    else{
        handleFiber();
    }
}

void Dialog::setBasicScene()
{
    scene->clear();
    setBox();
    for( double i = 50.0; i < 500.0; i += 50.0 ){
         QPointF top( scene->sceneRect().topLeft() );
         QPointF bot( scene->sceneRect().bottomLeft() );
         top.setX( top.x() + i );
         bot.setX( bot.x() + i );
         QLineF Line( bot, top );
         scene->addLine( Line, eBlue );
    }
    x = scene->sceneRect().topLeft().x();
    type = true;
}

void Dialog::setFiberScene()
{
    scene->clear();
    setBox();
    for( double i = 50.0; i < 500.0; i += 50.0 ){
         QPointF left( scene->sceneRect().topLeft() );
         QPointF right( scene->sceneRect().topRight() );
         left.setY( left.y() + i );
         right.setY( right.y() + i );
         QLineF Line( left, right );
         scene->addLine( Line, eBlue );
    }
    x = scene->sceneRect().topLeft().x();
    type = false;
}

void Dialog::startExperiment()
{

    double angle = ui->angleEdit->text().toDouble();
    double n1 = ui->n1Edit->text().toDouble();
    double n2 = ui->n2Edit->text().toDouble();
    int regions = ui->regionsEdit->text().toInt();
    double posInicial = 250.0;
    experiment = Experiment(posInicial, angle, n1, n2, regions);
    createLine();
}

void Dialog::setBox()
{
    scene->setSceneRect( 0, 0, 500, 500 );

    QLineF topLine( scene->sceneRect().topLeft(), scene->sceneRect().topRight() );
    QLineF leftLine( scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft() );
    QLineF rightLine( scene->sceneRect().topRight(), scene->sceneRect().bottomRight() );
    QLineF bottomLine( scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight() );

    scene->addLine( topLine, eBlack );
    scene->addLine( leftLine, eBlack );
    scene->addLine( rightLine, eBlack );
    scene->addLine( bottomLine, eBlack );
}
#include <qDebug>
void Dialog::handleBasic()
{
    foreach( Experiment::region r, experiment.vregiones ){
        QPointF left( x, r.puntoinicial );
        x += 50;
        QPointF right( x, r.puntofinal );
        QLineF Line( left, right );
        scene->addLine( Line, eRed );
        qDebug() << r.puntoinicial << " " << r.puntofinal;
    }
}

void Dialog::handleFiber()
{

}
