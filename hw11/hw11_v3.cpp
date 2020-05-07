#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <regex>
#include <iomanip>
using std::string;
using std::vector;
using std::ios;
using std::cout;
using std::endl;
using std::cin;
using std::regex;
using std::smatch;
using std::setw;
#define BACKOFFSET (-(sizeof("ID:    ,Name:         ,Phone:         ,Post ID:        ,Address:              \n")-1))
class Worker
{
public:
    Worker(string ID,string name, string phone,string post,string address);
    string& get_id();
private:
    string _ID;
    string _name;
    string _phone;
    string _post;
    string _address;
friend std::ostream& operator <<(std::ostream& out, const Worker& x);
};
std::ostream& operator <<(std::ostream& out, const Worker& x)
{
    out.setf(ios::left);
    out<<"ID:"<<setw(4)<<x._ID;
    out<<",Name:"<<setw(9)<<x._name;
    out<<",Phone:"<<setw(9)<<x._phone;
    out<<",Post ID:"<<setw(8)<<x._post;
    out<<",Address:"<<setw(14)<<x._address;
    return out;
}

class AddressBook
{
public:
    AddressBook();
    ~AddressBook();
    void add(Worker &worker);
    Worker search(string id);
    void modify(Worker &worker);

private:
    std::fstream file;
    regex reg;
};



int main()
{
    Worker list[]=
    {
        {"1","Wang","150","123","Shanghai"},
        {"2","Li","139","123","Shanghai"},
        {"3","Zhao","110","321","Beijing"},
        {"4","Qian","189","101","Nanjing"},
        {"5","Sun","150","123","Shanghai"},                   
    };
    AddressBook book;
    for(int i=0;i<5;i++)
    {
        book.add(list[i]);
    }
    cout<<book.search("1")<<endl;
    Worker wgai("5","Liu","150","123","Shandong");
    book.modify(wgai);
    Worker wgai2("2","Kai","150","123","Tianjing");
    book.modify(wgai2);
    cout<<book.search("2")<<endl;
    cout<<book.search("10")<<endl;
}

Worker::Worker(string ID,string name, string phone,string post,string address)
    :_ID(ID),_name(name),_phone(phone),_post(post),_address(address){}

string& Worker::get_id()
{
    return _ID;
}

AddressBook::AddressBook()
    :reg("ID:([0-9]+) {0,10},Name:([A-Za-z]+) {0,10},Phone:([0-9]+) {0,10},Post ID:([0-9]+) {0,10},Address:([A-Za-z]+) {0,10}")
{ 
   file.open("workers.txt",ios::out|ios::in);
   if(!file.is_open())
   {
        file.open("workers.txt",ios::out);
        assert(file.is_open());
        file.close();
        file.open("workers.txt",ios::out|ios::in);
        assert(file.is_open());
   }
}

AddressBook::~AddressBook()
{
    assert(file.is_open());
    file.close();
}

void AddressBook::add(Worker &worker)
{
    file<<worker<<endl;
}

Worker AddressBook::search(string id)
{
    string buf;
    file.seekg(ios::beg);
    getline(file,buf);
    smatch sm;
    while(!file.eof())
    {
        if(regex_search(buf,sm,reg))
        {
            if(sm[1]==id)
            {
                return (Worker){sm[1],sm[2],sm[3],sm[4],sm[5]};
            }
        }
        buf.clear();
        getline(file,buf);
    }
    file.seekg(ios::end);
    cout<<"No this worker!"<<endl;
    return (Worker){"","","","",""};
}

void AddressBook::modify(Worker &worker)
{
    string buf;
    file.seekg(ios::beg);
    getline(file,buf);
    smatch sm;
    while(!file.eof())
    {
        if(regex_search(buf,sm,reg))
        {
            if(sm[1]==worker.get_id())
            {
                file.seekg(BACKOFFSET,ios::cur);
                file<<worker;
                file.seekg(ios::end);
                return;
            }
        }
        buf.clear();
        getline(file,buf);
    }
    file.seekg(ios::end);
    cout<<"No this worker!"<<endl;    
}