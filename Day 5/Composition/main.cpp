#include <iostream>

using namespace std;
class Point
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
    Point()
    {
        x=y=0;
        cout<<"P ctor called"<<endl;
    }
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
        cout<<"P ctor called"<<endl;
    }
    ~Point()
    {
        cout<<"P dest called"<<endl;
    }
    Point(const Point& old)
    {
        x=old.x;
        y=old.y;
        cout<<"P cpyctor called"<<endl;
    }
};
class Line
{
private:
    Point start;
    Point end;
    int color;
public:
    void setStart(Point _start)
    {
        start=_start;
    }
    void setEnd(Point _end)
    {
        end=_end;
    }
    Point getStart()
    {
        return start;
    }
    Point getEnd()
    {
        return end;
    }
    void setColor(int _color)
    {
       color=_color;
    }
    int getColor()
    {
        return color;
    }

    Line()
    {
        color=0;
        cout<<"L ctor called"<<endl;
    }
    Line(int x1,int y1,int x2,int y2,int _color)
    :start(x1,y1),end(x2,y2)
    {
        color=_color;
        cout<<"L ctor called"<<endl;
    }
    ~Line()
    {
        cout<<"L dest called"<<endl;
    }
    Line(const Line& old)
    {
        start=old.start;
        end=old.end;
        color=old.color;
        cout<<"L cpyctor called"<<endl;
    }

    void Draw()
    {
        cout<<"Line"<<endl;
        cout<<"Start:("<<start.getX()<<","<<start.getY()<<")"<<endl;
        cout<<"End:("<<end.getX()<<","<<end.getY()<<")"<<endl;
        cout<<"color:"<<color<<endl;
    }
};
///////////////////////////////////////////////////////
class Rec
{
private:
    Point upperleft;
    Point lowerright;
    int color;
public:
    void setStart(Point _upperleft)
    {
        upperleft=_upperleft;
    }
    void setEnd(Point _lowerright)
    {
        lowerright=_lowerright;
    }
    Point getUpperleft()
    {
        return upperleft;
    }
    Point getLowerright()
    {
        return lowerright;
    }
     void setColor(int _color)
    {
       color=_color;
    }
    int getColor()
    {
        return color;
    }

    Rec()
    {
        color=0;
        cout<<"ctor called"<<endl;
    }
    Rec(int x1,int y1,int x2,int y2,int _color)
    :upperleft(x1,y1),lowerright(x2,y2)
    {
        color=_color;
        cout<<"ctor called"<<endl;
    }
    ~Rec()
    {
        cout<<"dest called"<<endl;
    }
    Rec(const Rec& old)
    {
        upperleft=old.upperleft;
        lowerright=old.lowerright;
        color=old.color;
        cout<<"cpyctor called"<<endl;
    }
    void Draw()
    {
        cout<<"Rectangle"<<endl;
        cout<<"Upper:("<<upperleft.getX()<<","<<upperleft.getY()<<")"<<endl;
        cout<<"Lower:("<<lowerright.getX()<<","<<lowerright.getY()<<")"<<endl;
        cout<<"color:"<<color<<endl;
    }
};
//////////////////////////////////////////////
class Circle
{
private:
    Point center;
    int radius;
    int color;
public:
    void setCenter(Point _center)
    {
       center = _center;
    }
    void setRadius(int _radius)
    {
        radius=_radius;
    }
    void setColor(int _color)
    {
       color=_color;
    }
    Point getCenter()
    {
        return center;
    }
    int getRadius()
    {
        return radius;
    }
    int getColor()
    {
        return color;
    }

    Circle()
    {
        radius=0;
        color=0;
        cout<<"ctor"<<endl;
    }
    Circle(int x,int y,int _radius,int _color)
    :center(x,y)
    {
        radius=_radius;
        color=_color;
        cout<<"ctor"<<endl;
    }
    ~Circle()
    {
         cout<<"dest called"<<endl;
    }
    Circle(const Circle& old)
    {
        this->center=old.center;
        radius=old.radius;
        color=old.color;
        cout<<"cpy ctor"<<endl;
    }
    void Draw()
    {
        cout<<"Circle"<<endl;
        cout<<"Center:("<<center.getX()<<","<<center.getY()<<")"<<endl;
        cout<<"radius:"<<radius<<endl;
        cout<<"color:"<<color<<endl;
    }
};
/////////////////////////////////////////////////////////////
class Tri
{
private:
    Point p1;
    Point p2;
    Point p3;
    int color;
public:
     void setP1(Point _p1)
    {
        p1=_p1;
    }
    void setP2(Point _p2)
    {
        p2=_p2;
    }
    void setP3(Point _p3)
    {
        p3=_p3;
    }
    void setColor(int _color)
    {
       color=_color;
    }
    Point getP1()
    {
        return p1;
    }
    Point getP2()
    {
        return p2;
    }
    Point getP3()
    {
        return p3;
    }
    int getColor()
    {
        return color;
    }

    Tri()
    {
        color=0;
        cout<<"ctor called"<<endl;
    }
    Tri(int x1,int y1,int x2,int y2,int x3,int y3,int _color)
    :p1(x1,y1),p2(x2,y2),p3(x3,y3)
    {
        color=_color;
        cout<<"ctor called"<<endl;
    }
    ~Tri()
    {
        cout<<"dest called"<<endl;
    }
    Tri(const Tri& old)
    {
        p1=old.p1;
        p2=old.p2;
        p3=old.p3;
        color=old.color;
        cout<<"cpyctor called"<<endl;
    }

    void Draw()
    {
        cout<<"Triangle"<<endl;
        cout<<"P1:("<<p1.getX()<<","<<p1.getY()<<")"<<endl;
        cout<<"P2:("<<p2.getX()<<","<<p2.getY()<<")"<<endl;
        cout<<"P3:("<<p3.getX()<<","<<p3.getY()<<")"<<endl;
        cout<<"color:"<<color<<endl;
    }
};
int main()
{
    Line l1(1,2,3,4,5);
    l1.Draw();

//    Rec r1(6,7,8,9,10);
//    r1.Draw();
//
//    Circle c1(6,7,8,9);
//    c1.Draw();
//
//    Tri t1(1,2,3,4,5,6,7);
//    t1.Draw();

    return 0;
}
