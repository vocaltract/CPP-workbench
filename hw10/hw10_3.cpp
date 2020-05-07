#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <map>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
#define ADT deque
class Book
{
public:
    Book(string name, string author,int year, int ID, int num);
    int get_num() const; 
    int get_ID() const;
    int get_year() const;
    void display() const;
    void display_year() const;
    const string& get_author() const;   
private:
    string _name,_author;
    int _year;
    int _ID;
    int _num;
};
Book::Book(string name, string author,int year, int ID, int num)
{
    _name = name;
    _author = author;
    _year = year;
    _ID = ID;
    _num = num;
}
int Book::get_num() const
{
    return _num;
}
int Book::get_ID() const
{
    return _ID;
}  

const string& Book::get_author() const
{
    return _author;
}
void Book::display() const
{
    cout<<"author:"<<_author<<" book name:"<<_name<<" num:"<<_num;
    cout<<" year:"<<_year<<" ID:"<<_ID<<endl;
}
int Book::get_year() const
{
    return _year;
}
void Book::display_year() const
{
    cout<<"Year:"<<_year<<endl;
}

class MatchAuthor
{
public:
    MatchAuthor(const string& author)
    {
        _author = author;
    }
    void operator()( Book& bk)
    {
        if(bk.get_author()==_author)
        {
            bk.display();
        }
    }
private:
    string _author;
};

bool cmp_year(Book& bk1,Book bk2)
{
    return bk1.get_year()>bk2.get_year();
}

void display(Book& bk)
{
    bk.display();
}

class Machine
{
public:
    Machine();
    void addBook(int num,const string& name,const string& author,int year);
    void deleteBook(int ID);
    int _getID();
    void display_with_year();
    void find(const string& author);
    void _freeID(int id);
private:
    ADT<Book> books;
    stack<int> available_IDs;//书被删除后重新加入需要新的ID
    int max_id;
};
Machine::Machine()
{
    max_id=-1;
}
void Machine::deleteBook(int ID)
{
    ADT<Book>::const_iterator it = books.begin();
    while(it!=books.end())
    {
        if((it->get_ID())==ID)
        {
            books.erase(it);
            _freeID(ID);
            return;
        }
        it++;
    }
    cout<<"No this book!"<<endl;
}

void Machine::find(const string& author)
{
    for_each(books.begin(),books.end(),MatchAuthor(author));
}

void Machine::display_with_year()
{
    sort(books.begin(),books.end(),cmp_year);
    for_each(books.begin(),books.end(),display);
}

void Machine::addBook(int num,const string& name,const string& author,int year)
{
    books.push_back((Book){name,author,year,_getID(),num});
}


int Machine::_getID()
{
    if(available_IDs.empty())
    {
        max_id++;
        return max_id;
    }
    int tmp = available_IDs.top();
    available_IDs.pop();
    return tmp;
}
void Machine::_freeID(int id)
{
    available_IDs.push(id);
}




int main()
{
    Machine my_library;
    clock_t st=clock();
    for(int i=0;i<120;i++)
    {
        my_library.addBook(i,"test","Dad",i+100);
        my_library.addBook(i,"see","wang",123);
        my_library.addBook(i,"Pig","Chen",11);
    } 
    for(int i=0;i<50;i++)
    {
        my_library.deleteBook(i);
    }
    for(int i=0;i<10;i++)
    {
        my_library.addBook(i,"test2","Kitty",10);
        my_library.addBook(i,"see2","wang",123);
        my_library.addBook(i,"Pig2","Chen",11);
    }
        for(int i=100;i<120;i++)
    {
        my_library.deleteBook(i);
    } 
    my_library.find("Chen");
    my_library.display_with_year();
    cout<<"Time consumption:"<<(double)(clock()-st)/CLOCKS_PER_SEC<<endl;
}










