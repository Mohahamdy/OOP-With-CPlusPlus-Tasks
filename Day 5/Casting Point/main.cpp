#include <iostream>

using namespace std;
class Point2D
 {
private:
    int x;
    int y;
public:
    void setX(int _x)
    {
        x=_x;
    }
    void setY(int _y)
    {
        y=_y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    Point2D()
    {
        x=y=0;
        cout<<"ctor called"<<endl;
    }
    Point2D(int _x,int _y)
    {
        x=_x;
        y=_y;
        cout<<"ctor called"<<endl;
    }
    Point2D(int _num)
    {
        x=y=_num;

    }
    ~Point2D()
    {
        cout<<"dest called"<<endl;
    }
    Point2D(const Point2D& old)
    {
        x=old.x;
        y=old.y;
        cout<<"cpyctor called"<<endl;
    }
    void print()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
 };

 class Point3D
 {
private:
    int x;
    int y;
    int z;
public:
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
    Point3D()
    {
        x=y=z=0;
    }
    Point3D(int _x,int _y,int _z)
    {
        x=_x;y=_y;z=_z;
    }
    Point3D(const Point3D& old)
    {
        x=old.x;
        y=old.y;
        z=old.z;
    }
    ~Point3D()
    {
        cout<<"dest called"<<endl;
    }

    operator Point2D()
    {
     Point2D retVal(this->x,this->y);
     return retVal;
    }

    void print()
    {
     cout<< "("<<x<<","<<y<<","<<z<<")"<<endl;
    }

};

int main()
{
    Point2D p1(1,1);
    p1.print();

    Point3D p2(2,2,2);
    p2.print();

    Point2D tmpP=p2;
    tmpP.print();
    return 0;
}
