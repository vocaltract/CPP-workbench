#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <stdexcept>
using namespace std;
class ExceptionTest
{
private:
    int prime[100];    //存前100个素数（质数）
public:
    //求分数，分子分母为a和b；分母为零异常
    double fraction(double a,double b);
    //求底数为10的对数，真数为a；真数为负异常
    double logarithm(double a);
    //求算出前100个素数，放在prime中，并写入文件；文件打开失败异常
    void calPrime(const char* address);
    //从prime中获取第i个素数；数组下标越界异常
    int getPrime(int i);
};

double ExceptionTest::fraction(double a, double b)
{
    try
    {
        if(b==0) throw runtime_error("ZeroDivision!");
        return a/b;
    }
    catch(runtime_error err)
    {
        cerr <<err.what()<<endl;
        abort();
    }
}

double ExceptionTest::logarithm(double a)
{
    try
    {
        if(a<=0) throw range_error("Negative log!");
        return log(a);
    }
    catch(range_error& e)
    {
        std::cerr << e.what() << '\n';
        abort();
    }
    
}

void ExceptionTest::calPrime(const char* address)
{
    int prime_num=0;
    int cur_num = 2;
    while(prime_num!=100)
    {
        bool is_prime = true;
        for(int i=2;i<cur_num;i++)
        {
            if(cur_num%i==0)
            {
                is_prime = false;
                break;
            }
        }
        if(is_prime)
        {
            prime[prime_num]=cur_num;
            prime_num++;
        }
        cur_num++;
    }
    try
    {
        fstream file(address,ios::app|ios::in);
        if(file.fail()) throw runtime_error("Can't open file!");
        for(int i=0;i<100;i++)
        {
            file<<prime[i]<<",";
            if(i%10==9) file<<endl;
        }
        file.close();
    }
    catch(runtime_error& e)
    {
        cerr << e.what() << '\n';
        abort();
    }

}

int ExceptionTest::getPrime(int i)
{
    try
    {
        if(!(0<=i&&i<=99)) throw invalid_argument("out of range!");
        return prime[i];
    }
    catch(invalid_argument& e)
    {
        cerr << e.what() << '\n';
        abort();
    }
}

int main()
{
    ExceptionTest a;
    a.fraction(1,0);
    a.calPrime("primes.txt");
}