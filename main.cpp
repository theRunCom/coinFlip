#include "mainwindow.h"
#include "startscene.h"
#include "selectscene.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    StartScene sc;
    sc.show();
    
    return a.exec();
}
