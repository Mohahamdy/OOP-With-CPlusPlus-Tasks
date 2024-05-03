#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int img;
public:
    Complex()
    {
        cout<<"costr called"<<endl;
        real=0;
        img=0;
    }
    Complex(int _real,int _img)
    {
        cout<<"costr called"<<endl;
        real=_real;
        img=_img;
    }
    Complex(const Complex& old)
    {
        real=old.real;
        img=old.img;
        cout<<"cpy ctor";
    }
    ~Complex()
    {
        cout<<"destr called"<<endl;
    }

    void SetReal(int _real)
    {
        real=_real;
    }
    int GetReal()
    {
        return real;
    }
    void SetImg(int _img)
    {
        img=_img;
    }
    int GetImg()
    {
        return img;
    }
    void print()
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }

    Complex operator+(Complex right)
    {
        Complex retVal(real+right.real,img+right.img);
        return retVal;
    }
    Complex operator+=(Complex right)
    {
        real=real+right.real;
        img+=right.img;
        return *this;
    }
    Complex operator++()
    {
        real++;
        this->img++;
        return *this;
    }
    Complex operator++(int)
    {
        Complex retVal(real,img);
        real++;
        img++;
        return retVal;
    }
    Complex operator+(int _num)
    {
        Complex retVal(real+_num,this->img);
        return retVal;
    }
    Complex operator+=(int _num)
    {
        real+=10;
        return *this;
    }
    operator int()
    {
        return this->real;
    }
    Complex operator=(Complex right)
    {
        this->real = right.real;
        img = right.img;
        return *this;
    }
};
Complex operator+(int _num,Complex right)
    {
        Complex retVal;
        retVal.SetReal(_num+right.GetReal());
        retVal.SetImg(right.GetImg());
        return retVal;
//        return right + _num;
    }

int main()
{
    Complex c1(1,2),c2(3,4),c3;

    c1.print();
    c2.print();

    c3=c1+c2;
    //c1+=c2;
    //c3=++c1;
    //c3=c1++;
    //c3=c1+10;
    //c1+=10;
    //cout<<(c2>c1)<<endl;
    //int x=(int)c2;
    //cout<<x<<endl;
    //c1=c2;
    //c3=10+c1;

    c1.print();
    c3.print();

    return 0;
}
