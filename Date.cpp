#include "inc\Date.h"
#include <iostream>
using std::cout;
using std::endl;
Date::Date(int a, int b, int c, int d, int e) : year(a), month(b), day(c), hour(d), minute(e) //��ʼ������
{
  if (year < 0)
    cout << "��ݴ���" << endl;
  if (month < 1 || month > 12)
    cout << "�·ݴ���" << endl;
  // if (day < 1 || day > 31)
  //     cout << "���ڴ���" << endl;
  if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31))
    cout << "���ڴ���" << endl;
  if ((month == 4 || month == 5 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
    cout << "���ڴ���" << endl;
  if ((year % 4 == 0 && year % 100 > 0) || year % 400 == 0)
  {
    if (month == 2 && day > 29)
      cout << "���ڴ���" << endl;
  }
  else
  {
    if (month == 2 && day > 28)
      cout << "���ڴ���" << endl;
  }
}

void Date::getDate()
{
  cout << year << "��" << month << "��" << day << "��" << hour << "ʱ" << minute << "��" << endl;
}
Date::~Date()
{
}
