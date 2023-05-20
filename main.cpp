#include "QMyMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMyMainWindow w;
    w.showMaximized();

    return a.exec();
}