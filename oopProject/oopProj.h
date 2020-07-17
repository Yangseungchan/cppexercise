#ifndef __OOP_PROJ_H__
#define __OOP_PROJ_H__

const int NAME_LEN = 20;

enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

class Account
{
private:
    int accID;
    int balance;
    char *cusName;

public:
    Account(int ID, int money, const char *name);
    Account(const Account &ref);

    int GetAccID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};

class NormalAccount : public Account
{
private:
    int interest_rate;

public:
    NormalAccount(int ID, int money, const char *name, int rate);
    virtual void Deposit(int money);
};

class HighCreditAccount : public NormalAccount
{
private:
    char credit_grade;

public:
    HighCreditAccount(int ID, int money, const char *name, int rate, int grade);
    virtual void Deposit(int money);
};

class AccountHandler
{
private:
    Account *accArr[100];
    int accNum;

public:
    AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    ~AccountHandler();
};

#endif