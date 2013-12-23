#include "plantdate.h"

PlantDate::PlantDate(int _day, int _month, int _year)
{
    p_day = new int(_day);
    p_month = new int(_month);
    p_year = new int(_year);

    p_date = new QString();
    QString day; day.setNum(*p_day);
    QString year; year.setNum(*p_year);
    QString date = day + getMonthName() + year;
    p_date = &date;
}//construct the object.

/** Operators **/
TimeDuration operator-(PlantDate t1, PlantDate t2)
{
    /** The first thing we do is convert everything to days.
     * There are 365 days in a year, and 366 days in a leap year. **/

    int t1_days = 0; int t1_years = t1.getYear() - 1;
    int t2_days = 0; int t2_years = t2.getYear() - 1;

    if (t1_years != t2_years)
    {
        while (t1_years >= 0)
        {
            if (t1_years % 4 == 0)
                t1_days += 366; //leap year
            else
                t1_days += 365;

            t1_years--;
        }//end while

        while (t2_years >= 0)
        {
            if (t2_years % 4 == 0)
                t2_days += 366; //leap year
            else
                t2_days += 365;

            t1_years--;
        }//end while
    }//don't do this if it's stupid to.
    t1_years = t1.getYear() - 1; t2_years = t2.getYear() - 1;

    if (t1.getMonth() != t2.getMonth() && t1.getYear() != t2.getYear()) //don't do this if you don't need to!
    {
        /**
          January = 31          July = 31
          February = 28 (29)    August = 31
          March = 31            September = 30
          April = 30            October = 31
          May = 31              November = 30
          June = 30             December = 31 **/

        bool leap1 = t1_years % 4 == 0; bool leap2 = t2_years % 4 == 0;

        const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//make an array
        const int days_leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for (int x = 11; x >= 0; x--)
        {
            if (!leap1)
                t1_days += days[x];
            else
                t1_days += days_leap[x];
        }//loop through and add days for months

        for (int y = 11; y >= 0; y--)
        {
            if (!leap2)
                t2_days += days[y];
            else
                t2_days += days_leap[y];
        }//see above loop comment
    }//do the math for days

    t1_days += t1.getDay(); t2_days += t2.getDay();
    int diff = (t1_days > t2_days) ? t1_days - t2_days : t2_days - t1_days;
    TimeDuration temp(diff);
    return temp;
}//addition operator
