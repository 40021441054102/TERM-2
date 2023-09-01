#include <iostream>
#include <cmath>
using namespace std;

struct point1{
	double x; //stands for x
	double y; //stands for y
};
struct point2{
	double x;//stands for x
	double y;//stands for y
};

double distToOrigin(double x, double y)
{
	double dist = sqrt(pow(x,2)+pow(y,2));
	return dist;
}

double distToAnotherPoint(double x1, double y1, double x2, double y2)
{
	double dist = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	return dist;
}

int main()
{
	struct point1 p1;
	struct point2 p2;
	cout<<"---------------------- ";
	cout<<"\nGive me cordinates of point#1 : ";
	cout<<"\nGive me point#1's x : ";
	cin>>p1.x;
	cout<<"Give me point#1's y : ";
	cin>>p1.y;
	cout<<"---------------------- ";
	cout<<"\nGive me cordinates of point#2 : ";
	cout<<"\nGive me point#2's x : ";
	cin>>p2.x;
	cout<<"Give me point#2's y : ";
	cin>>p2.y;
	cout<<"-------- done -------- ";
	cout<<"\ndistance of point#1 from point 0,0 is : ";
	cout<<distToOrigin(p1.x,p1.y);
	cout<<"\ndistance of point#2 from point 0,0 is : ";
	cout<<distToOrigin(p2.x,p2.y);
	cout<<"\n---------------------------------- ";
	cout<<"\ndistance between 2 points is : ";
	cout<<distToAnotherPoint(p1.x,p1.y,p2.x,p2.y);
}