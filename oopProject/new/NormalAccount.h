#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"

class NormalAccount : public Account
{
private:
    int interest_rate;

public:
    NormalAccount(int ID, int money, String name, int rate) : Account(ID, money, name), interest_rate(rate) {}
    virtual void Deposit(int money)
    {
        Account::Deposit(money + (money * interest_rate) / 100.0);
    }
};

#endif
