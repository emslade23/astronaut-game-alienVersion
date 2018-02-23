#ifndef CART_VECTOR_H
#define CART_VECTOR_H

#include <iostream>

using namespace std;

class Cart_Vector
{
public:
    double x;
    double y;

    Cart_Vector();
    Cart_Vector(double, double);
};

ostream& operator<<(ostream& out, const Cart_Vector& v1);
Cart_Vector operator*(Cart_Vector v1, double d);
Cart_Vector operator/(Cart_Vector v1, double d);


#endif