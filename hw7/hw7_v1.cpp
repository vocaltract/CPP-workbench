#include <iostream>
using namespace std;

#ifdef QUESTION1
class Base
{
public:
    int bar(char x)
    {
        return (int)(x);    
    }
    virtual int bar (int x)
    {
        return (2*x);    
    }
};

class Derived:public Base
{
public:
    int bar(char x)
    {
        return (int)(-x);    
    }
    int bar(int x)
    {
        return (x/2);
    }
};

int main()
{
    Derived Obj;
    Base*pObj=&Obj;
    cout<<pObj->bar((char)(100)) <<endl;
    cout<<pObj->bar(100) <<endl;
}
#else
#include <iostream>
using namespace std;
class A
{   
    int a;
public:
    A():a(5){}
    virtual void print() const
    {
        cout<<a<<endl;
    }
};
class B: public A
{ 
    char b;
public:
    B()    
    {
        b='E';    
    }
    void print()const
    {
        cout<<b<<endl;    
    }
};
void show(A&x) {x.print();}

int main()
{
    A d1,*p;
    B d2;
    p=&d2;
    d1.print();
    d2.print();
    p->print();
    show(d1);
    show(d2);
    return 0;
}

#endif