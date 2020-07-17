#include <iostream>

using namespace std;

void print_square(int num);

int main(void)
{
    int user_input;
    cout << "input the number : ";
    cin >> user_input;

    print_square(user_input);

    return 0;
}

void print_square(int num)
{
    cout << "result : " << num * num << endl;
}