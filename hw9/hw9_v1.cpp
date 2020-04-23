#include<iostream>
using namespace std;
template <typename T>
void f(T){ cout<<"f(T)"<<endl; }
template <typename T>
void f(const T*){ cout<<"f(const T*)"<< endl; }
template <typename T>
void g(T){ cout<<"g(T)"<<endl; }
template <typename T>
void g(T*){ cout<<"g(T*)"<<endl; }
int main(){
    int a=1;
    int* b=&a;
    const int c=0;
    const int*d=&c;
    f(a);//f(T) int
    f(b);//f(T) int*
    f(c);//f(T) const int
    f(d);//f(const T*) int
    g(a);//g(T) int
    g(b);//g(T*) int
    g(c);//g(T) const int
    g(d);//g(T*) const int
}