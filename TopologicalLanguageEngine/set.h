#ifndef SET_H
#define SET_H

#include <functional>
#include <QList>
#include <QString>
#include <QStringList>
#include <type_traits>
#include <exception>
#include <iostream>

template<typename T>
class Set {
public:
    //constructors
    Set();
    ~Set(){ delete []pType; }

    //functions
    const int & size(){ return m_size; }

    void add(const T * singleton);

    void empty();

    //operators
    inline T& operator [](int index){ return pType[index]; }

    template<class Y>
    friend Set<Y> operator *(const Set<Y>& s1, const Set<Y>& s2);//intersection
    template<class Y>
    friend Set<Y> operator *(Set<Y>& s1, Set<Y>& s2);
    template<class Y>
    friend Set<Y> operator +(const Set& s1, const Set& s2);//union
    template<class Y>
    friend Set<Y> operator +(Set& s1, Set& s2);//union
    template<class Y>
    friend Set operator -(const Set& s1, const Set& s2);//relative complement

    bool operator =(const Set& other)
    {
        delete []pType;//empty out the array

        /** Gets operator **/
        int x = other.size();
        pType = new T[x];
        for (int y = 0; y < x; y++)
            pType[y] = other[y];

        m_size = x;

        return true;
    }

    bool operator ==(const Set & other)
    {
        if(other.size() != size())
            return false;
        else
        {
            for (int x = 0; x < size(); x++)
                if (!other.has(pType[x]))
                    return false;
        }//end else
        return true;
    }//end equals operator

    bool operator >(const Set &other)
    {
        for (int x = 0; x < other.size(); x++)
            if (!has(other[x]))
                return false;
    }//superset operation
    \
    bool operator <(const Set &other)
    {
        for (int y = 0; y < m_size; y++)
            if (!other.has(pType[y]))
                return false;
    }//subset operation

    Set& complement();
    bool isEmpty(){ return m_size == 0; }
    bool has(T* element);
    bool has(T element);
    QString toString(int index);

private:
    T * pType;
    T * m_Type; //save the variable type.
    QStringList m_log;
    int m_size;
};

#endif // SET_H
