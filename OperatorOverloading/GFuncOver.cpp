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
    friend Point operator+(const Point &p1, const Point &p2);
    friend Point operator-(const Point &p1, const Point &p2);
};

Point operator+(const Point &p1, const Point &p2)
{
    Point pos(p1.xpos + p2.xpos, p1.ypos + p2.ypos);
    return pos;
}

Point operator-(const Point &p1, const Point &p2)
{
    Point pos(p1.xpos - p2.xpos, p1.ypos - p2.ypos);
    return pos;
}

int main(void)
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1 + pos2;
    Point pos4 = pos1 - pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    pos4.ShowPosition();
}