#include <iostream>
#include <string>
using std::string;
class StrOperation
{
private:
    string str;
public:
    StrOperation(string s);
    bool judgePalindrome();
    void insertStr(int i,string s);
    void replaceStr(int be,int en,string s);
};

StrOperation::StrOperation(string s)
{
    str = s;
}
bool StrOperation::judgePalindrome()
{
    string::const_iterator be = str.begin(),ed = str.end();
    ed--;
    while(be!=ed&&be!=ed+1)
    {
        if(*be!=*ed)
        {
            return false;
        }
        be++;
        ed--;
    }
    return true;
}
void StrOperation::insertStr(int i,string s)
{
    str.insert(i,s);
}
void StrOperation::replaceStr(int be,int en,string s)
{
    str.replace(be,en,s);
}
