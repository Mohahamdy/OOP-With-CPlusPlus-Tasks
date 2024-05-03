#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int img;
public:
    void SetReal(int _real)
    {
        (*this).real=_real;
    }
    int GetReal()
    {
        return this->real;
    }
     void SetImg(int _img)
    {
        (*this).img=_img;
    }
    int GetImg()
    {
        return this->img;
    }
    ////////
    void print()
    {
        cout<<"Complex number is: "<<real<<"+"<<img<<"i"<<endl;
    }
    ////////
    void Initiate()
    {
        this->real=0;
        (*this).img=0;
    }
    void Initiate(int _num)
    {
        this->real=_num;
        (*this).img=_num;
    }
    void Initiate(int _real,int _img)
    {
        this->real=_real;
        (*this).img=_img;
    }
    //////////
    Complex Add(Complex right)
    {
        Complex tmp;
        tmp.real= real+right.real;
        tmp.img=this->img+right.img;
        return tmp;
    }
    ///////////
    Complex()
    {
        this->real=0;
        (*this).img=0;
        cout<<"Constructor called"<<real<<endl;
    }
    Complex(int _num)
    {
        this->real=_num;
        (*this).img=_num;
        cout<<"Constructor called"<<real<<endl;
    }
    Complex(int _real,int _img)
    {
        this->real=_real;
        (*this).img=_img;
        cout<<"Constructor called"<<real<<endl;
    }
    /////////
    ~Complex(){
        cout<<"Destructor called"<<real<<endl;
    }
};

Complex AddStandAlone(Complex right,Complex left)
{
    Complex tmp;
    tmp.SetReal(right.GetReal()+left.GetReal());
    tmp.SetImg(right.GetImg()+left.GetImg());
    return tmp;
};
int main()
{

//    Complex c1,c2,c3,c4,c5;
//    c1.Initiate();
//    c2.Initiate(3);
//    c3.Initiate(5,6);
//    c4=c1.Add(c2);
//    c4.print();
//    c5=AddStandAlone(c2,c3);
//    c5.print();

    Complex c1(4),c2(7,8),c3;
    c3=AddStandAlone(c1,c2);
    c3.print();
    return 0;
}
