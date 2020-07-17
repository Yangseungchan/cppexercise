#include <stdio.h>

int change_val(int n)
{
    n = 3;
    return 0;
}

int main(void)
{
    int num;

    num = 5;

    change_val(num);

    printf("%d\n", num);

    return 0;
}