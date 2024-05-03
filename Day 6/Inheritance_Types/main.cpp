#include <iostream>

using namespace std;
class parent
{
private:
    int x;
protected:
    int y;
public:
    int z;

    void setX(int _x)
    {
        x=_x;
    }
    void setY(int _y)
    {
        y=_y;
    }
    void setZ(int _z)
    {
        z=_z;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getZ()
    {
        return z;
    }
    int Sum()
    {
        return x+y+z;
    }
};

/*class Child:protected parent
{
private:
    int a;
protected:
    int b;
public:
    int c;

    void setA(int _a)
    {
        a=_a;
    }
    void setB(int _b)
    {
        b=_b;
    }
    void setC(int _c)
    {
        c=_c;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int getC()
    {
        return c;
    }
    int Sum()
    {
        return getX()+y+z+a+b+c;
    }
};

class SubChild:protected Child
{
private:
    int i;
protected:
    int j;
public:
    int k;

    void seti(int _i)
    {
        i=_i;
    }
    void setj(int _j)
    {
        j=_j;
    }
    void setk(int _k)
    {
        k=_k;
    }
    int geti()
    {
        return i;
    }
    int getj()
    {
        return j;
    }
    int getk()
    {
        return k;
    }
    int Sum()
    {
        return getX()+y+z+getA()+b+c+i+j;
    }
};*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////
class Child:private parent
{
private:
    int a;
protected:
    int b;
public:
    int c;

    void setA(int _a)
    {
        a=_a;
    }
    void setB(int _b)
    {
        b=_b;
    }
    void setC(int _c)
    {
        c=_c;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int getC()
    {
        return c;
    }
    int Sum()
    {
        return getX()+y+z+a+b+c;
    }
};

class SubChild:private Child
{
private:
    int i;
protected:
    int j;
public:
    int k;

    void seti(int _i)
    {
        i=_i;
    }
    void setj(int _j)
    {
        j=_j;
    }
    void setk(int _k)
    {
        k=_k;
    }
    int geti()
    {
        return i;
    }
    int getj()
    {
        return j;
    }
    int getk()
    {
        return k;
    }
    int Sum()
    {
        return getA()+b+c+i+j+k;
    }
};
int main()
{

    return 0;
}
