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
  Date *PlanDepartureTime;
  Date *PlanArrivalTime;
  int Price;
  int RemainTickit;
  bool Late;

  void Add(Flight &F);
  void Set(Flight &F);
  void Delete(string FNumber);
  Flight *Find(string FNumber);
  Flight() = default;
  ~Flight();
};
