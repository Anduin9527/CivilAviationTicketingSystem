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
}

MainWindow::~MainWindow() { delete ui; }
