#include <iostream>
using namespace std;
class A
{
public:
    A(const char*s)
    {
        cout<<s<<endl;
    }
    ~A()
    {
        cout<<"destructor of A"<<endl;
    }
};  

class B: virtual public A
{
public:
    B(const char*s1, const char*s2):A( s1 )
    {
        cout<<s2<<endl;
    }
    ~B()
    {
        cout<<"destructor of B"<<endl;
    }
};

class C: virtual public A
{ 
public:
    C(const char*s1, const char*s2):A(s1)
    {
        cout<<s2<<endl;
    }
    ~C()
    {
        cout<<"destructor of C"<<endl;
    }
};

class D: public B, public C
{
public:
    D(const char*s1, const char*s2, const char*s3, const char*s4)
        :B(s1,s2),C(s1,s3),A(s1)
    {
        cout<<s4<<endl;
    }
    ~D()
    {
        cout<<"destructor of D"<<endl;
    }
};

int main()
{
    D* ptr=new D("string1","string2","string3","string4");
    delete ptr;
}