#include "login.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  Login L;
  L.show();
  return a.exec();
}
