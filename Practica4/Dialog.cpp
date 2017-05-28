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
    eGray = QPen( Qt::gray, 1 );
    eBlack = QPen( Qt::black, 3);
    eYellow = QPen( Qt::yellow, 4 );
    eGreen = QPen( Qt::green, 4 );
    type = false;
    regions = 10;
    n1 = 1;
    n2 = 1.5;

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
        setBox();
    }
    else{
        handleFiber();
        setBox();
    }
}

void Dialog::setBasicScene()
{
    scene->clear();
    regions = ( ui->regionsEdit->text().toInt() ? ui->regionsEdit->text().toInt() : 10 ) ;
    setBox();
    for( double i = size; i < size*regions; i += size ){
         QPointF top( scene->sceneRect().topLeft() );
         QPointF bot( scene->sceneRect().bottomLeft() );
         top.setX( top.x() + i );
         bot.setX( bot.x() + i );
         QLineF line( bot, top );
         scene->addLine( line, eGray );
    }
    x = scene->sceneRect().topLeft().x();
    type = true;
}

void Dialog::setFiberScene()
{
    scene->clear();
    regions = ( ui->regionsEdit->text().toInt() ? ui->regionsEdit->text().toInt() : 10 ) ;
    setBox();
    for( double i = size; i < size*regions; i += size ){
         QPointF left( scene->sceneRect().topLeft() );
         QPointF right( scene->sceneRect().topRight() );
         left.setY( left.y() + i );
         right.setY( right.y() + i );
         QLineF line( left, right );
         scene->addLine( line, eGray );
    }
    x = scene->sceneRect().topLeft().x();
    type = false;
}

void Dialog::startExperiment()
{

    double angle = ui->angleEdit->text().toDouble() ? ui->angleEdit->text().toDouble() : 25.0;
    n1 =  ui->n1Edit->text().toDouble() ? ui->n1Edit->text().toDouble() : 1;
    n2 = ui->n2Edit->text().toDouble() ? ui->n2Edit->text().toDouble() : 1.5;
    regions = ui->regionsEdit->text().toInt() ? ui->regionsEdit->text().toInt() : 10;
    double posInicial = ( size * regions ) / 2;
    experiment = Experiment(posInicial, angle, n1, n2, regions, ui->randomBox->isChecked() );
    createLine();
}

void Dialog::setBox()
{
    scene->setSceneRect( 0, 0, size*regions, size*regions );

    QLineF topLine( scene->sceneRect().topLeft(), scene->sceneRect().topRight() );
    QLineF leftLine( scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft() );
    QLineF rightLine( scene->sceneRect().topRight(), scene->sceneRect().bottomRight() );
    QLineF bottomLine( scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight() );

    scene->addLine( topLine, eBlack );
    scene->addLine( leftLine, eBlack );
    scene->addLine( rightLine, eBlack );
    scene->addLine( bottomLine, eBlack );
}

void Dialog::handleBasic()
{
    foreach( Experiment::region r, experiment.vregiones ){
        if( r.puntoinicial > 0 && r.puntoinicial < size*regions){
            QPointF left( x, r.puntoinicial );
            x += size;
            QPointF right( x, r.puntofinal );
            QLineF line( left, right );
            if( r.indice == n1 ){
                scene->addLine( line, eYellow );
            }
            else {
                scene->addLine( line, eGreen );
            }
        }
        delay();
    }
}

void Dialog::handleFiber()
{

}

void Dialog::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs( 500 );
    while(QTime::currentTime() < dieTime){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
