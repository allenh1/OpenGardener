#ifndef TIMEDURATION_H
#define TIMEDURATION_H

#include <QString>

class TimeDuration
{
public:
    TimeDuration(int days)
    {
        p_days = new int(days);
        QString temp;
        temp.setNum(*p_days);
        temp += " days";
        p_toString = new QString(temp);
    }//end constructor

    ~TimeDuration()
    { delete p_toString; delete p_days; }

    const QString & toString(){ return * p_toString; }

private:
    int * p_days;
    QString * p_toString;
};

#endif // TIMEDURATION_H
