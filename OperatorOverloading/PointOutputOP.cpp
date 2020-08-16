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
    friend istream &operator>>(istream &itm, Point &pos);
};

ostream &operator<<(ostream &otm, const Point &pos)
{
    otm << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
    return otm;
}

istream &operator>>(istream &itm, Point &pos)
{
    itm >> pos.xpos;
    itm >> pos.ypos;
    return itm;
}

int main(void)
{
    Point pos1;
    cout << "x, y좌표 순으로 입력: ";
    cin >> pos1;
    cout << pos1;

    Point pos2;
    cout << "x, y좌표 순으로 입력: ";
    cin >> pos2;
    cout << pos2;

    return 0;
}
