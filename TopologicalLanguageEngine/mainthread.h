#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include <QObject>

#include "set.h"
#include "set.cpp"
class MainThread : public QObject
{
    Q_OBJECT
public:
    MainThread(QObject *parent = 0) : QObject(parent)
    {connect(this, SIGNAL(finished()), parent, SLOT(quit()));}

    Q_SIGNAL void finished();

    void run();
    template<typename Y>
    void print(Set<Y> * s);
};

#endif // MAINTHREAD_H
