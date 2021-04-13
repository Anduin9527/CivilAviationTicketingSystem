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

void Flight::Add(Flight &F) {
  std::ofstream AddFile(F.FNumber + ".dat",
                        std::ios::out | std::ios::app); //写入+追加模式

  if (AddFile)
    qDebug() << "打开成功!";
  AddFile << F.FNumber << endl;
  AddFile << F.Airways << endl;
  AddFile << F.StartPoint << endl;
  AddFile << F.EndPoint << endl;
  //在这里插入日期
  AddFile << F.Price << endl;
  AddFile << F.RemainTickit << endl;
  qDebug() << "写入！";
  AddFile.close();
  std::ofstream File("flight.dat",
                     std::ios::out | std::ios::app); //写入+追加模式
  if (File)
    qDebug() << "打开flight成功!";
  File << F.FNumber << endl;
  File << F.Airways << endl;
  File << F.StartPoint << endl;
  File << F.EndPoint << endl;
  //在这里插入日期
  File << F.Price << endl;
  File << F.RemainTickit << endl;
  File.close();
}
void Flight::Delete(string FNumber) {
  if (remove((FNumber + ".dat").c_str()) == 0) //删除原文件，string->char*
    qDebug() << "原文件删除成功";
  else
    qDebug() << "原文件删除失败";
  std::fstream NewFile("flightTemp.dat",
                       std::ios::out); //写入
  std::fstream File("flight.dat",
                    std::ios::in); //读取

  string buf;
  if (File.is_open() && NewFile.is_open()) {
    while (true) {
      if (!(getline(File, buf))) //未到末尾
        break;
      if (buf == FNumber) {
        int n = 6; //跳过六组数据 尚未包含Date
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
}

Flight::~Flight() { ; }
