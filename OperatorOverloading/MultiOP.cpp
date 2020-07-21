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
};

int main(void)
{
    Point obj(3, 4);

    Point cpy = obj * 2;

    cpy.ShowPosition();
    return 0;
}
