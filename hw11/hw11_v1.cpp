#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.141592653589
int main()
{
    cout.setf(ios::left);
    cout<<setw(3)<<"x";
    cout<<setw(10)<<"sin(x)"<<setw(10)<<"cos(x)"<<setw(10)<<"tan(x)"<<endl;
    for(int i=1;i<=10;i++)
    {
        cout<<setw(3)<<i;
        cout<<setw(10)<<setiosflags(ios::fixed)<<setprecision(5)<<sin((double)i/180*PI);
        cout<<setw(10)<<setiosflags(ios::fixed)<<setprecision(5)<<cos((double)i/180*PI); 
        cout<<setw(10)<<setiosflags(ios::fixed)<<setprecision(5)<<tan((double)i/180*PI);              
        cout<<endl;
    }
}