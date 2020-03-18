#include<iostream>
#include<cstring>
class String
{

public:
    String()
    {
        str=NULL;
        str_len = 0;
    }
    String(char* s)
    {
        str_len =strlen(s); 
        str = new char[str_len+1];
        strcpy(str,s);
    }
    char& operator[](int i)
    {
        return i>=str_len?str[str_len-1]:str[i];   
    }
    String& operator=(const String& s)
    {
        if(&s==this) return *this;
        delete[] str;
        str_len = s.str_len;
        str = new char[str_len+1];
        strcpy(str,s.str);
        return *this;
    }
    ~String()
    {
        if(!str_len) delete[] str;
    }
private:
    char* str;
    int str_len;
};

int main()
{
    String a("123");
    std::cout<<a[0]<<","<<a[2]<<","<<a[5];
}