#include "Flight.h"
#include <QDebug>
#include <fstream>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void Flight::Add(Flight &F) {
  std::ofstream AddFile(F.FNumber + ".dat",
                        std::ios::out | std::ios::app); //写入+追加模式

  if (AddFile)
    qDebug() << "打开成功";
  AddFile << F.FNumber << endl;
  AddFile << F.Airways << endl;
  AddFile << F.StartPoint << endl;
  AddFile << F.EndPoint << endl;
  //在这里插入日期
  AddFile << F.Price << endl;
  AddFile << F.RemainTickit << endl;
  qDebug() << "写入！";
  AddFile.close();
}
Flight::~Flight() { ; }
