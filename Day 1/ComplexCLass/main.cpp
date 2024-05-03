#include <iostream>

using namespace std;
class complex
{
private:
    int real;
    int img;
public:
    void SetReal(int _real)
    {
        real = _real;
    }
    int GetReal () const
    {
        return real;
    }
     void SetImg(int _img)
    {
        img = _img;
    }
    int GetImg () const
    {
        return img;
    }
    void Print()
    {
        if(img < 0)
        {
            cout<<"Complex number is: "<<real<<img<<"i"<<endl;
        }
        else if (img == 0)
        {
            cout<<"Complex number is: "<<real<<endl;
        }
        else
        {
            cout<<"Complex number is: "<<real<<"+"<<img<<"i"<<endl;
        }
    }
    complex Add (const complex &right)
    {
        complex tmp;
        tmp.real = real+right.real;
        tmp.img = img+right.img;
        return tmp;
    }
};

complex AddTwoComplexStandAlon(complex &right,complex &left)
{
    complex tmp;
    tmp.SetReal(right.GetReal()+left.GetReal());
    tmp.SetImg(right.GetImg()+left.GetImg());
    return tmp;
}




int main()
{
    complex c1;
    complex c2;
    complex c3;
    complex c4;

    c1.SetReal(1);
    c1.SetImg(1);
    c1.Print();

    c2.SetReal(1);
    c2.SetImg(-4);
    c2.Print();

    c3=c1.Add(c2);
    c3.Print();

    c4=AddTwoComplexStandAlon(c2,c3);
    c4.Print();
    return 0;
}
