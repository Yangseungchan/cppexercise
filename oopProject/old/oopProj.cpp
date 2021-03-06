#include <iostream>
#include <cstring>
#include "oopProj.h"

using std::cin;
using std::cout;
using std::endl;

Account::Account(int ID, int money, const char *name) : accID(ID), balance(money)
{
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
}

Account::Account(const Account &ref) : accID(ref.accID), balance(ref.balance)
{
    cusName = new char[strlen(ref.cusName) + 1];
    strcpy(cusName, ref.cusName);
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
    delete[] cusName;
}

NormalAccount::NormalAccount(int ID, int money, const char *name, int rate) : Account(ID, money, name), interest_rate(rate) {}

void NormalAccount::Deposit(int money)
{
    Account::Deposit(money + (money * interest_rate) / 100);
}

HighCreditAccount::HighCreditAccount(int ID, int money, const char *name, int rate, int grade) : NormalAccount(ID, money, name, rate) {
  switch(grade)
  {
    case 1:
      credit_grade = 7;
      break;
    case 2:
      credit_grade = 4;
      break;
    case 3:
      credit_grade = 2;
      break;
  }
}

void HighCreditAccount::Deposit(int money)
{
    NormalAccount::Deposit(money);
    Account::Deposit(money * credit_grade / 100);
}

AccountHandler::AccountHandler() : accNum(0){}

void AccountHandler::ShowMenu(void) const
{
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입   금" << endl;
    cout << "3. 출   금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
    int id, choice;
    char name[NAME_LEN];
    int balance, rate, grade;

    cout << "[계좌종류선택]"<<endl;
    cout << "1. 보통예금계좌 2.신용신뢰계좌" << endl;
    cout << "선택: "; cin >> choice;
    
    switch(choice)
    {
      case 1:
        cout << "[보통예금계좌 개설]" << endl;
        break;
      case 2:
        cout << "[신용신뢰계좌 개설]" << endl;
        break;
    }
    cout << "계좌ID: ";
    cin >> id;
    cout << "이  름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> balance;
    cout << "이자율: ";
    cin >> rate;
    if(choice == 2)
    {
      cout << "신용등급(1toA, 2toB, 3toC): "; 
      cin >> grade; 
    }
    cout << endl;

    switch(choice)
    {
      case 1:
        accArr[accNum++] = new NormalAccount(id, balance, name, rate);
        break;
      case 2:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, rate, grade);
        break;
    }
    return;
}

void AccountHandler::DepositMoney(void)
{
    int money;
    int id;
    cout << "[입   금]" << endl;
    cout << "걔좌ID: ";
    cin >> id;
    cout << "입금액: ";
    cin >> money;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout << "입금완료" << endl
                 << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl
         << endl;
}

void AccountHandler::WithdrawMoney(void)
{
    int money;
    int id;
    cout << "[출   금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "출금액: ";
    cin >> money;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            if (accArr[i]->Withdraw(money) == 0)
            {
                cout << "잔액부족" << endl
                     << endl;
                return;
            }
            cout << "출금완료" << endl
                 << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl
         << endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{
    for (int i = 0; i < accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++)
    {
        delete accArr[i];
    }
}
