#include "Sort.h"
#include <QDebug>
#include <algorithm>
#include <fstream>
F f[1000];
bool Cmp(const F &a, const F &b) {
  return a.PlanDepartureTime < b.PlanDepartureTime;
}
void Fin(int num) {
  ofstream fin("Sort.dat", ios::out);
  if (fin.rdbuf()->sgetc() != char_traits<char>::eof()) {
    fin.close();
    remove("Sort.dat");
    ofstream fin("Sort.dat", ios::out);
  }
  for (int i = 0; i < num; i++) {
    fin << f[i].FNumber << endl;
    fin << f[i].Airways << endl;
    fin << f[i].StartPoint << endl;
    fin << f[i].EndPoint << endl;
    fin << f[i].PlanDepartureTime << endl;
    fin << f[i].PlanArrivalTime << endl;
    fin << f[i].Price << endl;
    fin << f[i].RemainTickit << endl;
    fin << f[i].Late << endl;
  }
  fin.close();
}
int Sort() {
  int num = 0;
  fstream File("flight.dat", ios::in | ios::out);
  string str;
  if (File.is_open()) {
    while (true) {
      if (!(getline(File, str))) //未到末尾
        break;
      else {
        if (str.empty())
          continue; //跳过空行
        f[num].FNumber = str;
        getline(File, str);
        f[num].Airways = str;
        getline(File, str);
        f[num].StartPoint = str;
        getline(File, str);
        f[num].EndPoint = str;
        getline(File, str);
        f[num].PlanDepartureTime = str;
        getline(File, str);
        f[num].PlanArrivalTime = str;
        getline(File, str);
        f[num].Price = str;
        getline(File, str);
        f[num].RemainTickit = str;
        getline(File, str);
        f[num].Late = str;
        num++;
      }
    }
  }
  File.close();
  sort(f, f + num, Cmp);
  Fin(num);
  return num;
}
