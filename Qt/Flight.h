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
  Date PlanDepartureTime;
  Date PlanArrivalTime;
  int Price;
  int RemainTickit;
  bool Late;
  Flight() = default;
  ~Flight();

private:
  void Add(string FNumber, string Airways, string StartPoint,
              string EndPoint, Date PlanDepartureTime, Date PlanArrivalTime,
              int Price, int Tickits);
  void Set(string FNumber, string Airways, string StartPoint, string EndPoint,
           Date PlanDepartureTime, Date PlanArrivalTime, int Price,
           int Tickits);
  void Delete(string FNumber);
};
