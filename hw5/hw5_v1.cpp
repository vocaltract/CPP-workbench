#include <cassert>
class Fib
{
public:
    Fib(int index);
    Fib();
    int operator()();


private:
    int last;
    int cur;

};


Fib::Fib(int index)
{
    assert(index >= 1);
    last = 0;
    cur = 1;
    for (int i = 1; i < index; i++)
    {
        int temp = last + cur;
        last = cur;
        cur = temp;
    }
}

Fib::Fib()
{
    last = 0;
    cur = 1;
}

int Fib::operator()()
{
    int temp = last + cur;
    last = cur;
    cur = temp;
    return cur;
}
