#include "Flight.h"
#include <QDebug>
#include <fstream>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void Flight::Add(string FNumber, string Airways, string StartPoint,
                 string EndPoint, Date *PlanDepartureTime,
                 Date *PlanArrivalTime, int Price, int Tickits)
{
  std::ofstream AddFile("fuck.dat", std::ios::out | std::ios::app); //写入+追加模式

  if (AddFile)
    qDebug() << "打开成功";
  AddFile << FNumber << endl;
  AddFile << Airways << endl;
  AddFile << StartPoint << endl;
  AddFile << EndPoint << endl;
  AddFile << Price << endl;
  AddFile << Tickits << endl;
  qDebug() << "写入！";
  AddFile.close();
}
Flight::~Flight() { ; }
