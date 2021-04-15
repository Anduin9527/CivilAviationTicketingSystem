#include "table.h"
#include "Sort.h"
#include "fstream"
#include "ui_table.h"
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QTableWidgetItem>
Table::Table(QWidget *parent) : QMainWindow(parent), ui(new Ui::Table) {
  ui->setupUi(this);
  ui->editDate->setEnabled(false); //日期默认禁用
  connect(ui->checkDate, &QCheckBox::stateChanged, [=] {
    if (ui->editDate->isEnabled())
      ui->editDate->setEnabled(false);
    else
      ui->editDate->setEnabled(true);
  }); //切换日期选中
  //初始化列表
  ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->table->setSortingEnabled(true);
  F f[1000]; //结构体数组
  int row = Sort();
  ui->table->setRowCount(row); //设置行数
  std::fstream File("Sort.dat", std::ios::in | std::ios::out);
  if (File.peek() == EOF) {
    File.close();
    QMessageBox::information(this, "失败", "请检查航班信息是否录入系统");
  } else {
    File.clear();
    string str;
    if (File.is_open()) {
      while (true) {
        if (!(getline(File, str))) //未到末尾
          break;
        else {
          if (str.empty())
            continue; //跳过空行
          for (int i = 0; i < row; i++)
            for (int j = 0; j < 9; j++) {
              ui->table->setItem(
                  i, j, new QTableWidgetItem(QString::fromStdString(str)));
              switch (j) {
              case 0:
                f[i].FNumber = str;
                break;
              case 1:
                f[i].Airways = str;
                break;
              case 2:
                f[i].StartPoint = str;
                break;
              case 3:
                f[i].EndPoint = str;
                break;
              case 4:
                f[i].PlanDepartureTime = str;
                break;
              case 5:
                f[i].PlanArrivalTime = str;
                break;
              case 6:
                f[i].Price = str;
                break;
              case 7:
                f[i].RemainTickit = str;
                break;
              case 8:
                f[i].Late = str;
                break;
              } //结构体数组初始化
              getline(File, str);
            }
        }
      }
    }
    File.close();
  }
  //列表查询
  connect(ui->btn, &QPushButton::clicked, [=] {
    string Airways = ui->editAirways->text().toStdString();
    string Start = ui->editStart->text().toStdString();
    string End = ui->editEnd->text().toStdString();
    // Date
    int nRow = ui->table->rowCount(); //获取行数
    if (ui->editDate->isEnabled()) {
      QList<QTableWidgetItem *> findItems =
          ui->table->findItems(ui->editDate->text(), Qt::MatchContains);
      bool bRowHidden = true;
      for (int i = 0; i < nRow; i++) {
        bRowHidden = true;
        foreach (QTableWidgetItem *item, findItems) {
          if (NULL == item)
            continue;
          if (ui->table->row(item) == i) {
            bRowHidden = false;
            break;
          }
        }
        ui->table->setRowHidden(i, bRowHidden);
      }
    }
    for (int i = 0; i < nRow && !ui->table->isRowHidden(i); i++) {
      if (f[i].Airways == Airways && f[i].StartPoint == Start &&
          f[i].EndPoint == End)
        ui->table->setRowHidden(i, false);
      else if (f[i].Airways == Airways && Start.empty() && End.empty())
        ui->table->setRowHidden(i, false);
      else if (Airways.empty() && f[i].StartPoint == Start && End.empty())
        ui->table->setRowHidden(i, false);
      else if (Airways.empty() && Start.empty() && f[i].EndPoint == End)
        ui->table->setRowHidden(i, false);
      else if (Airways.empty() && f[i].StartPoint == Start &&
               f[i].EndPoint == End)
        ui->table->setRowHidden(i, false);
      else if (f[i].Airways == Airways && Start.empty() && f[i].EndPoint == End)
        ui->table->setRowHidden(i, false);
      else if (f[i].Airways == Airways && f[i].StartPoint == Start &&
               End.empty())
        ui->table->setRowHidden(i, false);
      else if (Airways.empty() && Start.empty() && End.empty())
        ui->table->setRowHidden(i, false);
      else
        ui->table->setRowHidden(i, true);
    }
  });
}

Table::~Table() { delete ui; }
