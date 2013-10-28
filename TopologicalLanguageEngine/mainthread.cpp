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
    Set<char>* p_test; p_test = new Set<char>;
    p_test->add(new char('a')); p_test->add(new char('b')); p_test->add(new char('3'));
    Set<char>* p_tset; p_tset = new Set<char>;
    p_tset->add(new char('e')); p_tset->add(new char('3')); p_tset->add(new char('4'));

    Set<char>* p_insctn = new Set<char>;
    Set<char>* p_union = new Set<char>;
    Set<char> insctn = ((*p_test) * (*p_tset));
    Set<char> unon = ((*p_test) + (*p_tset));

    p_insctn = &insctn; p_union = &unon;
    print(p_test); print(p_tset);

    std::cout<<"The sets are of type: " << unon.getType().toStdString().c_str() << "\n";
    std::cout<<"The intersection is: ";
    print(p_insctn);
    std::cout<<"The union is: ";
    print(p_union);
    Q_EMIT finished();
}//test method
