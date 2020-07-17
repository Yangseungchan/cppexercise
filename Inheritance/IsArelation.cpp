#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class Computer
{
private:
    char owner[50];

public:
    Computer(const char *name)
    {
        strcpy(owner, name);
    }

    void Calculate()
    {
        cout << "요청 내용을 계산합니다." << endl;
    }
};

class NotebookComp : public Computer
{
private:
    int Battery;

public:
    NotebookComp(const char *name, int initChag) : Computer(name), Battery(initChag) {}
    void Charging() { Battery += 5; }
    void UseBattery() { Battery -= 1; }
    int GetBatteryInfo() { return Battery; }
    void MovingCal()
    {
        if (GetBatteryInfo() < 1)
        {
            cout << "충전이 필요합니다." << endl;
            return;
        }
        cout << "이동하면서 ";
        Calculate();
        UseBattery();
    }
};

class TableNotebook : public NotebookComp
{
private:
    char regstPenMode1[50];

public:
    TableNotebook(const char *name, int initChag, const char *pen) : NotebookComp(name, initChag)
    {
        strcpy(regstPenMode1, pen);
    }

    void Write(const char *penInfo)
    {
        if (GetBatteryInfo() < 1)
        {
            cout << "충전이 필요합니다." << endl;
            return;
        }
        if (strcmp(regstPenMode1, penInfo))
        {
            cout << "등록된 펜이 아닙니다." << endl;
            return;
        }
        UseBattery();
    }
};

int main(void)
{
    NotebookComp nc("이수종", 5);
    TableNotebook tn("정수영", 5, "NotePenS");

    nc.MovingCal();
    tn.Write("NotePen");
    return 0;
}