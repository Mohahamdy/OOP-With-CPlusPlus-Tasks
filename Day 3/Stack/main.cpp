#include <iostream>

using namespace std;

class Stack
{
private:
    int *arr;
    int tos;
    int _size;
    static int counter;
public:
    static int GetCounter()
    {
        return counter;
    }
    Stack()
    {
        counter++;
        tos=0;
        _size =5;
        arr = new int[_size];
        cout<<"ctor called"<<endl;
    }
    Stack(int size)
    {
        counter++;
        tos=0;
        _size = size;
        arr = new int[_size];
        cout<<"ctor called"<<endl;
    }
    ~Stack()
    {
        counter--;
        cout<<"Dest called"<<endl;
        for(int i=0;i<_size;i++)
        {
            arr[i]=-1;
        }
        delete [] arr;
    }
    void Puch(int num)
    {
        if(!isFull())
        {
            arr[tos]=num;
            tos++;
        }
        else
        {
            cout<<"Full !!!"<<endl;
        }
    }
    int Pop()
    {
        int ret_num=-1564;
        if(!isEmpty())
        {
            tos--;
            ret_num = arr[tos];
            return ret_num;
        }
        else
        {
            cout<<"Empty !!!"<<endl;
            return ret_num;
        }
    }
    int isFull()
    {return tos == _size;}
    int isEmpty()
    {return tos == 0;}
    friend void PrintStack(Stack param);
};

void PrintStack(Stack param)
{
    for(int i=0;i<param.tos;i++)
    {
        cout<<param.arr[i]<<endl;
    }
}

int Stack::counter=0;

int main()
{
    Stack s1,s2(10),s3;

    s1.Puch(10);
    s1.Puch(20);
    s1.Puch(30);
    s1.Puch(40);
    s1.Puch(50);
    s1.Puch(60);
    s1.Puch(70);
    s1.Pop();
    s1.Pop();
    PrintStack(s1);

    cout<<"Counter: "<<Stack::GetCounter()<<endl;

    s2.Puch(10);
    s2.Puch(20);
    s2.Puch(30);
    s2.Puch(40);
    s2.Puch(50);
    s2.Puch(60);
    s2.Puch(70);
    s2.Puch(80);


   PrintStack(s2);
   PrintStack(s2);



    return 0;
}
