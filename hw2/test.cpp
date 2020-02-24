#include "GoodsList.h"
#include <iostream>
int main()
{
GoodsList list;
/*Goods* good1 = new Goods("apple",500);
Goods* good2 = new Goods("pear",100);
Goods* good3 = new Goods("peach",150);*/

Goods* good1 = new Goods("apple",500);
Goods* good2 = new Goods("pear",100);
Goods* good3 = new Goods("peach",150);
Goods* good4 = new Goods("chick",100);
Goods* good5 = new Goods("duck",100);
Goods* good6 = new Goods("tower",120);
list.sort();
list.insert(good5);
list.insert(good5);
list.insert(good1);
list.insert(good2);
list.insert(good2);
list.show();
list.sort();
list.show();
list.remove("as",21);
list.remove("apple",500);
list.show();
list.insert(good3);
list.insert(good4);
list.show();
list.sort();
list.show();
cout<<list.count()<<endl;
list.clear();
list.show();
cout<<list.count()<<endl;

}
