#include <iostream>

using namespace std;

class Base
{
public:
    void BaseFunc() { cout << "Base Function" << endl; }
};

class Derived : public Base
{
public:
    void DerivedFunc() { cout << "Derived Function" << endl; }
};

int main(void)
{
    Base *bptr = new Derived(); /* 기본클래스 객체 포인터 bptr이 새로 할당되는 유도 클래스 객체를 가리키므로 문제가 없다.*/
    Derived *dptr = bptr;       /* 유도클래스 객체 포인터 dptr이 기본 클래스 객체의 주솟값을 가리키므로 에러가 발생한다. */
}
