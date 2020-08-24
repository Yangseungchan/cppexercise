#include <iostream>
#include "Point.h"

using namespace std;

Point::Point(int x, int y) : xpos(x), ypos(y) {}

ostream &operator<<(ostream &otm, const Point &pos)
{
    cout << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return otm;
}
