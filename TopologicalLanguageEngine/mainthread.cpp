#include "mainthread.h"

template<typename Y>
void MainThread::print(Set<Y> * s)
{
    std::cout<<"{";
    for (int x = 0; x < s->size(); x++)
    {
        std::cout<<s->toString(x).toStdString().c_str();
        if (x != s->size() - 1){ std::cout<<", "; }//end if
    }//end for

    std::cout<<"}\n";
}//print out a set

void MainThread::run()
{
    Set<int>* p_test; p_test = new Set<int>;
    p_test->add(new int(9)); p_test->add(new int(2)); p_test->add(new int(3));
    Set<int>* p_tset; p_tset = new Set<int>;
    p_tset->add(new int(2)); p_tset->add(new int(3)); p_tset->add(new int(4));

    Set<int>* p_insctn = new Set<int>;
    Set<int>* p_union = new Set<int>;
    Set<int> insctn = ((*p_test) * (*p_tset));
    Set<int> unon = ((*p_test) + (*p_tset));

    p_insctn = &insctn; p_union = &unon;
    print(p_test); print(p_tset);

    std::cout<<"The intersection is: ";
    print(p_insctn);
    std::cout<<"The union is: ";
    print(p_union);
    Q_EMIT finished();
}//test method
