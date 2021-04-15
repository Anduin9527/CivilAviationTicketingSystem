#include "table.h"
#include "Sort.h"
#include "fstream"
#include "ui_table.h"
#include <QMessageBox>
#include <QTableWidgetItem>
Table::Table(QWidget *parent) : QMainWindow(parent), ui(new Ui::Table) {
  ui->setupUi(this);
  ui->editDate->setEnabled(false); //日期默认禁用
  connect(ui->checkDate, &QCheckBox::stateChanged, [=] {
    if (ui->editDate->isEnabled())
      ui->editDate->setEnabled(false);
    else
      ui->editDate->setEnabled(true);
  });
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
              getline(File, str);
            }
        }
      }
    }
  }
}
Table::~Table() { delete ui; }
