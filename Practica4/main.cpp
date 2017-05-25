#include "Dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setWindowTitle( "Light Propagation" );
    w.show();

    return a.exec();
}
