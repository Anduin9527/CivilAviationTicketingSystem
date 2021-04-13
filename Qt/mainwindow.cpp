#include "mainwindow.h"
#include "Flight.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <ctime>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // Add
  connect(ui->btnAdd, &QPushButton::clicked, [=] {
    Flight F;
    Date d1, d2;
    F.FNumber = ui->editFNumber->text().toStdString(); // Qstring->std::string
    F.Airways = ui->ediAirways->text().toStdString();
    F.StartPoint = ui->editStartPoint->text().toStdString();
    F.EndPoint = ui->editEndPoint->text().toStdString();
    //在这里插入getDate的代码
    //在这里插入getDate的代码
    F.Price = ui->editPrice->text().toInt();
    F.RemainTickit = ui->editRemainTickit->text().toInt();
    F.Add(F);
  });
  //
  connect(ui->btnSet, &QPushButton::clicked, [=] {
    Flight F;
    Date d1, d2;
    F.FNumber = ui->editFNumber->text().toStdString(); // Qstring->std::string
    F.Airways = ui->ediAirways->text().toStdString();
    F.StartPoint = ui->editStartPoint->text().toStdString();
    F.EndPoint = ui->editEndPoint->text().toStdString();
    //在这里插入getDate的代码
    //在这里插入getDate的代码
    F.Price = ui->editPrice->text().toInt();
    F.RemainTickit = ui->editRemainTickit->text().toInt();
    //F.Set(F);
  });
  connect(ui->btnDel, &QPushButton::clicked, [=] {
    Flight F;
    F.FNumber = ui->editFNumber->text().toStdString();
    F.Delete(F.FNumber);
  });
}
MainWindow::~MainWindow() { delete ui; }
