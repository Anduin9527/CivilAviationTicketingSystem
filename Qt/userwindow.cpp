#include "userwindow.h"
#include "Crasa.h"
#include "Flight.h"
#include "table.h"
#include "ui_mainwindow.h"
#include "ui_userwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <ctime>
#include <fstream>
#include <iostream>
typedef struct Date {
  int year;
  int month;
  int day;
  int hour;
  int minute;
} Date;

bool isLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 > 0) || year % 400 == 0) {
    return true;
  } else {
    return false;
  }
}
int daysInMonth(int year, int month) {
  if (isLeapYear(year)) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
        month == 10 || month == 12) {
      return 31;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
      return 30;
    }
    if (month == 2) {
      return 29;
    }

  } else {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
        month == 10 || month == 12) {
      return 31;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
      return 30;
    }
    if (month == 2) {
      return 28;
    }
  }
}
int daysInYear(int year, int month, int day) {
  int totalDays = 0;
  for (int i = 1; i < month; i++) {
    totalDays += daysInMonth(year, i);
  }
  totalDays += day;
  return totalDays;
}
int minutesInYear(int year, int month, int day, int hour, int minute) {
  return 1440 * daysInYear(year, month, day) + 60 * hour + minute;
}
int minuteDifference(Date d1, Date d2) {

  if (isLeapYear(d1.year)) {
    return 366 * 24 * 60 * (d2.year - d1.year) +
           minutesInYear(d2.year, d2.month, d2.day, d2.hour, d2.minute) -
           minutesInYear(d1.year, d1.month, d1.day, d1.hour, d1.minute);
  } else {
    return 365 * 24 * 60 * (d2.year - d1.year) +
           minutesInYear(d2.year, d2.month, d2.day, d2.hour, d2.minute) -
           minutesInYear(d1.year, d1.month, d1.day, d1.hour, d1.minute);
  }
}

