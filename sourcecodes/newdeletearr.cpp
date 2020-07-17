#include <iostream>

using namespace std;

int main(void)
{
    int i;
    int arr_size = 10;
    int *list = new int[arr_size];

    for (i = 0; i < 10; i++)
    {
        cin >> list[i];
    }

    for (i = 0; i < arr_size; i++)
    {
        cout << "list[" << i << "] : " << list[i] << endl;
    }

    delete[] list;

    return 0;
}