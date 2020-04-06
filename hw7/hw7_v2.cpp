#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Animal
{
public:
    virtual void sound()=0;
    void show();
    Animal();
    Animal(string name, double weight);
private:
    string name;
    double weight;
};


class Dog:public Animal
{
public:
    Dog(string name, double weight)
        : Animal(name,weight)
    {        
    }
    void sound()
    {
        cout<< "woof woof woof!"<<endl;
    }
};

class Cat:public Animal
{
public:
    Cat(string name, double weight)
        : Animal(name,weight)
    {        
    }
    void sound()
    {
        cout<< "mew~"<<endl;
    }    
};

class Cow:public Animal
{
public:
    Cow(string name, double weight)
        : Animal(name,weight)
    {        
    }
    void sound()
    {
        cout<< "mooooooooo"<<endl;
    }    
};

void Animal::show()
{
    cout<<"Name:"<<name<<endl;
    cout<<"Weight:"<<weight<<endl;
}

Animal::Animal(string n, double w)
{
    name = n;
    weight = w;
}

Animal::Animal()
{
    name = "Not initialized!";
    weight = 0;    
}

