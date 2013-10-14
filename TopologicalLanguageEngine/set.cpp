#include "set.h"
template<typename Y>
Set<Y>::Set()
{
    m_size = 0;
    m_Type = new Y();//save a default value
    pType = new Y[0];//Make the array
}//create an empty set

template<class T>
void Set<T>::empty()
{ delete []pType; }

template<class T>
bool Set<T>::has(T *element)
{
    for (int x = 0; x < size(); x++)
        if (pType[x] == *element)
            return true;
    return false;
}//check if element is in our set

template<class T>
bool Set<T>::has(T element)
{
    for (int x = 0; x < size(); x++)
        if (pType[x] == element)
            return true;
    return false;
}//end has (for non-pointer)

template<typename T>
void Set<T>::add(const T *singleton)
{
    const int size = m_size + 1;
    T temp[size];//copy the data

    for (int x = 0; x < m_size; x++)
        temp[x] = pType[x];

    delete []pType;
    pType = new T[size];
    for (int x = 0; x < m_size; x++)
        pType[x] = temp[x];
    pType[m_size] = *singleton;//add the new element
    m_size ++;//add one to size;
}//add a new element to the set.

class out_of_bounds: public std::exception
{
  virtual const char* what() const throw()
  {
    return "ERROR: INDEX OUT OF BOUNDS.";
  }
};//handle out of bounds exception

template<typename T>
QString Set<T>::toString(int index)
{
    QString temp;
    temp.setNum(pType[index]);
    return temp;
}//get a string for a single index.

/** Operators **/
template<typename T>
Set<T> operator *(const Set<T>& s1, const Set<T>& s2)
{
    /** This is the intersection operator **/
    Set<T> * temp = new Set<T>();

    for (int x = 0; x < s1.size(); x++)
    {
        if (s2.has(s1[x]))
            temp->add(&s1[x]);
    }
    return *temp;
}//find the intersection of two sets

template<class T>
Set<T> operator *(Set<T>& s1, Set<T>& s2)
{
    /** This is the intersection operator **/
    Set<T> * temp = new Set<T>();

    for (int x = 0; x < s1.size(); x++)
    {
        if (s2.has(s1[x]))
            temp->add(&s1[x]);
    }
    return *temp;
}//find the intersection of two sets.

template<class T>
Set<T> operator +(Set<T>& s1, Set<T> s2)
{
    /** This is the union operator **/
    Set<T> * temp = new Set<T>();

    for (int x = 0; x < s1.size(); x++)
    {
        if (!s2.has(s1[x])) //so we don't count twice
            temp->add(&s1[x]);
    }//end for

    for (int y = 0; y < s2.size(); y++)
        temp->add(&s2[y]);

    return *temp;
}//find the union of two sets.
