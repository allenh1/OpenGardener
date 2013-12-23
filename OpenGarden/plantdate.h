#ifndef PLANTDATE_H
#define PLANTDATE_H

/**
 * @brief The PlantDate class
 *
 * This class holds the necessary things for keeping track of a date.
 *
 * ToDo: Write operators!
 */

#include "timeduration.h"

enum MONTHS { JANUARY, FEBRUARY, MARCH, APRIL,
              MAY, JUNE, JULY, AUGUST,
              SEPTEMBER, OCTOBER, NOVEMBER,
              DECEMBER };

class PlantDate
{
public:
    PlantDate(int _day, int _month, int _year);
    ~PlantDate(){ delete p_day; delete p_month; delete p_year;
                  delete p_date;         }//remove the pointers

    friend PlantDate operator +(PlantDate & p1, TimeDuration & p2);
    friend TimeDuration operator -(PlantDate & p1, PlantDate & p2);

    bool operator == (PlantDate rhs)
    {
        return *p_date == rhs.toString();
    }//check for equality

    bool operator == (PlantDate * rhs)
    {
        return *p_date == rhs->toString();
    }//check for equality

    bool operator < (PlantDate rhs)
    {
        /** Returns true when three conditions are met:
         *
         * i. The day of the left is less than that of the right
         * ii. the month of the left is less than or equal to that of the right
         * iii. the year of the left is less than or equal to that of the right
         */

        if (*p_year > rhs.getYear())
            return false;

        if (*p_month > rhs.getMonth())
            return false;

        if (*p_day > rhs.getDay())
            return false;

        return true;

    }//Which date comes first?

    bool operator > (PlantDate rhs)
    {
        if (*p_year < rhs.getYear())
            return false;

        if (*p_month < rhs.getMonth())
            return false;

        if (*p_day < rhs.getDay())
            return false;

        return true;
    }//Which date comes first?

    const QString & toString(){ return *p_date; }

    QString getMonthName()
    {
        return getMonthName(*p_month);
    }

    QString getMonthName(int month)
    {
        if (month == JANUARY)
            return QString ("January");

        else if (month == FEBRUARY)
            return QString ("February");

        else if (month == MARCH)
            return QString ("March");

        else if (month == APRIL)
            return QString ("April");

        else if (month == MAY)
            return QString ("May");

        else if (month == JUNE)
            return QString ("June");

        else if (month == JULY)
            return QString ("July");

        else if (month == AUGUST)
            return QString ("August");

        else if (month == SEPTEMBER)
            return QString ("September");

        else if (month == OCTOBER)
            return QString ("October");

        else if (month == NOVEMBER)
            return QString ("November");

        else if (month == DECEMBER)
            return QString ("December");

        else
            return QString ("Invalid"); //cath all
    }//identify the month of year

    const int & getDay(){ return * p_day; }
    const int & getMonth(){ return * p_month; }
    const int & getYear(){ return * p_year; }
private:
    int * p_day;
    int * p_month;
    int * p_year;

    QString * p_date;
};

#endif // PLANTDATE_H
