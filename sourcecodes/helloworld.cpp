#include <iostream>

using namespace std;

int main(void)
{
    int i, lucky_number;
    lucky_number = 7;

    cin >> i;

    if (i == lucky_number)
    {
        cout << "It is lucky number" << endl;
    }
    else
    {
        cout << "It is not lucky number but " << i << endl;
    }

    return 0;
}