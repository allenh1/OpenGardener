#include <QCoreApplication>
#include "mainthread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainThread * test = new MainThread(&a);

    test->run();

    return a.exec();
}
