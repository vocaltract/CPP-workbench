#include <iostream>
using namespace std;
class A
{
public:
    A(){cout<<"A()"<<endl;}
    ~A(){cout<<"~A()"<<endl;}
};

class Base
{
public:
    Base(){cout<<"Base()"<<endl;}
    ~Base(){cout<<"~Base()"<<endl;}
};

class Derive:public Base
{
public:
    Derive(){cout<<"Derive()"<<endl;}
    ~Derive(){cout<<"~Derive()"<<endl;}
    Derive(const Derive& testDerive)
    {
        cout<<"Derive(const Derive&)"<<endl;
    }
    Derive& operator=(const Derive& testDerive)
    {
        cout<<"Derive& operator=(const Derive& testDerive)"<<endl;
        return *this;
    }
private:
    A a;
};

Derive testFunc()
{
    Derive d1;
    Derive d2(d1);
    return d2;
}

int main()
{
    Derive* d3 = new Derive();
    delete d3;
    Derive d4;
    d4 = testFunc();
    return 0;
}


