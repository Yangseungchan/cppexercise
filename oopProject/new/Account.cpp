#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account()
{
    accID = balance = 0;
    cusName = String("");
}

Account::Account(int ID, int money, String name) : accID(ID), balance(money)
{
    cusName = String(name);
}

Account::Account(const Account &ref) : accID(ref.accID), balance(ref.balance)
{
    cusName = ref.cusName;
}

Account &Account::operator=(const Account &ref)
{
    accID = ref.accID;
    balance = ref.balance;
    cusName = ref.cusName;
    return *this;
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money)
{
    balance += money;
}

int Account::Withdraw(int money)
{
    if (balance < money)
        return 0;
    balance -= money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout << "계좌ID : " << accID << endl;
    cout << "이  름 : " << cusName << endl;
    cout << "잔  액 : " << balance << endl;
}

Account::~Account()
{
}