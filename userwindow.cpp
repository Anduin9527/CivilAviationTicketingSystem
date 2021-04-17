#include "userwindow.h"
#include "Crasa.h"
#include "Flight.h"
#include "Minutediff.h"
#include "User.h"
#include "table.h"
#include "ui_mainwindow.h"
#include "ui_userwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QRegion>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QString>
#include <QValidator>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
UserWindow::UserWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::UserWindow) {
  ui->setupUi(this);
  //初始化晚点label
  ui->labelPAT->setVisible(false);
  ui->labelPDT->setVisible(false);
  ui->labelPAT->setStyleSheet("color:red;");
  ui->labelPDT->setStyleSheet("color:red;");

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

  connect(ui->btnRegist, &QPushButton::clicked, [=] {
    string ID = ui->editName->text().toStdString();
    string password = ui->editPasswd->text().toStdString();
    bool fID = true, fpasswd = true, fpasswdn = false, fpasswda = false;
    for (auto i : ID)
      if (!isdigit(i) && i != 'X' && i != 'x')
        fID = false;
    for (auto i : password) {
      if (!isalnum(i))
        fpasswd = false;
      if (isdigit(i))
        fpasswdn = true;
      else if (isalpha(i))
        fpasswda = true;
    }
    if (ID.length() != 18)
      fID = false;
    if (password.length() <= 6)
      fpasswd = false;
    if (!fID || !fpasswd || !fpasswda || !fpasswdn) {
      QMessageBox::information(this, "错误", "请检查身份证格式和密码格式");
      ui->tip->setText(
          "账户为18位的身份证号码,密码必须有且只能有数字和字母的混合且大于6位");
      return;
    } else {
      {
        if (!isRegist(Encode(ID))) //如果没有注册过
        {
          //      Encode(ID, password);
          addUser(Encode(ID), Encode(password));
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
        } else
          QMessageBox::information(this, "错误", "您已经注册过了，请登录");
      }
    }
  });
  connect(ui->btnBook, &QPushButton::clicked, [=] {
    string flNum = ui->editFNumber->text().toStdString();
    string ID = ui->editName->text().toStdString();
    Flight *FP = FP->Find(flNum);
    if (FP == nullptr) {
      ui->tip->setText("无法查询到此航班！");
    } else {
      //获取数据库中计划时间
      int planYear = QString::fromStdString(FP->PlanDepartureTime)
                         .section("-", 0, 0)//section(分割符，起始项，终止项)
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
      if (FP->RemainTickit > 0) {
        if (delteMinute > 240) {
          string status = setUser(Encode(ID), flNum, 1);
          if (!(status == "nocredit")) {
            if (status == "OK") {
              FP->RemainTickit--;
              FP->Delete(flNum);
              FP->Add(*FP);
              ui->editRemainTickit->setText(QString::fromStdString(std::to_string(FP->RemainTickit)));
              ui->tip->setText(QString::fromStdString(
                  "尊敬的乘客，您成功预订" + FP->FNumber +
                  "号航班，请记得提前一小时取票"));
            }
            if (status == "otherAirway") {
              ui->tip->setText(QString::fromStdString(
                  "尊敬的乘客，您已预订过其他航班，无法再预订机票"));
            }
            if (status == "toomany") {
              ui->tip->setText(QString::fromStdString(
                  "尊敬的乘客，您已预订过两张机票，无法再预订！"));
            }
          } else {
            ui->tip->setText(
                QString::fromStdString("您的信誉分过低，无法订票"));
          }
        } else {
          ui->tip->setText(
              QString::fromStdString("尊敬的乘客，" + FP->FNumber +"号航班距起飞不到4小时，请更换预定"));
        }
      } else {
        ui->tip->setText(QString::fromStdString("余票不足！"));
      }
    }
    delete FP;
  });

  connect(ui->btnRefund, &QPushButton::clicked, [=] {
    string flNum = ui->editFNumber->text().toStdString();
    string ID = ui->editName->text().toStdString();
    Flight *FP = FP->Find(flNum);
    if (FP == nullptr) {
      ui->tip->setText("您未预订此航班！");
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

      if (delteMinute > 30) {
        string status = setUser(Encode(ID), flNum, -1);
        if (status == "noticket") {
          ui->tip->setText("退票失败，您未预订此航班！");
        }
        if(status=="OK"){
            FP->RemainTickit++;
            FP->Delete(flNum);
            FP->Add(*FP);
            ui->editRemainTickit->setText(QString::fromStdString(std::to_string(FP->RemainTickit)));
            ui->tip->setText("退票成功！");
        }
      } else {
        ui->tip->setText(QString::fromStdString(
            "退票失败，" + FP->FNumber +
            "号航班已起飞或距离起飞不到30分钟，无法退票！"));
      }
    }
    delete FP;
  });
  connect(ui->btnTake, &QPushButton::clicked, [=] {
    string flNum = ui->editFNumber->text().toStdString();
    string ID = ui->editName->text().toStdString();
    Flight *FP = FP->Find(flNum);
    if (FP == nullptr) {
      ui->tip->setText("您未预订此航班！");
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
      if (delteMinute > 60) {
        string status= takeUser(Encode(ID), flNum, false);
        if(status=="OK") ui->tip->setText("take ticket successly !");
        if(status=="noticket") ui->tip->setText("取票失败，您未预订此航班！！");
      } else {
        string status=takeUser(Encode(ID), flNum, true);
        if(status=="OK") ui->tip->setText("取票成功，但是您逾期了！");
        if(status=="noticket") ui->tip->setText("取票失败，您未预订此航班！！");
      }
    }

    delete FP;
  });

  connect(ui->btnLogin, &QPushButton::clicked, [=] {
    string ID = ui->editName->text().toStdString();
    string password = ui->editPasswd->text().toStdString();
    string str;
//    qDebug() << QString::fromStdString(ID);
//    qDebug() << QString::fromStdString(password);
    if (isRegist(Encode(ID))) {
      ifstream File("Account.dat", std::ios::in);
      if (File.is_open()) {
        while (true) {
          if (!(getline(File, str))) //未到末尾
            break;
          if (str == Encode(ID)) {
            getline(File, str);
            break;
          }
        }
      }
      File.close();
      if (Decode(str) == password) {
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
  connect(ui->btnFindMore, &QPushButton::clicked, [=] {
    Table *T = new Table(this);
    T->show();
  });
}
UserWindow::~UserWindow() { delete ui; }
