#ifndef TPOLINOM_H
#define TPOLINOM_H
#include "number.h"
#include <iostream>
using namespace std;

class TPolinom
{
private:
    number a,b,c;
public:
    TPolinom(number, number, number);
    number value(number); //value la ham tinh gia tri cua da thuc
    int roots(number*);//mang con tro dang x[i] de tinh va dua ra 2 nghiem cua pt bac 2
    friend ostream& operator << (ostream&, TPolinom&);
};

#endif // TPOLINOM_H
