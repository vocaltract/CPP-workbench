#include <iostream>
#include <string>
using namespace std;
template <class T> 
class Node
{
public:
    Node(){next=NULL;}
    T& val(){return value;}
    Node*& pnext(){return next;}
private:
    T value;
    Node *next;
};

template<class T>
class List
{
public:
    List()
    {
        head=NULL;
        tail=NULL;
    }
    ~List()
    {
        Node<T> *tmp =head;
        if(!tmp)
        {
            Node<T> *tmp2=tmp;
            tmp = tmp->pnext();
            delete tmp2;
        }
    }
    void add(T val)
    {
        if(head!=NULL)
        {
            tail->pnext() = new Node<T>;
            tail->pnext()->val()=val;
            tail = tail->pnext();
        }
        else
        {
            tail = new Node<T>;
            tail->val()=val;
            head=tail;   
        }
    }
    void display()
    {
        if(head!=NULL)
        {
            Node<T> *tmp = head;
            while(tmp!=NULL)
            {
                cout<<tmp->val()<<" ";
                tmp = tmp->pnext();
            }
        }
        
    }

private:
    Node<T> *head,*tail;
};

int main()
{
    List<int> mylist;
    mylist.add(21);
    mylist.add(12);
    mylist.display();
    cout<<endl;
    List<double> mylist2;
    mylist2.add(1.2);
    mylist2.add(2.1);
    mylist2.display();
    cout<<endl;
    List<string> mylist3;
    mylist3.add("abd");
    mylist3.add("adadada");
    mylist3.display();
}