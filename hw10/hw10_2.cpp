#include <iostream>
#include <string>
#include <map>
using std::endl;
using std::cout;
using std::map;
using std::string;
class System
{
public:
    System();
    void record(string name, int num);
    void del(string name);
    int animal_num(string name);
    int _kinds();
    int _total();
private:
    map<string,int> animals;
    int kinds_of_animals;
    int total;
};

System::System()
{
    kinds_of_animals=0;
    total=0;
}
void System::record(string name, int num)
{
    map<string,int>::iterator it = animals.find(name);
    cout<<"Record successfully!";
    if(it!=animals.end())
    {
        animals[name] += num;
        cout<<"Existed before."<<endl;
    }
    else
    {
        animals[name] = num;   
        cout<<"Not Existed before."<<endl;
        kinds_of_animals++;
    }
    total+=num;
}
void System::del(string name)
{
    map<string,int>::iterator it = animals.find(name);
    if(it!=animals.end())
    {
        total -= animals[name];
        kinds_of_animals--;
        animals.erase(name); 
        cout<<"Delete successfully"<<endl;
    }
    else
    {
        cout<<"Deletion failed!Not Existed"<<endl;
    }
    // if(animals.erase(name)) cout<<"Delete Successfully"<<endl;
    // else cout<<"Delete Failed! Animal not exists."<<endl;
}

int System::animal_num(string name)
{
    map<string, int>::const_iterator it = animals.find(name);
    if(it!=animals.end())
    {
        return animals[name];
    }
    else
    {
        return 0;
    }
}

int System::_kinds()
{
    return kinds_of_animals;
}
int System::_total()
{
    return total;
}
