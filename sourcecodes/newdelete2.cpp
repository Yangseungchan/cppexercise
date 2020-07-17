#include <iostream>

int main(void)
{
    int a = 4;
    {
        std::cout << "외부의 변수 1" << a << std::endl;
        int a = 3;
        std::cout << "내부의 변수 " << a << std::endl;
    }

    std::cout << "외부의 변수 2" << a << std::endl;

    return 0;
}