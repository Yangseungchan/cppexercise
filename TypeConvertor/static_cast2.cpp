#include <iostream>

using namespace std;

int main(void)
{
    int num1 = 20, num2 = 3;

    double result = 20 / 3;

    cout << "result1 : " << result << endl;

    double result2 = static_cast<double>(20) / 3;

    cout << "result2 : " << result2 << endl;
}

