#include <iostream>
using namespace std;
void *memcpy(void *dst, void *src, unsigned count);
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
    try
    {
//        memcpy(NULL,arr+3,4);
//        memcpy(arr+4,NULL,4);
        memcpy(arr+3,arr+4,16);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<",";
    }

}

void *memcpy(void *dst, void *src, unsigned count)
{

    if(!dst || !src) throw runtime_error("NULL pointer!");
    if(!((char*)dst>=(char*)src+count||(char*)dst+count<=(char*)src))
    {
        throw out_of_range("Intersected!");
    }
    for(unsigned i=0;i<count;i++)
    {
        *((char*)dst+i)=*((char*)src+i);
    }
    return dst;
}