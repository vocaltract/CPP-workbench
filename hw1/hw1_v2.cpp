#include <cstdio>
using namespace std;
/*使用循环数组和双向链表实现*/
/*使用ARRAY LINKED_NODE LOGGING 三个宏进行控制*/
//#define ARRAY
#define LINKED_NODE 1
#define LOGGING


#ifdef LOGGING
#define Log(format, ...)\
    printf("\33[1;35m[%s,%d,%s] " format "\33[0m\n",\
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)
#else
#define Log(format, ...)  
#endif
#ifdef ARRAY
const int QUEUE_SZ = 100;
#elif LINKED_NODE
struct Node{
    int val;
    Node* next;
};
#endif

class Queue
{
    public:
    #ifdef ARRAY
        Queue() 
        {
            front=rear=0;
            empty = true;
            full = false;
        }
        bool is_empty()
        {
            return empty;
        }
        bool is_full()
        {
            return full;
        }
        int insert(int num)
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
        int del(int &num)
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
    #elif LINKED_NODE
    Queue()
    {
        front = rear = NULL;
        count = 0;
    }

    bool is_empty()
    {
        return !count;
    }

    int del(int &num)
    {
        if(is_empty())
        {
            Log("The queue is empty!Deletion failed!");
            return -1;           
        }
        else
        {
            Node * temp = front;
            front = front->next;
            num = temp->val;
            delete temp;
            count --;
            return 0;
        }
    }

    int insert(int num)
    {
        if(!is_empty())
        {
            rear->next = new Node;
            rear = rear->next;
            rear->val = num;
            rear->next = NULL;
        }
        else
        {
            rear = front = new Node;
            rear ->val = num;
            rear ->next = NULL;
        }
        count ++;
        return 0;
    }


    #endif
    private:
    #ifdef ARRAY
        int front, rear;
        int queue[QUEUE_SZ];
        bool full,empty;
    #elif LINKED_NODE
        Node *front, *rear;
        int count;
    #endif
};

int main()
{
    Queue my_queue;
    int num;
    my_queue.del(num);
    my_queue.insert(1);
    my_queue.insert(1);
    my_queue.insert(1);
    my_queue.insert(1);
    my_queue.del(num);
    my_queue.del(num);
    my_queue.del(num);
    my_queue.del(num);
    my_queue.del(num);
}