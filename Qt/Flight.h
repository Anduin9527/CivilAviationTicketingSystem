#pragma once
#include <string>
using std::string;
class Flight {
public:
  string FNumber;
  string Airways;
  string StartPoint;
  string EndPoint;
  string PlanDepartureTime;
  string PlanArrivalTime;
  int Price;
  int RemainTickit;
  bool Late{0};//初始化为0

  bool Add(Flight &F);
  bool Set(Flight &F);
  bool Delete(string FNumber);
  bool isLate(Flight &F);
  Flight *Find(string FNumber);
  Flight() = default;
  ~Flight();
};
