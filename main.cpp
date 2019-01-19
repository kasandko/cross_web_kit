#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.setGeometry(300, 150, 600, 500);
    w.show();

    return a.exec();
}
