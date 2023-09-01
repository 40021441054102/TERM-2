#include <iostream>
#include <cmath>
#define center_x 0
#define center_y 0

using namespace std;

class Point 
{
    private:
        double x,y;
    public:
        int x_ret()
        {
            return x;
        }
        int y_ret()
        {
            return y;
        }
        Point(int, int);
        Point()
        {

        }
};

Point::Point(int x_in, int y_in)
{
    x = x_in;
    y = y_in;
}



class Size
{
    protected:
        double width,height;
    public:
        Size(int, int);
        int w_ret()
        {
            return width;
        }
        int h_ret()
        {
            return height;
        }
        Size()
        {

        }
};

Size::Size(int w_in, int h_in)
{
    height = h_in;
    width = w_in;
}


class Rectangle:public Size,public Point
{
    private :
        double area, diam, prim, dist;
        double x,y,w,l;
    public :
        Rectangle(Size s, Point p)
        {
            w = s.w_ret();
            l = s.h_ret();
            x = p.x_ret();
            y = p.y_ret();
        }
        void Perimeter();
        void Area();
        void Diameter();
        void Distance();
        void Print();
};

void Rectangle::Perimeter()
{
    cout << w << endl; 
    prim = (w * 2) + (l * 2);
}

void Rectangle::Diameter()
{
    diam = sqrt(pow(w,2) + pow(l,2));
}

void Rectangle::Area()
{
    area = w * l;
}

void Rectangle::Distance()
{
    dist = sqrt(pow(x,2) + pow(y,2));
}

void Rectangle::Print()
{
    Perimeter();
    Area();
    Diameter();
    Distance();
    cout << endl;
    cout << "\033[1;95m Area :\033[1;94m " << area << endl;
    cout << "\033[1;95m Primeter :\033[1;94m " << prim << endl;
    cout << "\033[1;95m Diameter :\033[1;94m " << diam << endl;
    cout << "\033[1;95m Distance to Point (0,0) :\033[1;94m " << dist << endl;
}


int main()
{
    cout << "\033[1;33mEnter Howmany Times Do You Want ?" << endl;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\033[1;36mRectangle \033[1;33m#" << n << endl;
        double x,y;
        cout << "\033[1;36mEnter x and y of Your Point :\033[1;94m" << endl;
        cin >> x >> y;
        Point p(x,y);
        double w,h;
        cout << "\033[1;36mEnter Width and Height of Your Rectangle\033[1;94m" << endl;
        cin >> w >> h;
        Size s(w,h);
        Rectangle rec = Rectangle(s, p);
        rec.Print();
    }
}