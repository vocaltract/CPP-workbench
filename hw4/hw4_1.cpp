#include <iostream>
using namespace std;
class A
{
public:
    int x;
    int *p;
    A()
    {
        p = new int(0);
        x = 0;
    }

    A& operator = (const A& a)
    {
        if(&a==this) return *this;
        x = a.x;
        delete p;
        p = new int(*a.p);
        return *this;
    }

    A& operator =(A&& a)
    {
        if(&a == this) return *this;
        x = a.x;
        delete p;
        p = new int(*a.p);
        a.p = NULL;
        return *this;
    }

    A(int m, int n)
    {
        p = new int(n);
        x = m;
    }
    ~A()
    {
        delete p;
        x = 0;
    }


};

int main()
{
    A a1(6, 8);
    A a2;
    a2 = a1;
    cout << "a1.x = " << a1.x << ", "
         << "*(a1.p) = " << *(a1.p) << endl;
    cout << "a2.x = " << a2.x << ", "
         << "*(a2.p) = " << *(a2.p) << endl;
    cout << "a1.p = " << a1.p << endl;
    cout << "a2.p = " << a2.p << endl;
    return 0;
}