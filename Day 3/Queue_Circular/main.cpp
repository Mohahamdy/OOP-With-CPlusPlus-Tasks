#include <iostream>

using namespace std;
class Queue
{
private:
    int *arr;
    int first;
    int last;
    int _size;

public:
    Queue()
    {
        cout<<"Ctor called"<<endl;
        _size =5;
        arr =new int[_size];
        first = -1;
        last=-1;
    }
    Queue(int size)
    {
        cout<<"Ctor called"<<endl;
        _size =size;
        arr =new int[_size];
        first = -1;
        last=-1;
    }
    ~Queue()
    {
        cout<<"Dest called"<<endl;
        for(int i=0;i<_size;i++)
        {
            arr[i]=-1;
        }
        delete [] arr;
    }

    int isFull()
    {return ((last+1)% _size == first);}
    int isEmpty()
    {return (first==-1 && last ==-1);}
    
    void Enqueue(int num)
    {
        if(isFull())
        {
            cout<<"Full !!"<<endl;

        }
      else if(isEmpty())
      {
          first=last=0;
          arr[last]=num;
      }
      else
      {
          last = (last+1) % _size;
            arr[last]=num;
      }
    }

    int Dequeue()
    {

        int ret_num=-1546;
        if(isEmpty())
        {
            cout<<"Empty !!"<<endl;
            return ret_num;
        }
        else if (first==last)
       {
         first = last = -1;
       }
       else
       {
            first = (first+1) % (_size);
            ret_num = arr[first];
            return ret_num;
       }
    }

    friend void PrintQueue(Queue param);
};

void PrintQueue(Queue param)
{
    if(param.first==-1 && param.last ==-1)
        {
            cout<<"Empty !!"<<endl;
        }
        else
        {
            if(param.first<=param.last)
            {
                for(int i=param.first;i<=param.last;i++)
                {
                    cout<<param.arr[i]<<endl;
                }
            }
            else
            {
                for(int i=param.first;i<param._size;i++)
                {
                    cout<<param.arr[i]<<endl;
                }
                for(int i=0;i<=param.last;i++)
                {
                    cout<<param.arr[i]<<endl;
                }
            }
        }

}
int main()
{
    Queue q1;
    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);
    q1.Enqueue(50);
    q1.Enqueue(60);
    q1.Enqueue(70);
    q1.Dequeue();
    q1.Dequeue();
    q1.Dequeue();
    PrintQueue(q1);

    return 0;
}
