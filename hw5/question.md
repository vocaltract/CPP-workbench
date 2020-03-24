概念题

1. C++中Lambda表达式的语法形式是怎样的？Lambda表达式有什么优点？

2. C++中类成员访问运算符 -> 可以用于实现"智能指针"的功能。与正常指针相比，"智能指针"有哪些特点？


编程题

1. 斐波那契数列是指：从数列的第3项开始，每一项都等于前两项之和(其中第一项和第二项都为1)。如下所示：

1，1， 2，3，5，8，13...

请使用函数对象设计程序，该程序满足：(1)可以获得斐波那契数列每项的值，每调用一次返回队列中下一个元素的值；(2)程序中可以同时使用多个序列；(3)可以通过构造函数指定具体数列项的起始位置，比如：fib(10)将以斐波那契数列第10项的值作为数列的初始值。请完成程序并验证其正确性。


2. 现有一程序，其输入参数是一个圆(由圆心和半径表示)，它可以判断给定的两个点，是否一个在圆外部，一个在圆内部。请对下列代码填空，使其完成以上功能：


struct Point

{

    int x;

    int y;

};


bool IsTrue(Point &rstCenter, int iRadius, Point &P1, Point &P2)

{

    # 在这里补充你的代码

    return PointInCircle(P1) != PointInCircle(P2);

}


3. 一个没有安全防护的网站A里有一系列小工具（f1，f2，…）可访问。客户端B的日志记录着最近一次访问的时间。请运用智能指针类的知识实现B。

要求: 

 （1）B类记录着最近访问时间；

 （2）B用函数string_access来获得最近访问时间；

 （3）函数visit可以访问网站A；

 （4）可以保证以下代码正常运行并得到正确结果：

    B b; 

    visit(b); 

    cout << b.string_access() << endl; 


备注：

1. A类的实现：

class A{

public:

    void f1(){}

    void f2(){}

    void f3(){}

    void f4(){}

}；

2. 所需头文件：<time.h> 、<string>

    获得系统当前时间并转化为string的代码:

time_t now_time=time(NULL);

string last_time =asctime(localtime(&now_time));