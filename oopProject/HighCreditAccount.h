#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include <NormalAccount.h>

class HighCreditAccount : public NormalAccount
{
private:
    char credit_grade;

public:
    HighCreditAccount(int ID, int money, const char *name, int rate, int grade);
    virtual void Deposit(int money);
};

HighCreditAccount::HighCreditAccount(int ID, int money, const char *name, int rate, int grade) : NormalAccount(ID, money, name, rate), credit_grade(grade) {}

void HighCreditAccount::Deposit(int money)
{
    NormalAccount::Deposit(money);
    Account::Deposit(money * credit_grade / 10);
}

#endif