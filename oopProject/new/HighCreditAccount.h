#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount
{
private:
    int credit_grade;

public:
    HighCreditAccount(int ID, int money, String name, int rate, int grade) : NormalAccount(ID, money, name, rate), credit_grade(grade) {}

    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money);
        Account::Deposit(money * credit_grade / 100.0);
    }
};

#endif