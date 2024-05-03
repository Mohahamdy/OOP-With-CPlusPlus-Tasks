#include <iostream>

using namespace std;

class GeoShape
{
protected:
    double dim1;
    double dim2;
public:
    void SetDim1(double _dim1)
    {
        dim1=_dim1;
    }
    void SetDim2(double _dim2)
    {
        dim2=_dim2;
    }
    double GetDim1()
    {
        return dim1;
    }
    double GetDim2()
    {
        return dim2;
    }
    GeoShape()
    {
        dim1=dim2=0;
        //cout<<"GS Def CTOR Called"<<endl;
    }
    GeoShape(double _dim1,double _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
        //cout<<"GS 2 Param CTOR Called"<<endl;
    }
    ~GeoShape()
    {
        //cout<<"GS Dest Called"<<endl;
    }
    GeoShape(const GeoShape& old)
    {
        dim1=old.dim1;
        dim2=old.dim2;
        //cout<<"GS Cpy CTOR Called"<<endl;
    }
    virtual double CalcArea()=0;
};

class Rect:public GeoShape
{
public:
    Rect()
    {
        //cout<<"Rect Def CTOR Called"<<endl;
    }
    Rect(double _dim1,double _dim2):GeoShape(_dim1,_dim2)
    {
        //cout<<"Rect 2 Param CTOR Called"<<endl;
    }
    ~Rect()
    {
        //cout<<"Rect Dest Called"<<endl;
    }
    Rect(const Rect& old)
    {
        dim1=old.dim1;
        dim2=old.dim2;
        //cout<<"Rect Cpy CTOR Called"<<endl;
    }
    double CalcArea() override
    {
        return dim1*dim2;
    }
};


class Squr:public GeoShape
{
public:
    void SetDim1(double _dim1)
    {
        dim1=dim2=_dim1;
    }
    void SetDim2(double _dim2)
    {
        dim1=dim2=_dim2;
    }
    Squr()
    {
        //cout<<"Squr Def CTOR Called"<<endl;
    }
    Squr(double _dim1):GeoShape(_dim1,_dim1)
    {
        //cout<<"Squr 2 Param CTOR Called"<<endl;
    }
    ~Squr()
    {
        //cout<<"Squr Dest Called"<<endl;
    }
    Squr(const Squr& old)
    {
        dim1=old.dim1;
        dim2=old.dim2;
        //cout<<"Squr Cpy CTOR Called"<<endl;
    }
    double CalcArea() override
    {
        return dim1*dim2;
    }
};

class Tri:public GeoShape
{
public:
    Tri()
    {
        //cout<<"Tri Def CTOR Called"<<endl;
    }
    Tri(double base,double hieght):GeoShape(base,hieght)
    {
        //cout<<"Tri 2 Param CTOR Called"<<endl;
    }
    ~Tri()
    {
        //cout<<"Tri Dest Called"<<endl;
    }
    Tri(const Tri& old)
    {
        dim1=old.dim1;
        dim2=old.dim2;
        //cout<<"Tri Cpy CTOR Called"<<endl;
    }
    double CalcArea() override
    {
        return 0.5*dim1*dim2;
    }
};

class Circle:public GeoShape
{
public:
    Circle()
    {
        //cout<<"Circle Def CTOR Called"<<endl;
    }
    Circle(double radius):GeoShape(radius,radius)
    {
        //cout<<"Circle 2 Param CTOR Called"<<endl;
    }
    ~Circle()
    {
        //cout<<"Circle Dest Called"<<endl;
    }
    Circle(const Circle& old)
    {
        dim1=old.dim1;
        dim2=old.dim2;
        //cout<<"Circle Cpy CTOR Called"<<endl;
    }
    double CalcArea() override
    {
        return 3.14*dim1*dim2;
    }
};

double sumOfAreas(GeoShape **gPtr,int gSize)
{
    double sum=0;
    for(int i=0;i<gSize;i++)
    {
        sum+=gPtr[i]->CalcArea();
    }
    return sum;
}

int main()
{
    Rect rArr[3]={Rect(1,2),Rect(3,4),Rect(5,6)};
    Squr sArr[2]={Squr(3),Squr(4)};
    Circle cArr[2]={Circle(1),Circle(2)};
    Tri t(2,3);

    GeoShape *gPtr[8]={rArr,&rArr[1],&rArr[2],sArr,&sArr[1],cArr,&cArr[1],&t};
    cout<<"Sum of Areas: "<<sumOfAreas(gPtr,8)<<endl;

    return 0;
}
