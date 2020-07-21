#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
    Point operator*(int times) /* obj.operator*(2) = obj * 2 */
    {
        Point retobj(xpos * times, ypos * times);
        return retobj;
    }

    friend Point operator*(int times, Point &obj); /* operator*(3, obj) = 3 * obj; */
};

Point operator*(int times, Point &obj)
{
    Point pos(obj.xpos * times, obj.ypos * times);
    return pos;
    //return obj * times;
}

int main(void)
{
    Point obj(3, 4);

    Point cpy = obj * 2;

    cpy.ShowPosition();

    cpy = 3 * obj;

    cpy.ShowPosition();

    cpy = 3 * obj * 2;

    cpy.ShowPosition();

    return 0;
}
