#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
typedef struct flight //结构体数组排序
{
  string FNumber;
  string Airways;
  string StartPoint;
  string EndPoint;
  string PlanDepartureTime;
  string PlanArrivalTime;
  string Price;
  string RemainTickit;
  string Late;
} F;
F f[1000];
int num = 0; //组数
bool Cmp(const F &a, const F &b) {
  return a.PlanDepartureTime < b.PlanDepartureTime;
}
void Fin() {
  fstream File("Sort.dat", ios::out | ios::in);
  if (File.peek() != EOF) {
    File.close();
    remove("Sort.dat");
    fstream File("Sort.dat", ios::out);
  }
  for (int i = 0; i < num; i++) {
    File << f[i].FNumber << endl;
    File << f[i].Airways << endl;
    File << f[i].StartPoint << endl;
    File << f[i].EndPoint << endl;
    File << f[i].PlanDepartureTime << endl;
    File << f[i].PlanArrivalTime << endl;
    File << f[i].Price << endl;
    File << f[i].RemainTickit << endl;
    File << f[i].Late << endl;
  }
}
void Sort() {

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
  Fin();
}
