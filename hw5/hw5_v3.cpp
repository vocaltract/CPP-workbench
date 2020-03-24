#include <time.h>
#include <string>
using std::string;
class A
{
public:
    void f1(){}
    void f2(){}
    void f3(){}
    void f4(){}
};

class B
{
public:
    B(A* p);
    string string_access() const;
    A* operator->();
private:
    string last_time;
    A* p_a;
};

B::B(A* p)
{
    last_time = "No Access!";
    p_a = p;
}

string B::string_access() const
{
    return last_time;
}

A* B::operator->()
{
    time_t now_time=time(NULL);
    last_time =asctime(localtime(&now_time));
    return p_a;
}

