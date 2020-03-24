#include "polynomial.h"
#include <iostream>
Polynomial::Polynomial()
{
    max = 1;
    paras[max] = 0;
}
//Polynomial类的拷贝构造函数
Polynomial::Polynomial(const Polynomial &p)
{
    max = p.max;
    for (int i = 0; i < max; i++)
    {
        paras[i] = p.paras[i];
    }
}
//输入参数向量w构造多项式,n为w的长度,等于最高次幂+1,w[i]是x的i次幂的参数
//如f(x)=1+x+x^2+x^3时,w={1,1,1,1},n=4
Polynomial::Polynomial(const double w[], const int n)
{
    for (int i = 0; i < 101; i++)
    {
        if (i < n)
            paras[i] = w[i];
        else
        {
            paras[i] = 0;
        }
    }
    max = n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (paras[i] == 0)
            max--;
        else
        {
            break;
        }
    }
}
Polynomial Polynomial::operator+(const Polynomial &p) const
{
    int new_max = p.get_max() > max ? p.get_max() : max;
    double *arr = new double[new_max];
    for (int i = 0; i < new_max; i++)
    {
        arr[i] = paras[i] + p.paras[i];
    }
    for (int i = new_max - 1; i >= 1; i--)
    {
        if (arr[i] == 0)
            new_max--;
        else
        {
            break;
        }
    }
    Polynomial a(arr, new_max);
    delete[] arr;
    return a;
}

int Polynomial::get_max() const
{
    return max;
}

//重载*运算符
Polynomial Polynomial::operator*(const Polynomial &p) const
{
    int new_max = p.max + max - 1;
    double *arr = new double[new_max];
    for (int i = 0; i < new_max; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < new_max; i++)
    {

        for (int j = 0; j < max; j++)
        {
            if (j > i)
                break;
            for (int k = 0; k < p.max; k++)
            {
                if (j + k > i)
                    break;
                if (i == j + k)
                {
                    arr[i] += p.paras[k] * paras[j];
                }
            }
        }
    }
    for (int i = new_max - 1; i >= 1; i--)
    {
        if (arr[i] == 0)
            new_max--;
        else
        {
            break;
        }
    }

    Polynomial res(arr, new_max);
    delete[] arr;
    return res;
}
//重载()运算符,实现函数复合
Polynomial Polynomial::operator()(const Polynomial &p) const
{
    double inttemp = 0;
    Polynomial res(&inttemp, 1);
    for (int i = max - 1; i >= 0; i--)
    {
        res = p * res;
        //res.display();
        Polynomial temp(&paras[i], 1);
        res = temp + res;
        //res.display();
        //std::cout << std::endl;
    }
    return res;
}
//重载()运算符,实现函数值计算
double Polynomial::operator()(double x) const
{
    double res = 0;
    for (int i = max - 1; i >= 0; i--)
    {
        res *= x;
        res += paras[i];
    }
    return res;
}
//求函数在x处的导数
double Polynomial::derivative(double x) const
{
    double *arr = new double[max - 1];
    for (int i = 1; i < max; i++)
    {
        arr[i - 1] = i * paras[i];
    }
    Polynomial res(arr, max - 1);
    delete[] arr;
    return res(x);
}

Polynomial operator*(double x, const Polynomial &p)
{
    double *arr = new double[p.max];
    for (int i = 0; i < p.max; i++)
    {
        arr[i] = p.paras[i] * x;
    }
    Polynomial temp(arr, p.max);
    delete[] arr;
    return temp;
}

void Polynomial::display() const
{
    for (int i = 0; i < max; i++)
    {
        std::cout << paras[i] << ",";
    }
    std::cout << std::endl;
}