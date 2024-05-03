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
        cout<<"Point Def ctor called"<<endl;
    }
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
        cout<<"Point 2Param ctor called"<<endl;
    }
    ~Point()
    {
        cout<<"Point dest called"<<endl;
    }
    Point(const Point& old)
    {
        x=old.x;
        y=old.y;
        cout<<"Point cpyctor called"<<endl;
    }
};
////////////////////////////////////////////
class ShapeColor
{
protected:
    int color;
public:
    void setColor(int _color)
    {
       color=_color;
    }
    int getColor()
    {
        return color;
    }
    ShapeColor()
    {
        color=0;
        cout<<"ShapeColor Def ctor called"<<endl;
    }
    ShapeColor(int _color)
    {
        color=_color;
        cout<<"ShapeColor Param ctor called"<<endl;
    }
    ~ShapeColor()
    {
        cout<<"ShapeColor Dest called"<<endl;
    }
    ShapeColor(const ShapeColor& old)
    {
        color=old.color;
        cout<<"ShapeColor Cpy ctor called"<<endl;
    }
};
/////////////////////////////////////////////
class Line:public ShapeColor
{
private:
    Point start;
    Point end;
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

    Line()
    {
        cout<<"Line Def ctor called"<<endl;
    }
    Line(int x1,int y1,int x2,int y2,int _color)
    :start(x1,y1),end(x2,y2),ShapeColor(_color)
    {
        cout<<"Line Param ctor called"<<endl;
    }
    ~Line()
    {
        cout<<"Line dest called"<<endl;
    }
    Line(const Line& old)
    {
        start=old.start;
        end=old.end;
        color=old.color;
        cout<<"Line cpyctor called"<<endl;
    }

    void Draw()
    {
        cout<<"----->Line<-----"<<endl;
        cout<<"Start:("<<start.getX()<<","<<start.getY()<<")"<<endl;
        cout<<"End:("<<end.getX()<<","<<end.getY()<<")"<<endl;
        cout<<"color:"<<color<<endl;
    }
};
///////////////////////////////////////////////////////
class Rec:public ShapeColor
{
private:
    Point upperleft;
    Point lowerright;
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

    Rec()
    {
        cout<<"Rec Def ctor called"<<endl;
    }
    Rec(int x1,int y1,int x2,int y2,int _color)
    :upperleft(x1,y1),lowerright(x2,y2),ShapeColor(_color)
    {
        cout<<"Rec Param ctor called"<<endl;
    }
    ~Rec()
    {
        cout<<"Rec dest called"<<endl;
    }
    Rec(const Rec& old)
    {
        upperleft=old.upperleft;
        lowerright=old.lowerright;
        color=old.color;
        cout<<"Rec cpyctor called"<<endl;
    }
    void Draw()
    {
        cout<<"----->Rectangle<-----"<<endl;
        cout<<"Upper:("<<upperleft.getX()<<","<<upperleft.getY()<<")"<<endl;
        cout<<"Lower:("<<lowerright.getX()<<","<<lowerright.getY()<<")"<<endl;
        cout<<"color:"<<color<<endl;
    }
};
//////////////////////////////////////////////
class Circle:public ShapeColor
{
private:
    Point center;
    int radius;
public:
    void setCenter(Point _center)
    {
       center = _center;
    }
    void setRadius(int _radius)
    {
        radius=_radius;
    }
    Point getCenter()
    {
        return center;
    }
    int getRadius()
    {
        return radius;
    }

    Circle()
    {
        radius=0;
        cout<<"Circle Def ctor"<<endl;
    }
    Circle(int x,int y,int _radius,int _color)
    :center(x,y),ShapeColor(_color)
    {
        radius=_radius;
        cout<<"Circle Param ctor"<<endl;
    }
    ~Circle()
    {
         cout<<"Circle dest called"<<endl;
    }
    Circle(const Circle& old)
    {
        this->center=old.center;
        radius=old.radius;
        color=old.color;
        cout<<"Circle cpy ctor"<<endl;
    }
    void Draw()
    {
        cout<<"----->Circle<------"<<endl;
        cout<<"Center:("<<center.getX()<<","<<center.getY()<<")"<<endl;
        cout<<"radius:"<<radius<<endl;
        cout<<"color:"<<color<<endl;
    }
};
/////////////////////////////////////////////////////////////
class Tri:public ShapeColor
{
private:
    Point p1;
    Point p2;
    Point p3;
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

