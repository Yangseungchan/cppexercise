#include <iostream>

using namespace std;

int change_val(int &p)
{
    p = 3;
    return 0;
}

int main(void)
{
    int x = 10;
    int arr[3] = {1, 2, 3};
    int(&ref)[3] = arr;

    ref[0] = 2;
    ref[1] = 4;
    ref[2] = 6;

    cout << arr[0] << arr[1] << arr[2] << endl;
    cout << "value of x : " << x << endl;
    change_val(x);
    cout << "value of x : " << x << endl;

    return 0;
}