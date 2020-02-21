#include <cstdio>
using namespace std;
typedef int QUEVAL;


#define LOGGING
#ifdef LOGGING
#define Log(format, ...)\
    printf("\33[1;35m[%s,%d,%s] " format "\33[0m\n",\
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)
#else
#define Log(format, ...)  
#endif

bool is_empty();
bool is_full();
int insert(QUEVAL num);
int del(QUEVAL &num);


const int QUEUE_SZ = 3;
int front = 0, rear = 0;
bool empty=true, full=false;
QUEVAL queue[QUEUE_SZ];


int main()
{
    QUEVAL num;
    del(num);
    insert(1);
    insert(1);
    insert(1);
    insert(2);
    del(num);
    del(num);
    del(num);
    del(num);
}





bool is_empty()
{
    return empty;
}

bool is_full()
{
    return full;
}
        
int insert(QUEVAL num)
{
    if(full)
    {
        Log("The queue is full!Insertion failed!");
        return -1;
    }
    else
    {
        empty = false;
        queue[rear] = num;
        rear = (rear+1)%QUEUE_SZ;
        if(rear == front) full = true;
        return 0;
    }
}
int del(QUEVAL &num)
{
    if(empty)
    {
        Log("The queue is empty!Deletion failed!");
        return -1;
    }
    else
    {
        full = false;
        num = queue[front];
        front = (front+1)%QUEUE_SZ;
        if(rear == front) empty = true;
        return 0;
    }
}