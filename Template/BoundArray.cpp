#include <iostream>
#include "ArrayTemplate.h"
#include "Point.h"
#include "Point.cpp"

using namespace std;

int main(void)
{
    BoundCheckArray<int> intarr(5);
    for (int i = 0; i < 5; i++)
        intarr[i] = i * 11;
    for (int i = 0; i < 5; i++)
        cout << intarr[i] << endl;

    BoundCheckArray<Point> Pointarr(3);
    Pointarr[0] = Point(3, 4);
    Pointarr[1] = Point(4, 5);
    Pointarr[2] = Point(5, 6);
    for (int i = 0; i < 3; i++)
        cout << Pointarr[i] << endl;

    typedef Point *PointPTR;
    BoundCheckArray<PointPTR> ptrarr(5);
    for (int i = 0; i < 5; i++)
        ptrarr[i] = new Point(i, i + 1);
    for (int i = 0; i < 5; i++)
        cout << *(ptrarr[i]) << endl;

    return 0;
}