    Tri()
    {
        cout<<"Tri Def ctor called"<<endl;
    }
    Tri(int x1,int y1,int x2,int y2,int x3,int y3,int _color)
    :p1(x1,y1),p2(x2,y2),p3(x3,y3),ShapeColor(_color)
    {
        color=_color;
        cout<<"Tri Param ctor called"<<endl;
    }
    ~Tri()
    {
        cout<<"Tri dest called"<<endl;
    }
    Tri(const Tri& old)
    {
        p1=old.p1;
        p2=old.p2;
        p3=old.p3;
        color=old.color;
        cout<<"Tri cpyctor called"<<endl;
    }

    void Draw()
    {
        cout<<"---->Triangle<------"<<endl;
        cout<<"P1:("<<p1.getX()<<","<<p1.getY()<<")"<<endl;
        cout<<"P2:("<<p2.getX()<<","<<p2.getY()<<")"<<endl;
        cout<<"P3:("<<p3.getX()<<","<<p3.getY()<<")"<<endl;
        cout<<"color:"<<color<<endl;
    }
};
///////////////////////////////////////////////
class Picture
{
private:
    Line* Lptr;
    int Lsize;
    Rec* Rptr;
    int Rsize;
    Circle* Cptr;
    int Csize;
    Tri* Tptr;
    int Tsize;
public:
    Picture()
    {
        Lptr=NULL;
        Lsize=0;
        Rptr=NULL;
        Rsize=0;
        Cptr=NULL;
        Csize=0;
        Tptr=NULL;
        Tsize=0;
        cout<<"Picture Def ctor called"<<endl;
    }

    ~Picture()
    {
        cout<<"Picture Dest called"<<endl;
    }
    Picture(const Picture& old)
    {
        Lptr=old.Lptr;
        Lsize=old.Lsize;
        Rptr=old.Rptr;
        Rsize=old.Rsize;
        Cptr=old.Cptr;
        Csize=old.Csize;
        Tptr=old.Tptr;
        Tsize=old.Tsize;
        cout<<"Picture Cpy ctor called"<<endl;
    }
    void SetLine(Line* _Lptr,int _Lsize)
    {
        Lptr=_Lptr;
        Lsize=_Lsize;
    }
    void SetRec(Rec* _Rptr,int _Rsize)
    {
        Rptr=_Rptr;
        Rsize=_Rsize;
    }
    void SetCircle(Circle* _Cptr,int _Csize)
    {
        Cptr=_Cptr;
        Csize=_Csize;
    }
    void SetTri(Tri* _Tptr,int _Tsize)
    {
        Tptr=_Tptr;
        Tsize=_Tsize;
    }
    void MakeIt()
    {
        for(int i=0;i<Lsize;i++)
        {
            Lptr[i].Draw();
        }
        for(int i=0;i<Rsize;i++)
        {
            Rptr[i].Draw();
        }
        for(int i=0;i<Csize;i++)
        {
            Cptr[i].Draw();
        }
        for(int i=0;i<Tsize;i++)
        {
            Tptr[i].Draw();
        }

    }

};
int main()
{
//    Line l1(1,2,3,4,5);
//    l1.Draw();
//
//    Rec r1(6,7,8,9,10);
//    r1.Draw();
//
//    Circle c1(6,7,8,9);
//    c1.Draw();
//
//    Tri t1(1,2,3,4,5,6,7);
//    t1.Draw();

    Line Larr[3]={Line(1,2,3,4,5),Line(1,2,3,4,5),Line(1,2,3,4,5)};
    Rec Rarr[3]={Rec(6,7,8,9,10),Rec(6,7,8,9,10),Rec(6,7,8,9,10)};
    Circle Carr[3]={Circle(11,12,13,14),Circle(11,12,13,14),Circle(11,12,13,14)};
    Tri Tarr[3]={Tri(1,2,3,4,5,6,7),Tri(1,2,3,4,5,6,7),Tri(1,2,3,4,5,6,7)};

    Picture P1;
    P1.SetLine(Larr,3);
    P1.SetRec(Rarr,3);
    P1.SetCircle(Carr,3);
    P1.SetTri(Tarr,3);

    P1.MakeIt();

    P1.SetLine(NULL,0);
    P1.SetRec(NULL,0);
    P1.SetCircle(NULL,0);
    P1.SetTri(NULL,0);

    return 0;
}
