#include <iostream>

class A
{
    int x;

public:
    A(int c)
    {
        x = c;
        std::cout << "A(int c) is executed" << std::endl;
    }
    A(const A &a)
    {
        x = a.x;
        std::cout << "복사 생성" << std::endl;
    }

    void print_x()
    {
        std::cout << x << std::endl;
    }
};

class B
{
    A a;

public:
    B(int c) : a(c) {}
    B(const B &b) : a(b.a) {}
    A get_A()
    {
        A temp(a);
        return temp; /* temp라는 객체를 복사하기 위해 복사 생성자 사용 */
    }
};

int main()
{
    A a2 = 10;
    std::cout << "---------" << std::endl;
    a2.print_x();
}