UserWindow::UserWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::UserWindow) {
  ui->setupUi(this);
  // Find
  connect(ui->btnFind, &QPushButton::clicked, [=] {
    Flight *FP;
    FP = FP->Find(ui->editFNumber->text().toStdString());
    ui->editAirways->setText(QString::fromStdString(FP->Airways));
    ui->editStartPoint->setText(QString::fromStdString(FP->StartPoint));
    ui->editEndPoint->setText(QString::fromStdString(FP->EndPoint));
    ui->editPlanDepartureTime->setText(
        QString::fromStdString(FP->PlanDepartureTime));
    ui->editPlanArrivalTime->setText(
        QString::fromStdString(FP->PlanArrivalTime));
    ui->editPrice->setText(QString::fromStdString(std::to_string(FP->Price)));
    ui->editRemainTickit->setText(
        QString::fromStdString(std::to_string(FP->RemainTickit)));
    delete FP;
  });
  connect(ui->btnRegist, &QPushButton::clicked, [=] {
    string ID = ui->editName->text().toStdString();
    string password = ui->editPasswd->text().toStdString();
    if (!isRegist(ID)) //如果没有注册过
    {
      Encode(ID, password);
      QMessageBox::information(this, "成功", "您已经成功注册！");
      ui->groupLogin->hide();
      ui->textBrowser->setText(
          "预售票及退票功能"
          "当某航班有余票且距离起飞还有超过四小时的情况才可以预订票，"
          "起飞前半小时及起飞后的飞机不允许退票。"
          "每人每航班一次限预定两张，且不可预订其他航班。"
          "在航班起飞前一个小时如果未及时取票次数达两侧则视为无信誉客户"
          "取消今后的预订资格");
      ui->btnBook->setEnabled(true);
      ui->btnFind->setEnabled(true);
      ui->btnTake->setEnabled(true);
      ui->btnRefund->setEnabled(true);
    } else {
      QMessageBox::information(this, "错误", "您已经注册过了，请登录");
    }
  });
  connect(ui->btnBook, &QPushButton::clicked, [=] {
    string flNum = ui->editFNumber->text().toStdString();
    Flight *FP = FP->Find(flNum);
    if (FP == nullptr) {
      ui->tip->setText("无法查询到此航班！");
    } else {
      //获取数据库中计划时间
      int planYear = QString::fromStdString(FP->PlanDepartureTime)
                         .section("-", 0, 0)
                         .toInt();
      int planMonth = QString::fromStdString(FP->PlanDepartureTime)
                          .section("-", 1, 1)
                          .toInt();
      int planDay = QString::fromStdString(FP->PlanDepartureTime)
                        .section("-", 2, 2)
                        .toInt();
      int planHour = QString::fromStdString(FP->PlanDepartureTime)
                         .section("-", 3, 3)
                         .toInt();
      int planMinute = QString::fromStdString(FP->PlanDepartureTime)
                           .section("-", 4, 4)
                           .toInt();
      //获取本地时间
      time_t nowtime;
      struct tm *p;
      ;
      time(&nowtime);
      p = localtime(&nowtime);
      int curYear = p->tm_year + 1900;
      int curMonth = p->tm_mon + 1;
      int curDay = p->tm_mday;
      int curHour = p->tm_hour;
      int curMinute = p->tm_min;
      //将两个时间赋值给Date结构体，随后计算时差
      Date planTime = {planYear, planMonth, planDay, planHour, planMinute};
      Date curTime = {curYear, curMonth, curDay, curHour, curMinute};
      int delteMinute = minuteDifference(curTime, planTime);
      if (FP->RemainTickit > 0 && delteMinute > 240) {
        FP->RemainTickit--;
        ui->editAirways->setText(QString::fromStdString(FP->Airways));
        ui->editStartPoint->setText(QString::fromStdString(FP->StartPoint));
        ui->editEndPoint->setText(QString::fromStdString(FP->EndPoint));
        ui->editPlanDepartureTime->setText(
            QString::fromStdString(FP->PlanDepartureTime));
        ui->editPlanArrivalTime->setText(
            QString::fromStdString(FP->PlanArrivalTime));
        ui->editPrice->setText(
            QString::fromStdString(std::to_string(FP->Price)));
        ui->editRemainTickit->setText(
            QString::fromStdString(std::to_string(FP->RemainTickit)));
        FP->Set(*FP);
        ui->tip->setText(QString::fromStdString(
            "尊敬的乘客，您已成功预订航班号为" + FP->FNumber + "的机票！"));
      } else {
        ui->tip->setText(QString::fromStdString(
            "尊敬的乘客，很抱歉，航班号为" + FP->FNumber +
            "的机票余量为0或距起飞不到4小时，请更换预定"));
      }
    }

    delete FP;
  });

  connect(ui->btnRefund, &QPushButton::clicked, [=] {
    string flNum = ui->editFNumber->text().toStdString();
    Flight *FP = FP->Find(flNum);
    if (FP == nullptr) {
      ui->tip->setText("无法查询到此航班！");
    } else {
      //获取数据库中计划时间
      int planYear = QString::fromStdString(FP->PlanDepartureTime)
                         .section("-", 0, 0)
                         .toInt();
      int planMonth = QString::fromStdString(FP->PlanDepartureTime)
                          .section("-", 1, 1)
                          .toInt();
      int planDay = QString::fromStdString(FP->PlanDepartureTime)
                        .section("-", 2, 2)
                        .toInt();
      int planHour = QString::fromStdString(FP->PlanDepartureTime)
                         .section("-", 3, 3)
                         .toInt();
      int planMinute = QString::fromStdString(FP->PlanDepartureTime)
                           .section("-", 4, 4)
                           .toInt();
      //获取本地时间
      time_t nowtime;
      struct tm *p;
      time(&nowtime);
      p = localtime(&nowtime);
      int curYear = p->tm_year + 1900;
      int curMonth = p->tm_mon + 1;
      int curDay = p->tm_mday;
      int curHour = p->tm_hour;
      int curMinute = p->tm_min;
      //将两个时间赋值给Date结构体，随后计算时差
      Date planTime = {planYear, planMonth, planDay, planHour, planMinute};
      Date curTime = {curYear, curMonth, curDay, curHour, curMinute};
      int delteMinute = minuteDifference(curTime, planTime);

      if (FP->RemainTickit > 0 && delteMinute > 30) {
        FP->RemainTickit--;
        ui->editAirways->setText(QString::fromStdString(FP->Airways));
        ui->editStartPoint->setText(QString::fromStdString(FP->StartPoint));
        ui->editEndPoint->setText(QString::fromStdString(FP->EndPoint));
        ui->editPlanDepartureTime->setText(
            QString::fromStdString(FP->PlanDepartureTime));
        ui->editPlanArrivalTime->setText(
            QString::fromStdString(FP->PlanArrivalTime));
        ui->editPrice->setText(
            QString::fromStdString(std::to_string(FP->Price)));
        ui->editRemainTickit->setText(
            QString::fromStdString(std::to_string(FP->RemainTickit)));
        FP->Set(*FP);
        ui->tip->setText(QString::fromStdString(
            "尊敬的乘客，您已成功退订航班号为" + FP->FNumber + "的机票！"));
      } else {
        ui->tip->setText(
            QString::fromStdString("尊敬的乘客，航班号为" + FP->FNumber +
                                   "的机票距离起飞不到30分钟，无法退票！"));
      }
    }

    delete FP;
  });

  connect(ui->btnLogin, &QPushButton::clicked, [=] {
    string ID = ui->editName->text().toStdString();
    string password = ui->editPasswd->text().toStdString();
    if (isRegist(ID)) {
      if (Decode(ID) == password) {
        QMessageBox::information(this, "成功", "您已经成功登录！");
        ui->groupLogin->hide();
        ui->textBrowser->setText(
            "预售票及退票功能"
            "当某航班有余票且距离起飞还有超过四小时的情况才可以预订票，"
            "起飞前半小时及起飞后的飞机不允许退票。"
            "每人每航班一次限预定两张，且不可预订其他航班。"
            "在航班起飞前一个小时如果未及时取票次数达两侧则视为无信誉客户"
            "取消今后的预订资格");
        ui->btnBook->setEnabled(true);
        ui->btnFind->setEnabled(true);
        ui->btnTake->setEnabled(true);
        ui->btnRefund->setEnabled(true);
      } else
        QMessageBox::information(this, "错误", "您的密码有误 请检查!");
    } else
      QMessageBox::information(this, "错误", "您尚未注册 请注册!");
  });

  //  connect(ui->editPlanDepartureTime, &QLineEdit::editingFinished,[=]{
  //      ui->btnFind->setEnabled(true);
  //      ui->tip->setText("");
  //      QString curQstr=ui->editPlanDepartureTime->text();
  //      int year=curQstr.section("-",0,0).toInt();
  //      int month=curQstr.section("-",1,1).toInt();
  //      int day=curQstr.section("-",2,2).toInt();
  //      int hour=curQstr.section("-",3,3).toInt();
  //      int minute=curQstr.section("-",4,4).toInt();
  //      int maxLen=16;
  //      int curLen=ui->editPlanDepartureTime->text().count();
  //      if(curLen>maxLen){
  //          ui->editPlanDepartureTime->setText(curQstr.left(maxLen));
  //      }
  //      if(curLen<maxLen||curQstr.isEmpty()){
  //          //ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if (year < 0){
  //          //ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if (month < 1 || month > 12)
  //      {
  //       // ui->btnAdd->setEnabled(false);
  //        ui->tip->setText("时间填写错误");
  //       }
  //      if ((month == 1 || month == 3 || month == 5 || month == 7 || month ==
  //      8 ||
  //           month == 10 || month == 12) &&
  //          (day < 1 || day > 31)){
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if ((month == 4 || month == 5 || month == 6 || month == 9 || month ==
  //      11) &&
  //          (day < 1 || day > 30)){
  //         // ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if ((year % 4 == 0 && year % 100 > 0) || year % 400 == 0) {
  //        if (month == 2 && day > 29){
  //         //   ui->btnAdd->setEnabled(false);
  //            ui->tip->setText("时间填写错误");
  //        }
  //      } else {
  //        if (month == 2 && day > 28){
  //          //  ui->btnAdd->setEnabled(false);
  //            ui->tip->setText("时间填写错误");
  //        }
  //      }
  //      if(hour<0||hour>23){
  //         // ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if(minute<0||minute>59){
  //         // ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //  });
  //  connect(ui->editPlanArrivalTime, &QLineEdit::editingFinished,[=]{
  //     // ui->btnAdd->setEnabled(true);
  //      ui->tip->setText("");
  //      QString curQstr=ui->editPlanArrivalTime->text();
  //      int year=curQstr.section("-",0,0).toInt();
  //      int month=curQstr.section("-",1,1).toInt();
  //      int day=curQstr.section("-",2,2).toInt();
  //      int hour=curQstr.section("-",3,3).toInt();
  //      int minute=curQstr.section("-",4,4).toInt();
  //      int maxLen=16;
  //      int curLen=ui->editPlanArrivalTime->text().count();
  //      if(curLen>maxLen){
  //          ui->editPlanArrivalTime->setText(curQstr.left(maxLen));
  //      }
  //      if(curLen<maxLen||curQstr.isEmpty()){
  //         // ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if (year < 0){
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if (month < 1 || month > 12)
  //      {
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if ((month == 1 || month == 3 || month == 5 || month == 7 || month ==
  //      8 ||
  //           month == 10 || month == 12) &&
  //              (day < 1 || day > 31)){
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if ((month == 4 || month == 5 || month == 6 || month == 9 || month ==
  //      11) &&
  //              (day < 1 || day > 30)){
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if ((year % 4 == 0 && year % 100 > 0) || year % 400 == 0) {
  //          if (month == 2 && day > 29){
  //          //    ui->btnAdd->setEnabled(false);
  //              ui->tip->setText("时间填写错误");
  //          }
  //      } else {
  //          if (month == 2 && day > 28){
  //         //     ui->btnAdd->setEnabled(false);
  //              ui->tip->setText("时间填写错误");
  //          }
  //      }
  //      if(hour<0||hour>23){
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      if(minute<0||minute>59){
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //      QString abvQstr=ui->editPlanDepartureTime->text();
  //      int abvyear=curQstr.section("-",0,0).toInt();
  //      int abvmonth=curQstr.section("-",1,1).toInt();
  //      int abvday=curQstr.section("-",2,2).toInt();
  //      int abvhour=curQstr.section("-",3,3).toInt();
  //      int abvminute=curQstr.section("-",4,4).toInt();
  //      if(year<abvyear){
  //         // ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }else if(month<abvmonth){
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }else if(day<abvday){
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }else if(hour<abvhour){
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }else if(minute<abvminute){
  //        //  ui->btnAdd->setEnabled(false);
  //          ui->tip->setText("时间填写错误");
  //      }
  //  });
}

UserWindow::~UserWindow() { delete ui; }
