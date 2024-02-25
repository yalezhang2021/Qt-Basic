#include "circlewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CircleWidget w;
    w.show();
    w.startCircle();

    return a.exec();
}
