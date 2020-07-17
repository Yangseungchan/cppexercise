#include <iostream>

using namespace std;

class Base
{
private: /* Base 클래스 내에서만 접근 가능 */
    int num1;

protected:
    int num2;

public:
    int num3;
};

class Derive : private Base
{
public:
private: /* Derive 클래스 내에서만 접근 가능 */
    int num2;

private: /* Derive 클래스 내에서만 접근 가능 */
    int num3;
};

class DeDerive : private Derive
{
public:
    /*
        상속받을 수 있는 멤버가 없음

    */
};
