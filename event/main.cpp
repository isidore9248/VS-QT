#include "Event.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Event w;
    w.show();
    return a.exec();
}
