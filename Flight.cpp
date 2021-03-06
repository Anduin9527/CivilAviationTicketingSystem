#include "Flight.h"
#include <QDebug>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
bool Flight::isLate(Flight &F) {
  std::ifstream File(F.FNumber + ".dat",
                     std::ios::in); //读
  string buf;
  if (File && File.peek() != EOF) {
    int n = 8;
    while (n--)
      getline(File, buf); //跳过前八行数据，读取第九行late
  }
  qDebug() << QString::fromStdString(buf);
  return std::stoi(buf);
}

bool Flight::Add(Flight &F) {
  bool flag = false;
  std::fstream AddFile(FNumber + ".dat",
                       std::ios::in | std::ios::out | std::ios::app); //读写

  if (AddFile && AddFile.peek() == EOF) //文件正确打开且空
  {
    qDebug() << "打开成功!";
    AddFile.clear(); // JC_YYDS！！！
    AddFile << F.FNumber << endl;
    AddFile << F.Airways << endl;
    AddFile << F.StartPoint << endl;
    AddFile << F.EndPoint << endl;
    AddFile << F.PlanDepartureTime << endl;
    AddFile << F.PlanArrivalTime << endl;
    AddFile << F.Price << endl;
    AddFile << F.RemainTickit << endl;
    AddFile << F.Late << endl;
    qDebug() << "写入！";
    flag = 1;
  }

  std::ofstream File("flight.dat",
                     std::ios::out | std::ios::app); //写入+追加模式
  if (File && flag) { //文件正确打开且不是重复写入
    qDebug() << "打开flight成功!";
    File << F.FNumber << endl;
    File << F.Airways << endl;
    File << F.StartPoint << endl;
    File << F.EndPoint << endl;
    File << F.PlanDepartureTime << endl;
    File << F.PlanArrivalTime << endl;
    File << F.Price << endl;
    File << F.RemainTickit << endl;
    File << F.Late << endl;
    AddFile.close();
    File.close();
  }
  return flag;
}
bool Flight::Delete(string FNumber) {
  bool flag = false;
  if (remove((FNumber + ".dat").c_str()) == 0) //删除原文件，string->char*
  {
    flag = true;
    qDebug() << "原文件删除成功";
  } else {
    qDebug() << "原文件删除失败";
    return flag;
  }

  std::fstream NewFile("flightTemp.dat",std::ios::out); //写入
  std::fstream File("flight.dat",std::ios::in); //读取
  string buf;
  if (File.is_open() && NewFile.is_open()) {
    while (true) {
      if (!(getline(File, buf))) //未到末尾
        break;
      if (buf == FNumber) {
        int n = 9; // 9行数据为一组
        while (n--)
          getline(File, buf);
      }
      NewFile << buf << endl;
    }
  }
  File.close();
  remove("flight.dat");
  NewFile.close();
  rename("flightTemp.dat", "flight.dat");
  return flag;
}

bool Flight::Set(Flight &F) {
  std::ifstream File(F.FNumber + ".dat",std::ios::in); //读
  string buf;
  bool flag; //更新是否晚点
  if (File && File.peek() != EOF) {
    int n = 4;
    while (n--)
      getline(File, buf); //跳过前4行数据，读取第5行PDT
  }
  if (buf > F.PlanDepartureTime)
    F.Late = 1;
  File.close();
  return (Delete(F.FNumber) && Add(F));
}

Flight *Flight::Find(string FNumber) {
  std::ifstream File(FNumber + ".dat", std::ios::in); //只读
  Flight *FP = new Flight;
  string str;
  if (File) {
    qDebug() << "查找打开成功";
    getline(File, str);
    FP->FNumber = str;
    getline(File, str);
    FP->Airways = str;
    getline(File, str);
    FP->StartPoint = str;
    getline(File, str);
    FP->EndPoint = str;
    getline(File, str);
    FP->PlanDepartureTime = str;
    getline(File, str);
    FP->PlanArrivalTime = str;
    getline(File, str);
    FP->Price = std::stoi(str);
    getline(File, str);
    FP->RemainTickit = std::stoi(str);
    getline(File, str);
    FP->Late = std::stoi(str);
    File.close();
  } else
    FP = nullptr;
  return FP;
}
Flight::~Flight() { ; }
