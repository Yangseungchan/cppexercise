#include <iostream>

using namespace std;

template <typename T>

T SumArray(T arr[], int len)
{
    T sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};

    cout << SumArray<int>(arr, 5) << endl;
}