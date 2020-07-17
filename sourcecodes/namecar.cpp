#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

namespace COMP_POS
{
    enum
    {
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };
}

class NameCard
{
private:
    char *username;
    char *company;
    char *phonenum;
    int grade;

public:
    NameCard(const char *user_name, const char *company_name, const char *phone_num, const int _grade);
    NameCard(const NameCard &ncd)
    {
        username = new char[strlen(ncd.username) + 1];
        strcpy(username, ncd.username);

        company = new char[strlen(ncd.company) + 1];
        strcpy(company, ncd.company);

        phonenum = new char[strlen(ncd.phonenum) + 1];
        strcpy(phonenum, ncd.phonenum);
    }

    void ShowNameCardInfo();

    ~NameCard()
    {
        delete[] username;
        delete[] company;
        delete[] phonenum;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);

    NameCard copy1 = manClerk;

    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

    NameCard copy2 = manAssist;

    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

    return 0;
}

NameCard::NameCard(const char *user_name, const char *company_name, const char *phone_num, const int _grade)
{
    int name_len, comp_len, phone_len;

    name_len = strlen(user_name) + 1;
    username = new char[name_len];
    strcpy(username, user_name);

    comp_len = strlen(company_name) + 1;
    company = new char[comp_len];
    strcpy(company, company_name);

    phone_len = strlen(phone_num) + 1;
    phonenum = new char[phone_len];
    strcpy(phonenum, phone_num);

    grade = _grade;
}

void NameCard::ShowNameCardInfo()
{
    cout << "이름 : " << username << endl;
    cout << "회사 : " << company << endl;
    cout << "전화번호 : " << phonenum << endl;
    cout << "직급 : ";
    switch (grade)
    {
    case COMP_POS::CLERK:
        cout << "사원" << endl;
        break;
    case COMP_POS::SENIOR:
        cout << "주임" << endl;
        break;
    case COMP_POS::ASSIST:
        cout << "대리" << endl;
        break;
    case COMP_POS::MANAGER:
        cout << "과장" << endl;
        break;
    }
}