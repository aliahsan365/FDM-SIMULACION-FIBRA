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


    eGray = QPen( Qt::gray, 1 );
    eBlack = QPen( Qt::black, 3);
    eRed = QPen( Qt::red, 4 );
    eBlue = QPen( Qt::blue, 4 );
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
    size = 40;
    type = true;
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
}

void Dialog::setFiberScene()
{
    scene->clear();
    regions = ( ui->regionsEdit->text().toInt() ? ui->regionsEdit->text().toInt() : 10 ) ;
    size = 15;
    type = false;
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

}

void Dialog::startExperiment()
{
    if( type ){
        double angle = ui->angleEdit->text().toDouble() ? ui->angleEdit->text().toDouble() : 25.0;
        n1 =  ui->n1Edit->text().toDouble() ? ui->n1Edit->text().toDouble() : 1;
        n2 = ui->n2Edit->text().toDouble() ? ui->n2Edit->text().toDouble() : 1.5;
        regions = ui->regionsEdit->text().toInt() ? ui->regionsEdit->text().toInt() : 10;
        double posInicial = ( size * regions ) / 2;
        experiment = Experiment(posInicial, angle, n1, n2, regions, ui->randomBox->isChecked() );
    }
    else {
        regions = ui->regionsEdit->text().toInt() ? ui->regionsEdit->text().toInt() : 10;
        double angle = ui->angleEdit->text().toDouble() ? ui->angleEdit->text().toDouble() : 25.0;
        double a = ( ui->aEdit->text().toDouble() ? ui->aEdit->text().toDouble() : 1.0 );
        fiber = Fiber(regions, angle, a);
    }
    createLine();
}

void Dialog::setBox()
{
    if( type ){
        scene->setSceneRect( 0, 0, size*regions, size*regions );
    }
    else {
        scene->setSceneRect( 0, 0, size*regions*2, size*regions );
    }

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
                scene->addLine( line, eRed );
            }
            else {
                scene->addLine( line, eBlue );
            }
        }
        delay();
    }
}

void Dialog::handleFiber()
{
    y = ( (regions / 2) + 1) * 15;
    bool subir = ui->angleEdit->text().toDouble() >= 0 ? true : false ;
    for(int i = 1; i < fiber.desp.size(); ++i ){
        if( fiber.desp[i-1] * 3 < size * regions * 2 ){
            QPointF left( fiber.desp[i-1] * 3, y );
            if( y == 0) subir = false;
            else if( y == size * regions ) subir = true;

            if( subir ) y -= size;
            else y += size;
            QPointF right( fiber.desp[i] * 3, y );
            QLineF line( left, right );
            scene->addLine( line, eRed );
            delay();
        }
    }
}

void Dialog::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs( 20 );
    while(QTime::currentTime() < dieTime){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
