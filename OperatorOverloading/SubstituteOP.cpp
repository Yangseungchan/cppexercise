#include <iostream>

using namespace std;

class First
{
private:
    int num1, num2;

public:
    First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2) {}
    void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
    int num3, num4;

public:
    Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4) {}
    void ShowData() { cout << num3 << ", " << num4 << endl; }

    Second &operator=(const Second &ref)
    {
        cout << "Second& operator=()" << endl;
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
};

int main(void)
{
    First fsrc(111, 222);
    First fcpy;

    Second ssrc(333, 444);
    Second scpy;

    fcpy = fsrc; /* 대입연산자가 정의 되지 않았음에도 얕은복사를 진행하는 디폴트 대입 연산자가 자동 삽입된다 */
    scpy = ssrc;
    fcpy.ShowData();
    scpy.ShowData();

    First fob1, fob2;
    Second sob1, sob2;
    fob1 = fob2 = fcpy;

    /*  fob1 = fob2 = fcpy 해석 

    1. fob2 = fcpy에 의해 fob2의 디폴트 대입 연산자가 발동되어 fob2에 fcpy의 정보가 대입, 이후 fob2 객체의 레퍼런스가 반환 

    2. 이후 fob1 = 이하의 문장이 실행되기 때문에 fob1에 fob2의 정보가 대입 
    
    */

    sob1 = sob2 = scpy;

    fob1.ShowData();
    fob2.ShowData();
    sob1.ShowData();
    sob2.ShowData();
    return 0;
}
