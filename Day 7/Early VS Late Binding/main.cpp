#include <iostream>

using namespace std;

class Parent
{
protected:
    int x;
public:
    void setX(int _x)
    {
        x=_x;
    }
    int getX()
    {
        return x;
    }
    Parent()
    {
        x=0;
        //cout<<"Parent Def CTOR Called"<<endl;
    }
    Parent(int _x)
    {
        x=_x;
        //cout<<"Parent Param CTOR Called"<<endl;
    }
    ~Parent()
    {
        //cout<<"Base Dest Called"<<endl;
    }
    Parent(const Parent& old)
    {
        this->x=old.x;
        //cout<<"Parent Cpy CTOR Called"<<endl;
    }
    virtual void SHOW()
    {
        cout<<"I am Base"<<endl;
    }
};

class Child:public Parent
{
protected:
    int y;
public:
    void setY(int _y)
    {
        y=_y;
    }
    int getY()
    {
        return y;
    }
    Child()
    {
        y=0;
        //cout<<"Child Def CTOR Called"<<endl;
    }
    Child(int _x,int _y):Parent(_x)
    {
        y=_y;
        //cout<<"Child Param CTOR Called"<<endl;
    }
    ~Child()
    {
        //cout<<"Child Dest Called"<<endl;
    }
    Child(const Child& old)
    {
        this->x=old.x;
        this->y=old.y;
        //cout<<"Child Cpy CTOR Called"<<endl;
    }
    void SHOW() override
    {
        cout<<"I am Child"<<endl;
    }
};

class SubChild:public Child
{
protected:
    int z;
public:
    void setZ(int _z)
    {
        z=_z;
    }
    int getZ()
    {
        return z;
    }
    SubChild()
    {
        z=0;
        //cout<<"SubChild Def CTOR Called"<<endl;
    }
    SubChild(int _x,int _y,int _z):Child(_x,_y)
    {
        z=_z;
        //cout<<"SubChild Param CTOR Called"<<endl;
    }
    ~SubChild()
    {
        //cout<<"SubChild Dest Called"<<endl;
    }
    SubChild(const SubChild& old)
    {
        this->x=old.x;
        this->y=old.y;
        this->z=old.z;
        //cout<<"SubChild Cpy CTOR Called"<<endl;
    }
    void SHOW() override
    {
        cout<<"I am SubChild"<<endl;
    }
};


int main()
{

    Parent *pPtr = new Child(1,2);
    pPtr->SHOW();

    pPtr = new SubChild(1,2,3);
    pPtr->SHOW();

    Child *cPtr = new SubChild(1,2,3);
    cPtr->SHOW();

    //Child *cPtr = new Parent(1);

    return 0;
}
