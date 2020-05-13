#include <iostream>
using namespace std;
int main()
{
    int n,*p;
    cin>>n;
    L1:
    try
    {
        p = new int[n];
        if(!p) throw runtime_error("Malloc Failed!");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        goto L1;
    }
    delete[] p;
    L2:
    try
    {
        max(NULL,10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    



}

int max(int x[],int num)//p131
{
    int max_index =0;
    if(!x) throw runtime_error("NULL point!");
    for(int i=1;i<num;i++)
    {
        if(x[i]>x[max_index]) max_index = i;
    }
    return max_index;
}

