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
        first = 0;
        last=0;
    }
    Queue(int size)
    {
        cout<<"Ctor called"<<endl;
        _size =size;
        arr =new int[_size];
        first = 0;
        last=0;
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
    void Enqueue(int num)
    {
        if(!isFull())
        {
            arr[last] = num;
            last++;
        }
      else
      {
          cout<<"Full !!"<<endl;
      }
    }
    int Dequeue()
    {

        int ret_num=-1546;
        if(!isEmpty())
        {
            ret_num = arr[first];
            for(int i=0;i<last;i++)
            {
                arr[i]=arr[i+1];

            }
            last--;
            return ret_num;
        }
      else
      {
          cout<<"Empty !!"<<endl;
          return ret_num;
      }
    }
    int isFull()
    {return last == _size;}
    int isEmpty()
    {return first == last;}
    friend void PrintQueue(Queue param);
};

void PrintQueue(Queue param)
{
    for(int i=0;i<param.last;i++)
    {
        cout<<param.arr[i]<<endl;
    }
}
int main()
{
    Queue q1(5);
    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);
    q1.Enqueue(50);
    q1.Enqueue(60);
    q1.Enqueue(70);
    q1.Dequeue();
    q1.Dequeue();


    PrintQueue(q1);









    return 0;
}
