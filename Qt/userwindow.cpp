#include "userwindow.h"
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
    std::ofstream AddFile("Account.dat",
                          std::ios::out | std::ios::app); //写入+追加模式

  });
}

UserWindow::~UserWindow() { delete ui; }
