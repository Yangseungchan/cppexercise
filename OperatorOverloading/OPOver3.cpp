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

    friend bool operator==(const Point &ref1, const Point &ref2);
    friend bool operator!=(const Point &ref1, const Point &ref2);

    Point &operator+=(const Point &ref)
    {
        xpos += ref.xpos;
        ypos += ref.ypos;
        return *this;
    }

    Point &operator-=(const Point &ref)
    {
        xpos -= ref.xpos;
        ypos -= ref.ypos;
        return *this;
    }
};

bool operator==(const Point &ref1, const Point &ref2)
{
    if (ref1.xpos == ref2.xpos && ref1.ypos == ref2.ypos)
    {
        return true;
    }
    return false;
}

bool operator!=(const Point &ref1, const Point &ref2)
{
    if (ref1 == ref2) /* ref1 == ref2 returns true */
    {
        return false;
    }
    return true;
}

int main(void)
{
    Point pos1(3, 4);
    Point pos2(3, 4);

    pos1.ShowPosition();
    pos2.ShowPosition();

    /*pos1 += pos2;
    pos1.ShowPosition();*/

    /*pos1 -= pos2;
    pos1.ShowPosition();*/

    if (pos1 == pos2)
    {
        cout << "SAME POSs" << endl;
    }
    else
    {
        cout << "NOT SAME" << endl;
    }

    if (pos1 != pos2)
    {
        cout << "NOT SAME" << endl;
    }
    else
    {
        cout << "SAME" << endl;
    }
}