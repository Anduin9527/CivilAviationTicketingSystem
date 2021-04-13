#ifndef CRASA_H
#define CRASA_H
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
bool isRegist(string &ID)
{
  ifstream File("Account.dat",
                std::ios::in);
  string str;
  if (File.is_open())
  {
    while (true)
    {
      if (!(getline(File, str))) //未到末尾
        break;
      if (str == ID)
        return true;
    }
  }
  return false;
}
void Encode(string &ID, string &str, int k = 5) //加密
{
  ofstream File("Account.dat",
                std::ios::out | std::ios::app);
  File << ID << endl;
  for (unsigned int i = 0; i < str.length(); i++)
  {
    if (97 <= str[i] && str[i] <= 122) //小写
    {
      str[i] = ((str[i] + k - 97) % 26) + 97;
      File << str[i];
    }
    else if (65 <= str[i] && str[i] <= 90) //大写
    {
      str[i] = ((str[i] + k - 65) % 26) + 65;
      File << str[i];
    }
    else if (48 <= str[i] && str[i] <= 57) //数字
    {
      str[i] = ((str[i] + k - 48) % 10) + 48;
      File << str[i];
    }
    else
      File << str[i];
  }
  File << endl;
  File.close();
}
string Decode(string &ID, int k = 5) //解密
{
  ifstream File("Account.dat",
                std::ios::in);
  string str;
  if (File.is_open())
  {
    while (true)
    {
      if (!(getline(File, str))) //未到末尾
        break;
      if (str == ID)
      {
        getline(File, str);
        break;
      }
    }
  }
  File.close();
  // cout << str;
  string ans;
  for (unsigned int i = 0; i < str.length(); i++)
  {
    if (97 <= str[i] && str[i] <= 122) //小写
    {
      str[i] = ((str[i] - k - 122) % 26) + 122;
      ans += str[i];
    }
    else if (65 <= str[i] && str[i] <= 90) //大写
    {
      str[i] = ((str[i] - k - 90) % 26) + 90;
      ans += str[i];
    }
    else if (48 <= str[i] && str[i] <= 57) //数字
    {
      str[i] = ((str[i] - k - 57) % 10) + 57;
      ans += str[i];
    }
    else
      ans += str[i];
  }
  return ans;
}

#endif // CRASA_H
