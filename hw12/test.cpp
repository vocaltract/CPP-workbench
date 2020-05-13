#include <iostream>
#include <string>
using namespace std;
int main()
{
    string buf;
 //   buf.resize(100);
    cout<<"First"<<endl;
    getline(cin,buf);
    cout<<"buf:"<<buf<<endl;
    //cin.ignore();
    cout<<"Second"<<endl;
    //cin>>buf;
    getline(cin,buf);
    cout<<"buf:"<<buf<<endl;

 //   string name;

//   cout << "Please, enter your full name: ";
//   getline (std::cin,name);
//   cout << "Hello, " << name << "!\n";

  return 0;
}