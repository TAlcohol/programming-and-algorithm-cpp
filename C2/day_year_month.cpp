#include <iostream>
using namespace std;

/* 2000年1月1日是 Saturday，输入一个数字n，计算2000年1月1日后面的n天是几年几月几日星期几 */
/* 例如输入 2，输出应该是 2000-1-3-Monday */

int days;
int get_dayofweek();
int get_year();
int get_month(int);

int main()
{
    int year, month, dayofweek;
    int leap_year;
    char week[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    /* 输入的 days 不是整数，或者等于 -1 时，结束输入循环 */
    while ((cin >> days) && days != -1)
    {
        dayofweek = get_dayofweek();
        year = get_year();
        leap_year = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
        month = get_month(leap_year);
        cout << year << "-" << month << "-" << ++days << "-" << week[dayofweek];
    }
    return 0;
}

int get_dayofweek()
{
    int dayofweek;
    dayofweek = days % 7;
    return dayofweek;
}

int get_year()
{
    int i = 2000, leap_year;
    while (1)
    {
        leap_year = (i % 4 == 0 && i % 100 != 0 || i % 400 == 0);
        if (leap_year == 1 && days >= 366)
        {
            days = days - 366;
            i++;
            continue;
        }
        else if (leap_year == 0 && days >= 365)
        {
            days = days - 365;
            i++;
            continue;
        }
        else
            break;
    }
    return i;
}

int get_month(int leap_year)
{
    int pmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int rmonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int j = 0;
    while (1)
    {
        if (leap_year == 1 && days >= rmonth[j])
        {
            days = days - rmonth[j];
            j++;
        }
        else if (leap_year == 0 && days >= pmonth[j])
        {
            days = days - pmonth[j];
            j++;
        }
        else
            break;
    }
    return ++j;
}