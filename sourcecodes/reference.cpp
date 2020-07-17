#include <iostream>

using namespace std;

int change_val(int &p)
{
    p = 3; /* p는 x의 참조자로 선언 및 정의 되기 때문에(int &p = x;), c에서와 달리 포인터를 사용하지 않아도 값이 변경된다 */

    return 0;
}

int main()
{
    int x;
    int &y = x;
    const int &z = 4;

    x = 5;

    cout << x << endl;

    change_val(x);

    cout << x << endl;
    cout << "z : " << z << endl;

    return 0;
}