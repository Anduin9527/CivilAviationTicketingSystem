#include "login.h"
#include "mainwindow.h"
#include "ui_login.h"
#include "userwindow.h"
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <iostream>
Login::Login(QWidget *parent) : QWidget(parent), ui(new Ui::Login) {
  ui->setupUi(this);
  this->resize(600, 400);
  connect(ui->btn_Admin, &QPushButton::clicked, [=] {
    QString name = ui->name->text();
    QString password = ui->password->text();
    // qDebug() << name << password;
    if (name == "admin" && password == "sast") {
      this->close();
      QMessageBox::information(
          this, "欢迎您!", "道路千万条，数据第一条，操作不规范，亲人两行泪");
      MainWindow *W = new MainWindow;
      W->show();
    } else
      QMessageBox::warning(this, "错误！",
                           "密码或用户名错误！旅客请直接使用旅客入口");
  });
  connect(ui->btn_User, &QPushButton::clicked, [=] {
    this->close();
    UserWindow *U = new UserWindow;
    QMessageBox::information(this, "欢迎您!", "亲爱的旅客，欢迎来到南邮航空！");
    U->show();
  });
}

Login::~Login() { delete ui; }
