#pragma once
#include "Date.h"
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
  bool Late{false};

  bool Add(Flight &F);
  bool Set(Flight &F);
  bool Delete(string FNumber);
  void isLate(Flight &F);
  Flight *Find(string FNumber);
  Flight() = default;
  ~Flight();
};
