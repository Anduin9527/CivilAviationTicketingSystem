#include "userwindow.h"
#include "Crasa.h"
#include "Flight.h"
#include "User.h"
#include "Minutediff.h"
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
    : QMainWindow(parent), ui(new Ui::UserWindow)
{
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
    if (FP != nullptr)
    {
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
      if (FP->Late)
      {
        ui->labelPAT->setVisible(true);
        ui->labelPDT->setVisible(true);
      }
      else
      {
        ui->labelPAT->setVisible(false);
        ui->labelPDT->setVisible(false);
      }
    }
    else
      QMessageBox::information(this, "失败",
                               "查询失败，请检查航班号是否已录入系统");
    delete FP;
  });

  connect(ui->btnRegist, &QPushButton::clicked, [=] {
    string ID = ui->editName->text().toStdString();
    string password = ui->editPasswd->text().toStdString();
    bool fID = true, fpasswd = true;
    for (auto i : ID)
      if (!isdigit(i) && i != 'X' && i != 'x')
        fID = false;
    for (auto i : password)
      if (!isalnum(i))
        fpasswd = false;

    if (ID.length() != 18)
      fID = false;
    if (!fID || !fpasswd)
    {
      QMessageBox::information(this, "错误", "请检查身份证格式和密码格式");
      ui->tip->setText("账户为18位的身份证号码,密码不可以带符号或者空格");
      return;
    }
    else
    {
      if (!isRegist(ID)) //如果没有注册过
      {
        //      Encode(ID, password);
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
      }
      else
      {
        QMessageBox::information(this, "错误", "您已经注册过了，请登录");
      }
    });
  connect(ui->btnBook, &QPushButton::clicked, [=] {
    string flNum = ui->editFNumber->text().toStdString();
    Flight *FP = FP->Find(flNum);
    if (FP == nullptr)
    {
      ui->tip->setText("无法查询到此航班！");
    }
    else
    {
      //获取数据库中计划时间
      int planYear = QString::fromStdString(FP->PlanDepartureTime).section("-", 0, 0).toInt();
      int planMonth = QString::fromStdString(FP->PlanDepartureTime).section("-", 1, 1).toInt();
      int planDay = QString::fromStdString(FP->PlanDepartureTime).section("-", 2, 2).toInt();
      int planHour = QString::fromStdString(FP->PlanDepartureTime).section("-", 3, 3).toInt();
      int planMinute = QString::fromStdString(FP->PlanDepartureTime).section("-", 4, 4).toInt();
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
      //查看用户是否超购
      bool ifBook = true;
      string ID = ui->editName->text().toStdString();
      string fn = "Account.dat";
      string temp;
      string tempfile = "temp.dat";
      fstream read1(fn, ios::in);
      fstream write1(tempfile, ios::out);
      if (!read1)
        cout << "error" << endl;
      while (true)
      {
        if (!getline(read1, temp))
        {
          break;
        }
        if (!(temp == ID))
        {
          write1 << temp << endl;
        }
        else
        {
          break;
        }
      }
      write1 << temp << endl;
      getline(read1, temp);
      write1 << temp << endl;
      getline(read1, temp);

      if (temp.length() < 2)
      {
        write1 << temp + "#" << endl;
      }
      else
      {
        ui->tip->setText("您已经预订过两张票了！");
        write1 << "##" << endl;
        ifBook = false;
      }
      while (true)
      {
        if (!getline(read1, temp))
        {
          break;
        }
        else
        {
          write1 << temp << endl;
        }
      }
      read1.close();
      write1.close();

      fstream acc("Account.dat", ios::out);
      fstream tmp("temp.dat", ios::in);
      while (true)
      {
        if (!getline(tmp, temp))
        {
          break;
        }
        else
        {
          acc << temp << endl;
        }
      }
      acc.close();
      tmp.close();

      if (FP->RemainTickit > 0)
      {
        if (delteMinute > 240)
        {
          if (ifBook)
          {
            FP->RemainTickit--;
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
            FP->Set(*FP);
            ui->tip->setText(QString::fromStdString("尊敬的乘客，您已成功预订航班号为" + FP->FNumber + "的机票！"));
          }
          else
          {
            ui->tip->setText(QString::fromStdString("购票过多"));
            cout << "购票过多" << endl;
          }
        }
        else
        {
          ui->tip->setText(QString::fromStdString("尊敬的乘客，很抱歉，航班号为" + FP->FNumber + "的机票余量为0，请更换预定"));
        }
      }
      else
      {
        ui->tip->setText(QString::fromStdString("尊敬的乘客，" + FP->FNumber + "号航班距起飞不到4小时，请更换预定"));
      }
    }

    delete FP;
  });

  connect(ui->btnRefund, &QPushButton::clicked, [=] {
    string flNum = ui->editFNumber->text().toStdString();
    Flight *FP = FP->Find(flNum);
    if (FP == nullptr)
    {
      ui->tip->setText("您未预订此航班！");
    }
    else
    {
      //获取数据库中计划时间
      int planYear = QString::fromStdString(FP->PlanDepartureTime).section("-", 0, 0).toInt();
      int planMonth = QString::fromStdString(FP->PlanDepartureTime).section("-", 1, 1).toInt();
      int planDay = QString::fromStdString(FP->PlanDepartureTime).section("-", 2, 2).toInt();
      int planHour = QString::fromStdString(FP->PlanDepartureTime).section("-", 3, 3).toInt();
      int planMinute = QString::fromStdString(FP->PlanDepartureTime).section("-", 4, 4).toInt();
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
      //检查是否能退票
      bool ifRefond = true;
      string ID = ui->editName->text().toStdString();
      string fn = "Account.dat";
      string temp;
      string tempfile = "temp.dat";
      int line = 0;
      fstream find(fn, ios::in);
      if (!find)
      {
        cout << "error" << endl;
      }
      while (true)
      {
        if (!getline(find, temp))
        {
          break;
        }
        if (!(temp == ID))
        {
          line++;
          //cout<<"line="<<line<<endl;
        }
        else
        {
          break;
        }
      }
      find.close();
      fstream read2(fn, ios::in);
      fstream write2(tempfile, ios::out);
      for (int i = 0; i < line; i++)
      {
        getline(read2, temp);
        write2 << temp << endl;
      }
      getline(read2, temp);
      write2 << temp << endl;
      getline(read2, temp);
      write2 << temp << endl;
      getline(read2, temp);
      if (temp.length() == 1)
      {
        write2 << endl;
      }
      if (temp.length() >= 2)
      {
        write2 << "#" << endl;
      }
      if (temp.length() == 0)
      {
        ifRefond = false;
        //ui->tip->setText("尊敬的用户，您没有这次航班的机票");
      }

      while (true)
      {
        if (!getline(read2, temp))
        {
          break;
        }
        else
        {
          write2 << temp << endl;
        }
      }
      read2.close();
      write2.close();
      fstream acc("Account.dat", ios::out);
      fstream tmp("temp.dat", ios::in);
      while (true)
      {
        if (!getline(tmp, temp))
        {
          break;
        }
        else
        {
          acc << temp << endl;
        }
      }
      acc.close();
      tmp.close();

      //          if(FP->RemainTickit>0)
      //          {
      if (delteMinute > 30)
      {
        if (ifRefond)
        {
          FP->RemainTickit++;
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
          FP->Set(*FP);
          ui->tip->setText(QString::fromStdString("尊敬的乘客，您已成功退订航班号为" + FP->FNumber + "的机票！"));
        }
        else
        {
          ui->tip->setText(QString::fromStdString("亲，您没有预订本航班的机票！"));
        }
      }
      else
      {
        ui->tip->setText(QString::fromStdString("尊敬的乘客，" + FP->FNumber + "号航班已起飞或距离起飞不到30分钟，无法退票！"));
      }
    }
    //      }
    delete FP;
  });
  connect(ui->btnTake, &QPushButton::clicked, [=] {
    string flNum = ui->editFNumber->text().toStdString();
    Flight *FP = FP->Find(flNum);
    if (FP == nullptr)
    {
      ui->tip->setText("您未预订此航班！");
    }
    else
    {
    }

    delete FP;
  });

  connect(ui->btnLogin, &QPushButton::clicked, [=] {
    string ID = ui->editName->text().toStdString();
    string password = ui->editPasswd->text().toStdString();
    if (isRegist(ID))
    {
      if (Decode(ID) == password)
      {
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
      }
      else
        QMessageBox::information(this, "错误", "您的密码有误 请检查!");
    }
    else
      QMessageBox::information(this, "错误", "您尚未注册 请注册!");
  });
}

UserWindow::~UserWindow() { delete ui; }
