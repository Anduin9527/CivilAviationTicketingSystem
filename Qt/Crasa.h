#ifndef CRASA_H
#define CRASA_H
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void Encode(string &s, int k = 5) //加密
{
  ofstream File("Account.dat",
                std::ios::out | std::ios::app);
  for (unsigned int i = 0; i < s.length(); i++)
  {
    if (97 <= s[i] && s[i] <= 122) //小写
    {
      s[i] = ((s[i] + k - 97) % 26) + 97;
      File << s[i];
    }
    else if (65 <= s[i] && s[i] <= 90) //大写
    {
      s[i] = ((s[i] + k - 65) % 26) + 65;
      File << s[i];
    }
    else if (48 <= s[i] && s[i] <= 57) //数字
    {
      s[i] = ((s[i] + k - 48) % 10) + 48;
      File << s[i];
    }
    else
      File << s[i];
  }
  File << endl;
}
// void Encode(string &s, int k = 5) //解密
// {
//   ofstream File("Account.dat",
//                 std::ios::out | std::ios::app);
//   for (unsigned int i = 0; i < s.length(); i++)
//   {
//     if (97 <= s[i] && s[i] <= 122) //小写
//     {
//       s[i] = ((s[i] + k - 97) % 26) + 97;
//       File << s[i];
//     }
//     else if (65 <= s[i] && s[i] <= 90) //大写
//     {
//       s[i] = ((s[i] + k - 65) % 26) + 65;
//       File << s[i];
//     }
//     else if (48 <= s[i] && s[i] <= 57) //数字
//     {
//       s[i] = ((s[i] + k - 48) % 10) + 48;
//       File << s[i];
//     }
//     else
//       File << s[i];
//   }
//   File << endl;
// }
#endif // CRASA_H
