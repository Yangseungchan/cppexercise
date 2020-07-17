#include <iostream>

class A
{
    int x;

public:
    A(int c) : x(c) {}

    int &access_x() { return x; }
    int get_x() { return x; }
    void show_x() { std::cout << x << std::endl; }
};

int main()
{
    A a = A(5); // = A a(5);
    a.show_x();

    int &c = a.access_x();
    c = 4;
    a.show_x();

    int d = a.access_x();

    std::cout << "d : " << d << std::endl;
    d = 3;
    a.show_x();

    // 아래는 오류
    a.get_x();
    // e = 2;
    // a.show_x();

    int f = a.get_x();
    f = 1;
    a.show_x();

    return 0;
}