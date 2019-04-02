#include "polinom.h"
#include <math.h>
#define EPSILON 0.00001 // vi chung ta co tao ra kieu number (double), nen sau nay khi so sanh delta se gap van de voi 0
// can thiet phai tao hang so EPSILON de tranh sai lam khi so sanh double voi 0

TPolinom::TPolinom(number x, number y, number z)
{
    a=x;
    b=y;
    c=z;
}

number TPolinom::value(number x)
{
    return (a*x*x+b*x+c);
}

int TPolinom::roots(number *x)
{
    number d = b*b - 4*a*c;
    if (d>EPSILON) {
        x[0] = (-b + sqrt(d))/2*a;
        x[1] = (-b - sqrt(d))/2*a;
        return 2;//co 2 nghiem
    }
    if (d >= -EPSILON  && d<= EPSILON){
        x[0]= -b/2*a;
        return 1; //tra ve 1 nghiem
    }
    return 0; //vo nghiem
}

ostream& operator << (ostream& os, TPolinom& p)
{
    bool hasa= fabs(p.a) >= EPSILON;
    bool hasb= fabs(p.b) >= EPSILON;
    //kiem tra xem a, b khac 0, de in ra dang cua da thuc

    if (fabs(p.a) >= EPSILON)
        os << p.a << "x^2";
    if (p.b >= EPSILON)
        if (hasa)
            os <<"+"<<p.b<<"x";
        else if (p.b<=-EPSILON){
            os<<p.b<<"x";
        }
    if (p.c >= EPSILON)
        if (hasa||hasb)
            os<<"+"<<p.c<<"";
        else {
            os<<p.c<<"";
        }
    else if (p.c <= -EPSILON){
        os<<p.c<<"";
    } else if (!hasa && !hasb)
        os << "0";
    return os;
}
