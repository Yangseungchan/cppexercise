#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const { cout << "[" << xpos << ", " << ypos << "]" << endl; }

    // cin >> pos = cin.operator>>(const Point &pos)
    // [전역함수] operator>>(istream &itm, const Point &pos)
    friend istream &operator>>(istream &itm, Point &pos);
    friend ostream &operator<<(ostream &otm, const Point &pos);
};

istream &operator>>(istream &itm, Point &pos)
{
    itm >> pos.xpos >> pos.ypos;
    return itm;
}

ostream &operator<<(ostream &otm, const Point &pos)
{
    otm << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
    return otm;
}

int main(void)
{
    Point pos1;
    cout << "x, y 좌표 순으로 입력: ";
    cin >> pos1;
    cout << pos1;

    Point pos2;
    cout << "x, y좌표 순으로 입력: ";
    cin >> pos2;
    cout << pos2;

    return 0;
}
