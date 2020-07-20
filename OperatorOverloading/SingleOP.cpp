#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point &operator++()
    {
        xpos++;
        ypos++;
        return *this;
    }

    const Point operator++(int)
    {
        const Point retobj(xpos, ypos);
        xpos += 1;
        ypos += 1;
        return retobj;
    }

    friend Point &operator--(Point &pos);
    friend const Point operator--(Point &pos, int);
};

Point &operator--(Point &pos)
{
    pos.xpos--;
    pos.ypos--;
    return pos;
}

const Point operator--(Point &pos, int)
{
    const Point retobj(pos);
    pos.xpos -= 1;
    pos.ypos -= 1;
    return retobj;
}

int main(void)
{
    Point pos(3, 5);
    Point cpy;

    int n1 = 2;

    cpy = pos--;
    cpy.ShowPosition();
    pos.ShowPosition();

    cpy = pos++;
    cpy.ShowPosition();
    pos.ShowPosition();

    ++(++pos);

    return 0;
}
