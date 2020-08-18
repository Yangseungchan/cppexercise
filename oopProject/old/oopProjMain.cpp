#include <iostream>
#include <cstring>
#include "oopProj.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    AccountHandler manager;
    int choice;
    while (1)
    {
        manager.ShowMenu();
        cout << "선택:  ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}