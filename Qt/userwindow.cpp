#include "userwindow.h"
#include "Crasa.h"
#include "Flight.h"
#include "ui_mainwindow.h"
#include "ui_userwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <ctime>
#include <fstream>
#include <iostream>
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
    // Date写这里
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
}

UserWindow::~UserWindow() { delete ui; }
