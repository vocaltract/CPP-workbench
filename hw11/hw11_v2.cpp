#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <regex>
#include <cstdlib>
#include <vector>
#include <algorithm>
using std::ofstream;
using std::string;
using std::vector;
using std::ios;
using std::cout;
using std::endl;
using std::ifstream;
using std::cin;
using std::regex;
using std::smatch;
using std::stoi;

int main()
{
    ofstream fileA("A.dat",ios::out|ios::binary);
    ofstream fileB("B.dat",ios::out|ios::binary);
    if(!fileA.is_open()||!fileB.is_open()) assert(0);
    string str_buf;
    cout<<"Type the A's available workhours, and end with 'A'."<<endl;
    getline(cin,str_buf,'A');
    fileA.write(&str_buf[0],str_buf.length());
    fileA.close();
    str_buf.clear();
    cin.ignore();
    cout<<"Type the B's available workhours, and end with 'B'."<<endl;
    getline(cin,str_buf,'B');
    fileB.write(&str_buf[0],str_buf.length());
    fileB.close();
    ifstream in_fileA("A.dat",ios::in|ios::binary);
    ifstream in_fileB("B.dat",ios::in|ios::binary);
    if(!in_fileA.is_open()||!in_fileB.is_open()) assert(0);
    str_buf.resize(200);
    in_fileA.read(&str_buf[0],200);
    regex reg("([0-9]{1,2}):00~([0-9]{1,2}):00");
    smatch sm;
    vector<int> a_times,b_times;
    while(regex_search(str_buf,sm,reg))
    {
        for(int i=stoi(sm[1]);i<stoi(sm[2]);i++)    
            a_times.push_back(i);
        str_buf = sm.suffix().str();
    }
    str_buf.clear();
    str_buf.resize(200);
    in_fileB.read(&str_buf[0],200);
    while(regex_search(str_buf,sm,reg))
    {
        for(int i=stoi(sm[1]);i<stoi(sm[2]);i++)    
            b_times.push_back(i);
        str_buf = sm.suffix().str();
    }
    vector<int> res(25);
    vector<int>::iterator it=std::set_intersection(a_times.begin(),a_times.end(),b_times.begin(),b_times.end(),res.begin());
    res.resize(it-res.begin());
    bool first_flag=true;
    int last_val=0;
    std::ostringstream res_buf;
    for(auto it=res.begin();it!=res.end();it++)
    {
        if(first_flag)
        {
            first_flag=false;
            res_buf<<*it<<":00~";
            last_val=*it;
        }
        else if(last_val+1!=*it)
        {
            res_buf<<last_val+1<<":00,";
            res_buf<<*it<<":00~";
            last_val=*it;
        }
        else
        {
            last_val++;
        }
    }
    res_buf<<last_val+1<<":00";
    ofstream fileC("C.dat",ios::out|ios::binary);
    fileC.write(&(res_buf.str())[0],res_buf.str().length());
    fileC.close();
}