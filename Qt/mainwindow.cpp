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
        F.isLate(F);
        if (F.Late) {
          ui->labelPAT->setVisible(true);
          ui->labelPDT->setVisible(true);
        } else {
          ui->labelPAT->setVisible(false);
          ui->labelPDT->setVisible(false);
        }
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
        F.isLate(F);
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
}
MainWindow::~MainWindow() { delete ui; }
