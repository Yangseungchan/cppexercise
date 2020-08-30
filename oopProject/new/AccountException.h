#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "BankingCommonDecl.h"

class WithdrawException
{
private:
    int balance;

public:
    WithdrawException(int money) : balance(money) {}
    void ShowExceptionReason()
    {
        cout << "잔액이 부족합니다." << endl;
    }
    int inputmoney()
    {
        int money;
        cout << "출금액을 다시 입력하세요" << endl;
        cout << "출금액:  ";
        cin >> money;
        return money;
    }
};

class MoneyNegativeException
{
private:
    int situation;
    /* 1 = Deposit, 2 = Withdraw */
    int balance;

public:
    MoneyNegativeException(int sit, int money) : situation(sit), balance(money) {}

    void ShowExceptionReason()
    {
        cout << (situation == 1 ? "입금액" : "출금액");
        cout << "이 음수입니다." << endl;
    }

    int inputmoney()
    {
        int money;
        cout << (situation == 1 ? "입금액" : "출금액");
        cout << "을 다시 입력하세요" << endl;
        cout << (situation == 1 ? "입금액:  " : "출금액:  ");
        cin >> money;
        return money;
    }
};

#endif