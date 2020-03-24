class Polynomial
{
public:
Polynomial();
Polynomial(const Polynomial& p);
//输入参数向量w构造多项式,n为w的长度,等于最高次幂+1,w[i]是x的i次幂的参数
//如f(x)=1+x+x^2+x^3时,w={1,1,1,1},n=4

Polynomial(const double w[],const int n);
//重载+运算符
Polynomial operator+(const Polynomial& p)const;
//重载*运算符
Polynomial operator*(const Polynomial& p)const;
//重载()运算符,实现函数复合
Polynomial operator()(const Polynomial& p)const;
//重载()运算符,实现函数值计算
void display() const;

friend Polynomial operator*(double x, const Polynomial& p);


double operator()(double x) const;
//求函数在x处的导数
double derivative(double x) const;
int get_max() const;
private:
    int max;
    double paras[101];

};