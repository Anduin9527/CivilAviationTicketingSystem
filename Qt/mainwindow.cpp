#include "mainwindow.h"
#include "Flight.h"
#include "Sort.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

typedef struct Date{
  int year;
  int month;
  int day;
  int hour;
  int minute;
}Date;

bool isLeapYear_(int year){
  if((year%4==0&&year%100>0)||year%400==0){
    return true;
  }else{
    return false;
  }
}
int daysInMonth_(int year,int month){
  if(isLeapYear_(year)){
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
      return 31;
    }
    if(month==4||month==6||month==9||month==11){
      return 30;
    }
    if(month==2){
      return 29;
    }

  }else{
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
      return 31;
    }
    if(month==4||month==6||month==9||month==11){
      return 30;
    }
    if(month==2){
      return 28;
    }
  }
}
int daysInYear_(int year, int month ,int day){
  int totalDays=0;
  for(int i=1;i<month;i++){
    totalDays+=daysInMonth_(year,i);
  }
  totalDays+=day;
  return totalDays;
}
int minutesInYear_(int year, int month ,int day,int hour,int minute){
  return 1440*daysInYear_(year , month , day)+60*hour+minute;
}
int minuteDifference_(Date d1,Date d2){

  if(isLeapYear_(d1.year)){
    return 366*24*60*(d2.year-d1.year)+minutesInYear_(d2.year,d2.month,d2.day,d2.hour,d2.minute)-minutesInYear_(d1.year,d1.month,d1.day,d1.hour,d1.minute);
  }else{
    return 365*24*60*(d2.year-d1.year)+minutesInYear_(d2.year,d2.month,d2.day,d2.hour,d2.minute)-minutesInYear_(d1.year,d1.month,d1.day,d1.hour,d1.minute);
  }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->labelPAT->setVisible(false);
  ui->labelPDT->setVisible(false);
  ui->labelPAT->setStyleSheet("color:red;");
  ui->labelPDT->setStyleSheet("color:red;");


  // Add
  connect(ui->btnAdd, &QPushButton::clicked, [=] {
    if (!ui->editFNumber->text().isEmpty() &&
        !ui->editAirways->text().isEmpty() &&
        !ui->editStartPoint->text().isEmpty() &&
        !ui->editFNumber->text().isEmpty() &&
        !ui->editPlanDepartureTime->text().isEmpty() &&
        !ui->editPlanArrivalTime->text().isEmpty() &&
        !ui->editPrice->text().isEmpty() &&
        !ui->editRemainTickit->text().isEmpty()) { //判断输入框是否为空
      Flight F;
      F.FNumber = ui->editFNumber->text().toStdString(); // Qstring->std::string
      F.Airways = ui->editAirways->text().toStdString();
      F.StartPoint = ui->editStartPoint->text().toStdString();
      F.EndPoint = ui->editEndPoint->text().toStdString();
      F.PlanDepartureTime = ui->editPlanDepartureTime->text().toStdString();
      F.PlanArrivalTime = ui->editPlanArrivalTime->text().toStdString();
      F.Price = ui->editPrice->text().toInt();
      F.RemainTickit = ui->editRemainTickit->text().toInt();
      if (F.Add(F)) {
        QMessageBox::information(this, "成功", "添加航班信息成功!");
      } else
        QMessageBox::information(this, "失败！",
                                 "请检查航班号是否已经被添加过!");
    } else
      QMessageBox::information(this, "错误！", "请检查数据是否完整");
  });
  // Set
  connect(ui->btnSet, &QPushButton::clicked, [=] {
    if (!ui->editFNumber->text().isEmpty() &&
        !ui->editAirways->text().isEmpty() &&
        !ui->editStartPoint->text().isEmpty() &&
        !ui->editFNumber->text().isEmpty() &&
        !ui->editPlanDepartureTime->text().isEmpty() &&
        !ui->editPlanArrivalTime->text().isEmpty() &&
        !ui->editPrice->text().isEmpty() &&
        !ui->editRemainTickit->text().isEmpty()) {
      Flight F;
      F.FNumber = ui->editFNumber->text().toStdString(); // Qstring->std::string
      F.Airways = ui->editAirways->text().toStdString();
      F.StartPoint = ui->editStartPoint->text().toStdString();
      F.EndPoint = ui->editEndPoint->text().toStdString();
      F.PlanDepartureTime = ui->editPlanDepartureTime->text().toStdString();
      F.PlanArrivalTime = ui->editPlanArrivalTime->text().toStdString();
      F.Price = ui->editPrice->text().toInt();
      F.RemainTickit = ui->editRemainTickit->text().toInt();
      if (F.Set(F)) {
        QMessageBox::information(this, "成功", "更新航班信息成功!");
        if (F.Late) {
          ui->labelPAT->setVisible(true);
          ui->labelPDT->setVisible(true);
        } else {
          ui->labelPAT->setVisible(false);
          ui->labelPDT->setVisible(false);
        }
      } else
        QMessageBox::information(this, "失败", "请检查航班号是否已录入系统");
    } else
      QMessageBox::information(this, "错误！", "请检查数据是否完整");
  });
  // Delete
  connect(ui->btnDel, &QPushButton::clicked, [=] {
    if (!ui->editFNumber->text().isEmpty()) {
      Flight F;
      F.FNumber = ui->editFNumber->text().toStdString();
      if (F.Delete(F.FNumber))
        QMessageBox::information(this, "成功", "删除航班信息成功!");
      else
        QMessageBox::information(this, "失败",
                                 "请检查该航班号是否已录入系统！");
    } else
      QMessageBox::information(this, "错误！", "请检查数据是否完整");
  });
  // Find
  connect(ui->btnFind, &QPushButton::clicked, [=] {
    Flight *FP;
    FP = FP->Find(ui->editFNumber->text().toStdString());
    if (FP != nullptr) {
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
      QMessageBox::information(this, "成功", "查询成功!");
      FP->isLate(*FP);
      if (FP->Late) {
        ui->labelPAT->setVisible(true);
        ui->labelPDT->setVisible(true);
      } else {
        ui->labelPAT->setVisible(false);
        ui->labelPDT->setVisible(false);
      }
    } else
      QMessageBox::information(this, "失败",
                               "查询失败，请检查航班号是否已录入系统");
    delete FP;
  });
  connect(ui->editPlanDepartureTime, &QLineEdit::editingFinished, [=] {
    ui->btnAdd->setEnabled(true);
    ui->tip->setText("");
    QString curQstr = ui->editPlanDepartureTime->text();
    int year = curQstr.section("-", 0, 0).toInt();
    int month = curQstr.section("-", 1, 1).toInt();
    int day = curQstr.section("-", 2, 2).toInt();
    int hour = curQstr.section("-", 3, 3).toInt();
    int minute = curQstr.section("-", 4, 4).toInt();
    int maxLen = 16;
    int curLen = ui->editPlanDepartureTime->text().count();
    if (curLen > maxLen) {
      ui->editPlanDepartureTime->setText(curQstr.left(maxLen));
    }
    if (curLen < maxLen || curQstr.isEmpty()) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if (year < 0) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if (month < 1 || month > 12) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
         month == 10 || month == 12) &&
        (day < 1 || day > 31)) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if ((month == 4 || month == 5 || month == 6 || month == 9 || month == 11) &&
        (day < 1 || day > 30)) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if ((year % 4 == 0 && year % 100 > 0) || year % 400 == 0) {
      if (month == 2 && day > 29) {
        ui->btnAdd->setEnabled(false);
        ui->tip->setText("时间填写错误");
      }
    } else {
      if (month == 2 && day > 28) {
        ui->btnAdd->setEnabled(false);
        ui->tip->setText("时间填写错误");
      }
    }
    if (hour < 0 || hour > 23) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if (minute < 0 || minute > 59) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    QString arrivalQstr = ui->editPlanArrivalTime->text();
    int year_ = arrivalQstr.section("-", 0, 0).toInt();
    int month_ = arrivalQstr.section("-", 1, 1).toInt();
    int day_ = arrivalQstr.section("-", 2, 2).toInt();
    int hour_ = arrivalQstr.section("-", 3, 3).toInt();
    int minute_ = arrivalQstr.section("-", 4, 4).toInt();
    Date time={year,month,day,hour,minute};
    Date time_={year_,month_,day_,hour_,minute_};
    int deltetime=minuteDifference_(time,time_);
    if(deltetime<1){
        ui->btnAdd->setEnabled(false);
        ui->tip->setText("时间填写错误");
    }

  });
  connect(ui->editPlanArrivalTime, &QLineEdit::editingFinished, [=] {
    ui->btnAdd->setEnabled(true);
    ui->tip->setText("");
    QString curQstr = ui->editPlanArrivalTime->text();
    int year = curQstr.section("-", 0, 0).toInt();
    int month = curQstr.section("-", 1, 1).toInt();
    int day = curQstr.section("-", 2, 2).toInt();
    int hour = curQstr.section("-", 3, 3).toInt();
    int minute = curQstr.section("-", 4, 4).toInt();
    int maxLen = 16;
    int curLen = ui->editPlanArrivalTime->text().count();
    if (curLen > maxLen) {
      ui->editPlanArrivalTime->setText(curQstr.left(maxLen));
    }
    if (curLen < maxLen || curQstr.isEmpty()) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if (year < 0) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if (month < 1 || month > 12) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
         month == 10 || month == 12) &&
        (day < 1 || day > 31)) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if ((month == 4 || month == 5 || month == 6 || month == 9 || month == 11) &&
        (day < 1 || day > 30)) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if ((year % 4 == 0 && year % 100 > 0) || year % 400 == 0) {
      if (month == 2 && day > 29) {
        ui->btnAdd->setEnabled(false);
        ui->tip->setText("时间填写错误");
      }
    } else {
      if (month == 2 && day > 28) {
        ui->btnAdd->setEnabled(false);
        ui->tip->setText("时间填写错误");
      }
    }
    if (hour < 0 || hour > 23) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    if (minute < 0 || minute > 59) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("时间填写错误");
    }
    QString departureQstr = ui->editPlanDepartureTime->text();
    int _year = departureQstr.section("-", 0, 0).toInt();
    int _month = departureQstr.section("-", 1, 1).toInt();
    int _day = departureQstr.section("-", 2, 2).toInt();
    int _hour = departureQstr.section("-", 3, 3).toInt();
    int _minute = departureQstr.section("-", 4, 4).toInt();
    Date time={year,month,day,hour,minute};
    Date _time={_year,_month,_day,_hour,_minute};
    int deltetime=minuteDifference_(_time,time);
    if(deltetime<1){
        ui->btnAdd->setEnabled(false);
        ui->tip->setText("时间填写错误");
    }

  });
  // Sort
  connect(ui->btnSort, &QPushButton::clicked, [=] {
    Sort();
    QMessageBox::information(this, "成功", "排序成功!");
  });
}
MainWindow::~MainWindow() { delete ui; }
