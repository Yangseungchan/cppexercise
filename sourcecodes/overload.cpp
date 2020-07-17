#include <iostream>

using namespace std;

void print(int a) { cout << "int : " << a << endl; };
void print(double b) { cout << "double : " << b << endl; };

int main(void)
{
    int n1;
    double d1;

    cin >> n1;
    cin >> d1;

    print(n1);
    print(d1);

    return 0;
}