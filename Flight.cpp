#include "inc/Flight.h"
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

Flight *Flight::Add(string FNumber, string Airways,
                    string startPoint, string EndPoint,
                    Date PlanDepartureTime, Date PlanArrivalTime,
                    int Price, int Tickits)
{
  this->FNumber = FNumber;
  this->Airways = Airways;
  this->StartPoint = startPoint;
  this->EndPoint = EndPoint;
  this->PlanDepartureTime = PlanDepartureTime;
  this->PlanArrivalTime = PlanArrivalTime;
  this->Price = Price;
  this->RemainTickit = Tickits;
  return this;
}