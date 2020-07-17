#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class Rectangle
{
private:
    int width;
    int height;

public:
    Rectangle(int wd, int ht) : width(wd), height(ht) {}
    void ShowAreaInfo()
    {
        cout << "면적 : " << width * height << endl;
    }
};

class Square : public Rectangle
{
private:
public:
    Square(int length) : Rectangle(length, length) {}
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}