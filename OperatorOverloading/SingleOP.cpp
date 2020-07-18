#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {
    }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point operator-()
    {
        Point pos(xpos * -1, ypos * -1);
        return pos;
    }
    Point &operator++()
    {
        xpos++;
        ypos++;
        return *this;
    }
    friend Point &operator--(Point &pos);
    friend Point operator~(Point &pos);
};

Point &operator--(Point &pos)
{
    pos.xpos--;
    pos.ypos--;
    return pos;
}

Point operator~(Point &pos)
{
    Point ptr(pos.ypos, pos.xpos);
    return ptr;
}

int main(void)
{
    Point pos1(3, 4);
    Point pos2 = -pos1;
    Point pos3 = ~pos1;

    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}
