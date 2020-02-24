#include <string>
using namespace std;
class Goods
{
private:
  string name;
  int nums;

public:
  Goods(string name, int nums);
  void inc();
  void inc(int num);
  void dec();
  void dec(int num);
  void show();
  string get_name();
  int get_nums();
  void set_nums(int nums);
  void set_name(string name);
  ~Goods();
};

class GoodsList
{
private:
  struct Node
  {
    Goods *goods;
    Node *prev;
    Node *next;
  } *sentinel;
  int total;
public:
  GoodsList();
  void insert(Goods *goods);
  void remove(string name, int nums);
  void show();
  void sort();
  Node* test_in(string name);
  int count();
  void clear();
  void swap(Node* bar, Node* foo);
  ~GoodsList();
};
