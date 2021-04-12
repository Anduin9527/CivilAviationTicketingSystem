#pragma once
#include <string>
#include "Date.h"
using std::string;
class Flight
{
public:
  string FNumber;
  string Airways;
  string startPoint;
  string endPoint;
  Date PlanDepartureTime;
  Date PlanArrivalTime;
  int Price;
  int RemainTickit;
  bool Late;

private:
  void Add(string FNumber, string Airways,
           string startPoint, string endPoint,
           Date PlanDepartureTime, Date PlanArrivalTime,
           int Price, int Tickits);
  void Set(string FNumber, string Airways,
           string startPoint, string endPoint,
           Date PlanDepartureTime, Date PlanArrivalTime,
           int Price, int Tickits);

};