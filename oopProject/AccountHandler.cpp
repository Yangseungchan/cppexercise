#include "BankingCommonDecl.h"
#include "AccountHandler.h"

AccountHandler::AccountHandler() : accNum(0)
{
}

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
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이  름: ";
    cin >> name;
    cout << "입금액:  ";
    cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
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
    cout << "계좌ID:  ";
    cin >> id;
    cout << "출금액:  ";
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
