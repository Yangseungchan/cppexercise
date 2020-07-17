#include <iostream>

using namespace std;

class Date
{
private:
    int year_;
    int month_; // 1 부터 12 까지.
    int day_;   // 1 부터 31 까지.

public:
    void SetDate(int year, int month, int day);
    Date()
    {
        cout << "디폴트 생성자 호출!" << endl;
        year_ = 2000;
        month_ = 1;
        day_ = 1;
    }
    Date(int year, int month, int day)
    {
        cout << "인자 3개 생성자 호출" << endl;
        year_ = year;
        month_ = month;
        day_ = day;
    }
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);
    int GetCurrentMonthTotalDays(int year, int month);
    void ShowDate();
};

void Date::SetDate(int year, int month, int day)
{
    year_ = year;
    month_ = month;
    day_ = day;
}

void Date::AddDay(int inc)
{
    int monthdays = GetCurrentMonthTotalDays(year_, month_);
    day_ += inc;
    while (day_ > monthdays)
    {
        day_ -= monthdays;
        AddMonth(1);
        monthdays = GetCurrentMonthTotalDays(year_, month_);
    }
}

void Date::AddMonth(int inc)
{
    month_ += inc;
    if (month_ > 12)
    {
        AddYear(month_ / 12);
        month_ %= 12;
    }
}

void Date::AddYear(int inc)
{
    year_ += inc;
}

int Date::GetCurrentMonthTotalDays(int year, int month) /* all years are supposed to be bigger than 1000 */
{
    static int MonthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /* MonthDays is only accessible by this function. */
    if (month == 2)
    {
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                {
                    return MonthDays[month] + 1; /* Leap year */
                }
                return MonthDays[month]; /* ordinary year */
            }
            else
            {
                return MonthDays[month] + 1; /* leap year */
            }
        }
    }
    return MonthDays[month];
}

void Date::ShowDate()
{
    cout << year_ << "/" << month_ << "/" << day_ << endl;
}

int main()
{
    Date day = Date(2011, 3, 1);
    Date day2(2020, 4, 8);
    //day.SetDate(2011, 3, 1);
    day.ShowDate();

    day.AddDay(30);
    day.ShowDate();

    day.AddDay(2000);
    day.ShowDate();

    day.SetDate(2012, 1, 31); // 윤년
    day.AddDay(29);
    day.ShowDate();

    day.SetDate(2012, 8, 4);
    day.AddDay(2500);
    day.ShowDate();
    return 0;
}