#include <QApplication>
#include "rasdial.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rasdial w;
    w.show();
    
    return a.exec();
}
