#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
    String(char* s)
    {
        if(s)
        {
            len = strlen(s);
            str = new char[len+1];
            strcpy(str,s);
        }
        else
        {
            len = 0;
            str = NULL;
        }
    }
    String(const String& s)
    {
        len = s.get_len();
        set(s.get_str());
    }
    int get_len() const
    {
        return len;
    }
    char* get_str() const
    {
        return str;
    }
    bool is_NULL() const
    {
        return len==0;
    }
    
    void set(char* s)
    {
        if(s)
        {
            delete[] str;            
        }
        int s_len = strlen(s);
        str = new char[s_len+1];
        strcpy(str,s);
    }
    void clear()
    {
        delete[] str;
        str = NULL;
    }

    static int mystrcat(const String& str1, const String& str2, String& str3)
    {
        if(str1.is_NULL()&&str2.is_NULL())
        {
            cerr<<"Both are NULL\n";
            return 0;
        }
        else if(str1.is_NULL())
        {
            str3.set(str2.get_str());
            return strlen(str2.get_str());       
        }
        else if(str2.is_NULL())
        {
            str3.set(str1.get_str());
            return strlen(str1.get_str());  
        }
        else
        {
            int new_s_len = str1.get_len()+str2.get_len();
            char* new_s = new char[new_s_len+1];
            strcpy(new_s,str1.get_str());
            strcpy(&new_s[str1.get_len()],str2.get_str());
            str3.set(new_s);
            delete new_s;
            return strlen(new_s);          
        }
    }
    void output()
    {
        cout<<str<<endl;
    }
    ~String()
    {
        delete[] str;
        str = NULL;
        len = 0;
    }
private:
    char* str;
    int len;
};

class Array
{
public:
    Array(int length, int column)
        : len(length), col(column)
    {
        array = new double[length];
    }
    Array(int length, int column, double origin[], int origin_len)
        : len(length), col(column)
    {
        array = new double[length];
        for (int i = 0; i < len; i++)
        {
            if (i < origin_len)
            {
                array[i] = origin[i];
            }
            else
            {
                array[i] = 0;
            }
        }
    }
    inline double loc(int x, int y) const
    {
        return array[x * col + y];
    }
    inline double get(int x) const
    {
        return array[x];
    }

    inline int get_col() const
    {
        return col;
    }
    inline int get_row() const
    {
        return len / col;
    }
    inline int get_len() const
    {
        return len;
    }
    inline void swap()
    {
        for (int i = 0; i < len; i++)
        {
            array[i] = -array[i];
        }
    }
    inline void output() const
    {
        for (int i = 0; i < len; i++)
        {
            if (i % col == col - 1)
            {
                cout << array[i] << ",\n";
            }
            else
            {
                cout << array[i] << ",";
            }
        }
    }
    Array(const Array &a)
    {
        len = a.get_len();
        col = a.get_col();
        array = new double[len];
        for (int i = 0; i < len; i++)
        {
            array[i] = a.get(i);
        }
    }
    ~Array()
    {
        delete[] array;
    }

private:
    int len;
    int col;
    double *array;
};

class Matrix
{
public:
    Matrix(int this_row, int this_col, double origin[], int origin_len)
        : row(this_row),
          col(this_col),
          arr(row * col, col, origin, origin_len)
    {
    }
    Matrix(const Matrix &a)
        : row(a.get_row()),
          col(a.get_col()),
          arr(a.arr)
    {
        arr.swap();
    }
    inline int get_col() const
    {
        return col;
    }
    inline int get_row() const
    {
        return row;
    }
    inline void output() const
    {
        arr.output();
    }

private:
    int row, col;
    Array arr;
};


class Single
{
public:
    static Single* create_obj();
    static void del_obj();
    Single()
    {
        count_object++;
        
    }
    ~Single()
    {
        count_object--;
    }

private:
    static int get_count_obj()
    {
        return count_object;
    }
    static int count_object;
    static Single* the_only;
};
int Single::count_object = 0;
Single* Single::the_only = NULL;



Single* Single::create_obj()
{
    if(Single::get_count_obj())
    {
        cerr<<"Object Creation Failed!"<<endl;
    }
    else
    {
        Single::the_only = new Single;
        Single::count_object++;
        
    }
    return Single::the_only;
    
}
void Single::del_obj()
{
    if(Single::get_count_obj())
    {
        Single::count_object--;
        delete Single::the_only;
        Single::the_only = NULL;
    }
    else
    {
        cerr<<"There is no object!"<<endl;
    }
}



int main()
{

    /*double arr[] = {1, 2, 3, 4, 5, 6};
    Matrix matrix1(2, 3, arr, 6);
    matrix1.output();
    Matrix matrix2(matrix1);
    matrix2.output();*/
    //String str1("abc"),str2("def"),str3("!23");
    //String::mystrcat(str1,str2,str3);
    //str3.output();
    Single::del_obj();
    Single* a = Single::create_obj();
    Single* b = Single::create_obj();
    Single::del_obj();
    Single::del_obj();
    a = Single::create_obj();
    


}