#include <iostream>

using namespace std;

class AAA
{
private:
    int num1;

public:
    virtual void func1() { cout << "Func1" << endl; }
    virtual void func2() { cout << "Func2" << endl; }
};

class BBB : public AAA
{
private:
    int num2;

public:
    virtual void func1() { cout << "BBB::Func1" << endl; }
    void func3() { cout << "Func3" << endl; }
};

int main(void)
{
    AAA *aptr = new AAA();
    aptr->func1();

    BBB *bptr = new BBB();
    bptr->func1();

    delete aptr;
    delete bptr;
    return 0;
}
