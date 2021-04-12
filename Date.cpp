#include "inc\Date.h"
#include <iostream>
using std::cout;
using std::endl;
Date::Date(int a, int b, int c, int d, int e) : year(a), month(b), day(c), hour(d), minute(e) //初始化数据
{
  if (year < 0)
    cout << "年份错误" << endl;
  if (month < 1 || month > 12)
    cout << "月份错误" << endl;
  // if (day < 1 || day > 31)
  //     cout << "日期错误" << endl;
  if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31))
    cout << "日期错误" << endl;
  if ((month == 4 || month == 5 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
    cout << "日期错误" << endl;
  if ((year % 4 == 0 && year % 100 > 0) || year % 400 == 0)
  {
    if (month == 2 && day > 29)
      cout << "日期错误" << endl;
  }
  else
  {
    if (month == 2 && day > 28)
      cout << "日期错误" << endl;
  }
}

void Date::getDate()
{
  cout << year << "年" << month << "月" << day << "日" << hour << "时" << minute << "分" << endl;
}
Date::~Date()
{
}
