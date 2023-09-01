#include <iostream>
using namespace std;
class Point
{
    friend bool operator!=(Point p1,Point p2);
    private :
        int x;
        int y;
    public :
    Point(int, int);
    Point();
    void pointSet(int, int);
    void pointPrint();
    void dist_to_another(const Point &);
    bool operator==(Point p2)
    {
        if (this->x == p2.x && this->y == p2.y)
        {
            return 1;
        }
    }
};

void Point::pointSet(int xx,int yy)
{
    x = xx;
    y = yy;
}

void Point::pointPrint()
{
    cout << endl << "- Point(" << x << "," << y <<")" << endl;
}

void Point::dist_to_another(const Point &dist)
{
    int height,floor,distance;
    height = this->x - dist.x;
    floor = this->y - dist.y;
    distance = height*height + floor*floor;
    cout << "Distance is : " << distance;
}

Point::Point(int x1, int y1)
{
    pointSet(x1,y1);
}

Point::Point()
{
    x = 0;
    y = 0;
}

bool operator!=(Point p1,Point p2)
{
    if (p1.x != p2.x && p1.y != p2.y)
    {
        return 0;
    }
}

int main()
{
    Point p;
    int x1,x2,y1,y2;
    cout << "Enter Point #1's x & y :" << endl;
    cout << "- x1 =\t"; cin >> x1;
    
    cout << "- y1 =\t"; cin >> y1;
    
    cout << endl;
    cout << "Enter Point #2's x & y :" << endl;
    cout << "- x2 =\t"; cin >> x2;
    
    cout << "- y2 =\t"; cin >> y2;
    
    cout << endl;
    Point p1(x1,y1),p2(x2,y2);
    cout << endl;
    p1.pointPrint();
    p2.pointPrint();
    cout << endl;
    p1.dist_to_another(p2);
    cout << endl;
    if (p1==p2)
    {
        cout << endl;
        cout << "are same";
    }
    if (p1!=p2)
    {
        cout << endl;
        cout << "are not same";
    }

    cin.ignore();
}