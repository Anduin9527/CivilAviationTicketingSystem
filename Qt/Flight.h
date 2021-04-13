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
  bool Late;

  void Add(Flight &F);
  void Set(Flight &F);
  void Delete(string FNumber);
  Flight *Find(string FNumber);
  Flight() = default;
  ~Flight();
};
