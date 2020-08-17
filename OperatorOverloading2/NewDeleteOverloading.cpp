#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    friend ostream &operator<<(ostream &ostm, const Point &ref);

    void *operator new(size_t size)
    {
        cout << "operator new : " << size << endl;
        void *addr = new char[size];
        return addr;
    }

    void *operator new[](size_t size)
    {
        cout << "operator new[] : " << size << endl;
        void *addr = new char[size];
        return addr;
    }

    void operator delete(void *adr)
    {
        cout << "operator delete ()" << endl;
        delete[]((char *)adr);
    }

    void operator delete[](void *adr)
    {
        cout << "operator delete[] ()" << endl;
        delete[]((char *)adr);
    }
};

ostream &operator<<(ostream &ostm, const Point &ref)
{
    cout << '[' << ref.xpos << ", " << ref.ypos << ']' << endl;
    return ostm;
}

int main(void)
{
    Point *ptr = new Point(3, 4); /* overloaded new operator is called */

    Point *arr = new Point[3]; /* default constructor is called to make array */

    delete ptr;
    delete[] arr;

    return 0;
}