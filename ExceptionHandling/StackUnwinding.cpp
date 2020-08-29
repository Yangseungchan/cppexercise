#include <iostream>

using namespace std;

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void)
{
    try
    {
        {
            SimpleFuncOne();
        }
    }
    catch (int excp)
    {
        cout << "예외코드 : " << excp << endl;
    }
}

void SimpleFuncOne(void)
{
    cout << "SimpleFuncOne()" << endl;
    SimpleFuncTwo();
}

void SimpleFuncTwo(void)
{
    cout << "SimpleFuncTwo()" << endl;
    SimpleFuncThree();
}

void SimpleFuncThree(void)
{
    cout << "SimpleFuncThree()" << endl;
    throw -1;
}
