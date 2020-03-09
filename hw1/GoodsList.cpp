#include "GoodsList.h"
#include <iostream>

Goods::Goods(string name, int nums)
{
    Goods::name = name;
    Goods::nums = nums;
}
Goods::~Goods()
{
}

void Goods::inc(int num)
{
    Goods::nums += num;
}
void Goods::dec(int num)
{
    Goods::nums -= num;
}

void Goods::inc()
{
    Goods::nums++;
}
void Goods::dec()
{
    Goods::nums--;
}

string Goods::get_name()
{
    return name;
}
int Goods::get_nums()
{
    return nums;
}
void Goods::set_name(string name)
{
    Goods::name = name;
}
void Goods::set_nums(int nums)
{
    Goods::nums = nums;
}

void Goods::show()
{
    cout << name << ',' << nums << endl;
}

GoodsList::GoodsList()
{
    sentinel = new GoodsList::Node;
    sentinel->goods = new Goods("sentinel", -1);
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    total = 0;
}
void GoodsList::show()
{
    GoodsList::Node *temp = GoodsList::sentinel->prev;

    while (temp != sentinel)
    {
        cout << temp->goods->get_name() << ',' << temp->goods->get_nums();
        temp = temp->prev;
        if(temp != sentinel) cout<<' ';
    }
    cout << endl;
}

int GoodsList::count()
{
    return total;
}

GoodsList::Node *GoodsList::test_in(string name)
{
    GoodsList::Node *temp = GoodsList::sentinel->next;
    while (temp!=sentinel)
    {
        if (name == temp->goods->get_name())
            return temp;
        temp = temp->next;
    }
    return sentinel;
}

void GoodsList::insert(Goods *goods)
{
    GoodsList::Node *cur;
    if ((cur = test_in(goods->get_name()))!=sentinel)
    {
        cur->goods->inc(goods->get_nums());
    }
    else
    {
        Node *new_node = new Node;
        new_node->next = sentinel->next;
        new_node->prev = sentinel;            
        sentinel->next->prev = new_node;
        sentinel->next = new_node;
        new_node->goods = new Goods(goods->get_name(), goods->get_nums());
        GoodsList::total++;
    }
}

void GoodsList::clear()
{
    GoodsList::Node *p = sentinel->next;
    while (p!=sentinel)
    {
        Node *q = p;
        p = p->next;
        delete q->goods;
        delete q;
    }
    sentinel->next = sentinel->prev = sentinel;
    GoodsList::total = 0;
}

void GoodsList::swap(Node* bar, Node* foo)
{
    Goods* p= bar->goods;
    bar->goods = foo->goods;
    foo->goods = p;
}


void GoodsList::remove(string name, int nums)
{
    GoodsList::Node *cur;
    if ((cur = test_in(name))!=sentinel)
    {
        if(cur->goods->get_nums()==nums)
        {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur->goods;
            delete cur;
            GoodsList::total--;
        }
        else if(cur->goods->get_nums()<nums)
        {   
            cout<<"Not enough goods!\n";
        }
        else
        {
            cur->goods->dec(nums);
        }
    }
    else
    {
        cout<<"Not enough goods!\n";
    }
    
}

void GoodsList::sort()//insertion sort
{
    if(total == 1|| total ==0) return;
    GoodsList::Node* cur = GoodsList::sentinel->next->next;
    if(total == 2)
    {
        if(sentinel->next->goods->get_nums()<cur->goods->get_nums())
        {
            swap(sentinel->next,cur);
        }
        return;
    }
	for (int i = 0; i < total - 1; i++)
	{
		GoodsList::Node* p = sentinel->next;
		for (int j = 0; j < total -i -1; j++)
		{
			if (p->goods->get_nums()>p->next->goods->get_nums())
			{
				swap(p,p->next);	
			}
			p = p->next;
		}
    }
}


GoodsList::~GoodsList()
{
    GoodsList::Node *p = sentinel;
    do
    {
        GoodsList::Node *q = p;
        p = p->next;
        delete q->goods;
        delete q;
    } while (p!=sentinel);
}


