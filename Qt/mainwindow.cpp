#include "mainwindow.h"
#include "Flight.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <ctime>
#include <iostream>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // Add
  connect(ui->btnAdd, &QPushButton::clicked, [=] {
    Flight F;
    F.FNumber = ui->editFNumber->text().toStdString(); // Qstring->std::string
    F.Airways = ui->editAirways->text().toStdString();
    F.StartPoint = ui->editStartPoint->text().toStdString();
    F.EndPoint = ui->editEndPoint->text().toStdString();
//    F.PlanDepartureTime = ui->editPlanDepartureTime->text().toStdString();
//    F.PlanArrivalTime = ui->editPlanArrivalTime->text().toStdString();
    F.Price = ui->editPrice->text().toInt();
    F.RemainTickit = ui->editRemainTickit->text().toInt();
    F.Add(F);
  });
  // Set
  connect(ui->btnSet, &QPushButton::clicked, [=] {
    Flight F;
    Date d1, d2;
    F.FNumber = ui->editFNumber->text().toStdString(); // Qstring->std::string
    F.Airways = ui->editAirways->text().toStdString();
    F.StartPoint = ui->editStartPoint->text().toStdString();
    F.EndPoint = ui->editEndPoint->text().toStdString();
//    F.PlanDepartureTime = ui->editPlanDepartureTime->text().toStdString();
//    F.PlanArrivalTime = ui->editPlanArrivalTime->text().toStdString();
    F.Price = ui->editPrice->text().toInt();
    F.RemainTickit = ui->editRemainTickit->text().toInt();
    F.Set(F);
  });
  // Delete
  connect(ui->btnDel, &QPushButton::clicked, [=] {
    Flight F;
    F.FNumber = ui->editFNumber->text().toStdString();
    F.Delete(F.FNumber);
  });
  // Find
  connect(ui->btnFind, &QPushButton::clicked, [=] {
    Flight *FP;
    FP = FP->Find(ui->editFNumber->text().toStdString());
    ui->editAirways->setText(QString::fromStdString(FP->Airways));
    ui->editStartPoint->setText(QString::fromStdString(FP->StartPoint));
    ui->editEndPoint->setText(QString::fromStdString(FP->EndPoint));
//    ui->editPlanDepartureTime->setText(QString::fromStdString(FP->PlanDepartureTime));
//    ui->editPlanArrivalTime->setText(QString::fromStdString(FP->PlanArrivalTime));
    ui->editPrice->setText(QString::fromStdString(std::to_string(FP->Price)));
    ui->editRemainTickit->setText(QString::fromStdString(std::to_string(FP->RemainTickit)));
    delete FP;
  });
}
MainWindow::~MainWindow() { delete ui; }
