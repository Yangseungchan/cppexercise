#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const { cout << "[" << xpos << ", " << ypos << "]" << endl; }

    friend ostream &operator<<(ostream &otm, const Point &pos);
};

ostream &operator<<(ostream &otm, const Point &pos)
{
    otm << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
    return otm;
}

int main(void)
{
    Point pos(3, 4);

    cout << pos;

    /* cout.operator<<(pos) [멤버함수]; operator<<(cout, pos) [전역함수];*/

    return 0;
}

