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
    scene->setSceneRect( -200, -200, 500, 500 );

    QLineF TopLine( scene->sceneRect().topLeft(), scene->sceneRect().topRight() );
    QLineF LeftLine( scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft() );
    QLineF RightLine( scene->sceneRect().topRight(), scene->sceneRect().bottomRight() );
    QLineF BottomLine( scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight() );

    QPen mPen = QPen( Qt::blue );

    for( double i = 50.0; i < 500.0; i += 50.0 ){
         QPointF top( scene->sceneRect().topLeft() );
         QPointF bot( scene->sceneRect().bottomLeft() );
         top.setX( top.x() + i );
         bot.setX( bot.x() + i );
         QLineF Line( bot, top );
         scene->addLine( Line, mPen );
    }

    scene->addLine( TopLine, mPen );
    scene->addLine( LeftLine, mPen );
    scene->addLine( RightLine, mPen );
    scene->addLine( BottomLine, mPen );

    startX = scene->sceneRect().topLeft().rx();
    startY = scene->sceneRect().topLeft().ry();

    timer = new QTimer( this );
    connect( timer, SIGNAL( timeout() ), this, SLOT( createLine() ) );
    timer->start( 1000 );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::createLine()
{
    QPen mPen = QPen( Qt::red );

    double endY = double( qrand() % 500 ) - 200.0;
    QPointF left( startX, startY );
    QPointF right( startX + 50.0, endY );
    QLineF Line( left, right );
    scene->addLine( Line, mPen );

    startX = startX + 50.0;
    startY = endY;

    if( startX == scene->sceneRect().topRight().rx() ){
        timer->blockSignals( true );
    }

}
