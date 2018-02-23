#include <iostream>
#include <math.h>
#include "Cart_Vector.h"
#include "Cart_Point.h"

using namespace std;

Cart_Point:: Cart_Point(){
	x = 0.0;
	y = 0.0;
}

Cart_Point:: Cart_Point(double inputx, double inputy)
{
	x = inputx;
	y = inputy;	
}

//non member functions 
// find distance between two points 
double cart_distance(Cart_Point p1, Cart_Point p2)
{
	double distance = sqrt(pow(p1.x - p2.x,2)+ pow(p1.y - p2.y, 2));
	return distance;
}
//stream output operator
ostream& operator<<(ostream& out, const Cart_Point& p1)
{
	out<< "("<< p1.x << ", "<< p1.y<< ")";
	return out;
}

//addition operator
Cart_Point operator+(Cart_Point p1, Cart_Vector v1)
{
	double x = p1.x + v1.x;
	double y = p1.y + v1.y;
	Cart_Point newCart_Point = Cart_Point(x,y);
	return newCart_Point;
}

//subtraction operator
Cart_Vector operator-(Cart_Point p1, Cart_Point p2)
{
	double x = p1.x - p2.x;
	double y = p1.y - p2.y; 
	Cart_Vector newCart_Vector = Cart_Vector(x,y);
	return newCart_Vector;
}
