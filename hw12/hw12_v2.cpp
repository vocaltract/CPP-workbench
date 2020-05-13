#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Web
{
public:
    void inputName();
    void inputAge();
    void inputPhone();
    void uploadFile();
    void enroll();
private:
    string name;
    int age;
    string phone;
    string address;
};

void Web::enroll()
{
    inputName();
    inputAge();
    L1:
    try
    {
        inputPhone();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        goto L1;
    }
    L2:
    try
    {
        uploadFile();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        goto L2;
    }   
    
}

void Web::inputName()
{
    cout<<"Input your name.End with ENTER"<<endl;
    getline(cin,name);
}

void Web::inputAge()
{
    cout<<"Input your Age.End with ENTER"<<endl;
    string age_buf;
    getline(cin,age_buf);
    age = stoi(age_buf);
    if(age<11 || age>18)
    {
        cerr<<"Inappropriate age!"<<endl;
        abort();
    }
}

void Web::inputPhone()
{
    cout<<"Input your Phone Number.End with ENTER"<<endl;
    getline(cin,phone);
    for(char s:phone)
    {
        if(!((s>='0'&&s<='9')||s=='-')) 
            throw runtime_error("Inappropriate phone!");
    } 
}

 void Web::uploadFile()
 {
    cout<<"Input your Article Address.End with ENTER"<<endl;
    getline(cin,address);
    fstream file(address,ios::in);
    if(file.fail()) throw runtime_error("Something wrong with your address!");
    //pretends to have some operation
    //as no format is given, I can't do anything.
    file.close();
 }

int main()
{
    Web myweb;
    myweb.enroll();
}