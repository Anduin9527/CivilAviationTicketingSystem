#include "mainwindow.h"
#include "Flight.h"
#include "Sort.h"
#include "table.h"
#include "Minutediff.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QValidator>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->labelPAT->setVisible(false);
  ui->labelPDT->setVisible(false);
  ui->labelPAT->setStyleSheet("color:red;");
  ui->labelPDT->setStyleSheet("color:red;");
  ui->editPrice->setValidator(new QIntValidator(this));
  ui->editRemainTickit->setValidator(new QIntValidator(this));
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
  connect(ui->editPlanDepartureTime, &QLineEdit::textChanged, [=] {
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
      ui->tip->setText("注意填写正确的时间");
    }
    if (year < 0) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    if (month < 1 || month > 12) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
         month == 10 || month == 12) &&
        (day < 1 || day > 31)) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    if ((month == 4 || month == 5 || month == 6 || month == 9 || month == 11) &&
        (day < 1 || day > 30)) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    if ((year % 4 == 0 && year % 100 > 0) || year % 400 == 0) {
      if (month == 2 && day > 29) {
        ui->btnAdd->setEnabled(false);
        ui->tip->setText("注意填写正确的时间");
      }
    } else {
      if (month == 2 && day > 28) {
        ui->btnAdd->setEnabled(false);
        ui->tip->setText("注意填写正确的时间");
      }
    }
    if (hour < 0 || hour > 23) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    if (minute < 0 || minute > 59) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    QString arrivalQstr = ui->editPlanArrivalTime->text();
    int year_ = arrivalQstr.section("-", 0, 0).toInt();
    int month_ = arrivalQstr.section("-", 1, 1).toInt();
    int day_ = arrivalQstr.section("-", 2, 2).toInt();
    int hour_ = arrivalQstr.section("-", 3, 3).toInt();
    int minute_ = arrivalQstr.section("-", 4, 4).toInt();
    Date time = {year, month, day, hour, minute};
    Date time_ = {year_, month_, day_, hour_, minute_};
    int deltetime = minuteDifference(time, time_);
    if (deltetime < 1) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
  });
  connect(ui->editPlanArrivalTime, &QLineEdit::textChanged, [=] {
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
      ui->tip->setText("注意填写正确的时间");
    }
    if (year < 0) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    if (month < 1 || month > 12) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
         month == 10 || month == 12) &&
        (day < 1 || day > 31)) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    if ((month == 4 || month == 5 || month == 6 || month == 9 || month == 11) &&
        (day < 1 || day > 30)) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    if ((year % 4 == 0 && year % 100 > 0) || year % 400 == 0) {
      if (month == 2 && day > 29) {
        ui->btnAdd->setEnabled(false);
        ui->tip->setText("注意填写正确的时间");
      }
    } else {
      if (month == 2 && day > 28) {
        ui->btnAdd->setEnabled(false);
        ui->tip->setText("注意填写正确的时间");
      }
    }
    if (hour < 0 || hour > 23) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    if (minute < 0 || minute > 59) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
    QString departureQstr = ui->editPlanDepartureTime->text();
    int _year = departureQstr.section("-", 0, 0).toInt();
    int _month = departureQstr.section("-", 1, 1).toInt();
    int _day = departureQstr.section("-", 2, 2).toInt();
    int _hour = departureQstr.section("-", 3, 3).toInt();
    int _minute = departureQstr.section("-", 4, 4).toInt();
    Date time = {year, month, day, hour, minute};
    Date _time = {_year, _month, _day, _hour, _minute};
    int deltetime = minuteDifference(_time, time);
    if (deltetime < 1) {
      ui->btnAdd->setEnabled(false);
      ui->tip->setText("注意填写正确的时间");
    }
  });
  // Sort
  connect(ui->btnSort, &QPushButton::clicked, [=] {
    Sort();
    QMessageBox::information(this, "成功", "排序成功!");
  });
  // Find More
  connect(ui->btnFindMore, &QPushButton::clicked, [=] {
    Table *T = new Table(this);
    T->show();
  });
}
MainWindow::~MainWindow() { delete ui; }
