#include <iostream>

using namespace std;

class Stack
{
private:
    int *arr;
    int tos;
    int _size;
public:
    Stack()
    {

        tos=0;
        _size =5;
        arr = new int[_size];
//        cout<<"ctor called"<<endl;
    }
    Stack(int size)
    {

        tos=0;
        _size = size;
        arr = new int[_size];
//        cout<<"ctor called"<<endl;
    }
    Stack(const Stack& old)
    {
        this->tos=old.tos;
        _size = old._size;
        this->arr = new int[_size];
        for(int i=0;i<tos;i++)
        {
            this->arr[i]=old.arr[i];
        }
//        cout<<"Cpyctor called"<<endl;
    }
    ~Stack()
    {

//        cout<<"Dest called"<<endl;
        for(int i=0;i<_size;i++)
        {
            arr[i]=-1;
        }
        delete [] arr;
    }

      int isFull()
    {return tos == _size;}
    int isEmpty()
    {return tos == 0;}

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

    void Print()
    {
         for(int i=0;i<tos;i++)
        {
            cout<<arr[i]<<"   ";
        }
    }
    friend void PrintStack(Stack param);

    Stack operator=(Stack right)
    {
        delete [] this->arr;
        this->tos=right.tos;
        _size = right._size;
        this->arr = new int[_size];
        for(int i=0;i<tos;i++)
        {
            this->arr[i]=right.arr[i];
        }
        return *this;
    }
    Stack operator+(Stack right)
    {
        Stack retVal((this->_size+right._size));
//        delete[] retVal.arr;
//        retVal._size=this->_size+right._size;
//        retVal.arr = new int[retVal._size];

        for(int i=0;i<this->tos;i++)
        {
            retVal.Puch(arr[i]);
        }
        for(int i=0;i<right.tos;i++)
        {
            retVal.Puch(right.arr[i]);
        }
        return retVal;
    }

    Stack Reverse()
    {
        Stack retVal((_size));
//        delete[] retVal.arr;
//        retVal._size=this->_size;
//        retVal.arr = new int[retVal._size];
        for(int i=(tos-1);i>=0;i--)
        {
            retVal.Puch(arr[i]);
        }
        return retVal;
    }

    int operator==(Stack right)
    {

        if(tos==right.tos)
        {
            int repeated=0;
            for(int i=0;i<tos;i++)
            {
                for(int j=0;j<tos;j++)
                {
                    if(arr[i]==right.arr[j])
                    {
                        repeated++;;
                    }
                }
                if(repeated==1)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            return 0;
        }
    }
};

void PrintStack(Stack param)
{
    for(int i=0;i<param.tos;i++)
    {
        cout<<param.arr[i]<<"   ";
    }
}

int main()
{
    Stack s1,s2(10),s3;
    s2.Puch(10);
    s2.Puch(20);
    s2.Puch(30);
    s2.Puch(40);
    s2.Puch(50);


    s1.Puch(50);
    s1.Puch(10);
    s1.Puch(20);
    s1.Puch(30);
    s1.Puch(40);

    int x= (s1==s2);
    cout<<x<<endl;
    s3=s2.Reverse();
    s3.Print();
    cout<<endl;
    s1=s2;
    s3=s1+s2;
    s3.Print();

    return 0;
}
