#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
    int interest_rate;

public:
    NormalAccount(int ID, int money, const char *name, int rate);
    virtual void Deposit(int money);
};

NormalAccount::NormalAccount(int ID, int money, const char *name, int rate) : Account(ID, money, name), interest_rate(rate) {}

void NormalAccount::Deposit(int money)
{
    Account::Deposit(money + (money * interest_rate) / 10);
}

#endif
